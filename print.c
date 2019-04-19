#include "ft_printf.h"
#include "libft/libft.h"

unsigned long ft_print_c(va_list ag, t_pr *vals)
{
	unsigned long size;
	int i;
	int c;

	i = 0;
	size = 0;
	c = va_arg(ag, int);
	if (!vals->f_minus)
	{
		while (++i < vals->field)
			size += write(1, " ", 1);
		size += write(1, &c, 1);
	}
	else
	{
		size += write(1, &c, 1);
		while (++i < vals->field)
			size += write(1, " ", 1);
	}
	return (size);
}

unsigned long ft_print_str(va_list ag, t_pr *vals)
{
	char			*s;
	char			*tmp;
	int				i;
	unsigned long	size;

	i = 0;
	size = 0;
	tmp = va_arg(ag, char *);
	s = (tmp) ? ft_strdup(tmp) : ft_strdup("(null)");
	if ((vals->prec >= 0 && tmp) || (vals->prec >= 6 && !tmp))
		s[vals->prec] = (vals->prec < (int)ft_strlen(s)) ?\
						'\0' : s[vals->prec];
	i = (vals->prec < 6 && !tmp) ? vals->field : \
					vals->field - (int)ft_strlen(s);
	if (i  > 0 && !vals->f_minus)
		while(i--)
			size += write(1, " ", 1);
	tmp = (!tmp && (vals->prec < ft_strlen(s))) ? NULL : s;
	while (*s && tmp && s)
		size += write(1, s++, 1);
	if (vals->f_minus && i > 0)
		while(i--)
			size += write(1, " ", 1);
	((tmp) ? free(tmp) : free(s));
	return (size);
}


int		ft_print_handler(char *str, unsigned long size,  va_list args)
{
	t_pr	*vals;
	
	if (!*str || !str)
		return ((int)size);
	while (*str && *str != '%')
		size += (write(1, str++, 1));
	vals = init_val();
	if (*str == '%')
	{
		str = parse_val(&vals, str + 1);
		if (*str == 'c')
			size += ft_print_c(args, vals);
		else if (*str == 's')
			size += ft_print_str(args, vals);
		else if (*str == '%')
			size += write(1, "%", 1);
		str++;
	}
	free(vals);
	return (ft_print_handler(str, size, args));

}

int					ft_printf(const char *format, ...)
{
	char *traverse; 
	int size;

	va_list arg; 
	va_start(arg, format); 
	
	size = ft_print_handler((char *)format, 0, arg);	
	va_end(arg); 
	return ((int)size);
}

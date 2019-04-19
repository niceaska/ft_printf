#include "ft_printf.h"
#include "libft/libft.h"

long ft_print_c(va_list ag, t_pr *vals)
{
	long size;
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

long ft_print_str(va_list ag, t_pr *vals)
{
	char			*s;
	char			*tmp;
	int				i;
	long			size;

	i = 0;
	size = 0;
	tmp = va_arg(ag, char *);
	s = (tmp) ? ft_strdup(tmp) : ft_strdup("(null)");
	if ((vals->prec >= 0 && tmp) || (vals->prec >= 6 && !tmp))
		s[vals->prec] = (vals->prec < (int)ft_strlen(s)) ?\
						'\0' : s[vals->prec];
	i = (vals->prec < 6 && !tmp) ? vals->field : \
					vals->field - (int)ft_strlen(s);
	if (i > 0 && !vals->f_minus)
		size += ft_printer(i, ' ');
	tmp = (!tmp && (vals->prec < (int)ft_strlen(s))) ? NULL : s;
	while (*s && tmp && s)
		size += write(1, s++, 1);
	if (vals->f_minus && i > 0)
		size += ft_printer(i, ' ');
	((tmp) ? free(tmp) : free(s));
	return (size);
}


long ft_print_ptr(va_list ag, t_pr *vals)
{
	char			*s;
	void			*tmp;
	int				i;
	long	size;

	i = 0;
	size = 0;
	tmp = va_arg(ag, void *);
	s = (tmp) ? ft_pr_ltoa_base((uintptr_t)tmp, 16, 0) : ft_strdup("(nil)");	
	i = (tmp) ? (vals->field - (MAX((int)ft_strlen(s), vals->prec) + 2)) :\
										vals->field - ft_strlen(s);
	if (i  > 0 && !vals->f_minus)
		size += ft_printer(i, ' ');
	size += (tmp) ? write(1, "0x", 2) : 0;
	while (tmp && vals->prec-- > ft_strlen(s))
		size += write(1, "0", 1);
	tmp = s;
	while (*s && s)
		size += write(1, s++, 1);
	if (vals->f_minus && i > 0)
		size += ft_printer(i, ' ');
	free(tmp);
	return (size);
}

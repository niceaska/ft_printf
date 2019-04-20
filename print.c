#include "ft_printf.h"
#include "libft/libft.h"

long ft_printer(long i, char c)
{
	long size;

	size = 0;
	while(i--)
		size += write(1, &c, 1);
	return (size);
}

int		ft_choices(char conv, va_list args, t_pr *vals)
{
	long size;
	
	size = 0;
	if (conv == 'c')
		size += ft_print_c(args, vals);
	else if (conv == 'd')
		size += ft_print_i(args, vals, 0, 0);
	else if (conv == 's')
		size += ft_print_str(args, vals);
	else if (conv == 'p')
		size += ft_print_ptr(args, vals);
	else if (conv == '%')
		size += write(1, "%", 1);
	return ((int)size);
}

int		ft_print_handler(char *str, long size,  va_list args)
{
	t_pr	*vals;
	
	if (*str == '\0' || !str)
		return ((int)size);
	while (*str && *str != '%')
		size += (write(1, str++, 1));
	vals = init_val();
	if (*str == '%')
	{
		str = parse_val(&vals, str + 1);
		size += ft_choices(*str, args, vals);
		str++;
	}
	free(vals);
	return (ft_print_handler(str, size, args));
}

int					ft_printf(const char *format, ...)
{
	int size;

	va_list arg; 
	va_start(arg, format); 
	
	size = ft_print_handler((char *)format, 0, arg);	
	va_end(arg); 
	return ((int)size);
}

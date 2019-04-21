#include "ft_printf.h"

static unsigned long uns_arg_convert(va_list ag, t_pr *v)
{
	unsigned long n;

	n = (v->arg_mods[0]) ? va_arg(ag, unsigned long) \
							: va_arg(ag, unsigned int);
	n = (v->arg_mods[1]) ? (unsigned char)n : n;
	n = (v->arg_mods[2]) ? (unsigned short)n : n;
	return (n);

}
static	long add_pref(char mod, t_pr *v, long n)
{
	long	size;

	size = 0;
	if (v->f_d && n != 0)
	{
		if (mod == 'o' && !v->f_zero)
			size += write(1, "0", 1);
		else if (mod == 'x')
			size += write(1, "0x", 2);
		else if (mod == 'X')
			size += write(1, "0X", 2);
	}
	return (size);
}

char		*init_num_string(long n, t_pr *v, char conv)
{
	char *num;

	if (conv == 'o')
		num = (n == 0 && !v->prec && !v->f_d) ? \
				ft_strnew(1) : ft_ultoa_base(n, 8, 0);
	else if (conv == 'x')
		num = (n == 0 && !v->prec) ? \
				ft_strnew(1) : ft_ultoa_base(n, 16, 0);
	else if (conv == 'X')
		num = (n == 0 && !v->prec) ? \
				ft_strnew(1) : ft_ultoa_base(n, 16, 1);
	else if (conv == 'd' || conv == 'i')
		num = (n == 0 && !v->prec) ? ft_strnew(1) : ft_ltoa(n);
	return (num);
}


long			ft_print_ox(va_list ag, t_pr *v, long i, char conv)
{
	long	n;
	long	size;
	char	*num;
	char	*tmp;

	size = 0;
	n = uns_arg_convert(ag, v);
	num = init_num_string(n, v, conv);
	i = find_add_field_size(v, n, num, conv);
	size += (v->f_plus && v->f_zero && n >= 0 && \
						v->prec == -1) ? write(1, " ", 1) : 0;
	size += (((v->prec - (int)ft_strlen(num) > 0) || (i >= 0 && !v->f_zero) \
		|| (i > 0 && v->prec >= 0)) && !v->f_minus) ? 0 : add_pref(conv, v, n);
	if (!v->f_minus)
		size += (v->f_zero && v->prec == -1) \
								? ft_printer(i, '0') : ft_printer(i, ' ');
	if (!v->f_minus && !v->f_zero)
		size += add_pref(conv, v, n);
	size += manage_fl_prec(v, num, n, conv);
	tmp = num;
	while (*tmp && tmp)
		size += write(1, tmp++, 1);
	size += (v->f_minus) ? ft_printer(i, ' ') : 0;
	free(num);
	return (size);
}

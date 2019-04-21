#include "ft_printf.h"

long		arg_convert(va_list ag, t_pr *v)
{
	long n;

	n = (v->arg_mods[0]) ? va_arg(ag, long) : va_arg(ag, int);
	n = (v->arg_mods[1]) ? (char)n : n;
	n = (v->arg_mods[2]) ? (short)n : n;
	return (n);
}

long		find_add_field_size(t_pr *v, long n, char *num, char conv)
{
	long i;

	if (n < 0)
		i = v->field - MAX(v->prec + 1, ((int)ft_strlen(num)));
	else
		i = v->field - MAX(v->prec, ((int)ft_strlen(num)));
	i -= (v->f_plus && n >= 0 && conv != 'o' \
					&& conv != 'x' && conv != 'X') ? 1 : 0;
	if (n != 0 && v->f_d)
	{
		if (conv == 'o')
			i -= 1;
		else if (conv == 'x' || conv == 'X')
			i -= 2;
	}
	return ((i < 0) ? 0 : i);
}

long		manage_fl_prec(t_pr *v, char *num, long n, char conv)
{
	long s;
	long i;

	s = 0;
	i = find_add_field_size(v, n, num, conv);
	if (v->f_plus && !v->f_zero && n >= 0 \
		&& conv != 'o' && conv != 'x' && conv != 'X')
		s += write(1, "+", 1);
	if (v->prec > 0 && n < 0) 
		s += write(1, "-", 1);
	if (i == 0 && v->f_space && n > 0)
		s += write(1, " ", 1);
	if (v->prec > 0 && !(n == 0 && !v->prec) && (v->prec > (int)ft_strlen(num)))
		s += ft_printer((v->prec - (int)ft_strlen(num)), '0');
	if (v->prec > 0 && !(n == 0 && !v->prec) && \
		(v->prec > (int)ft_strlen(num + 1) && n < 0))
		s += ft_printer(1, '0');
	return (s);
}

long			ft_print_i(va_list ag, t_pr *v, long i, char conv)
{
	long	n;
	long	size;
	char	*num;
	char	*tmp;

	size = 0;
	n = arg_convert(ag, v);
	num = init_num_string(n, v, conv);
	i = find_add_field_size(v, n, num, conv);
	size += (v->f_plus && v->f_zero && n >= 0 && \
						v->prec == -1) ? write(1, "+", 1) : 0;
	size += (v->f_zero && n < 0 && \
					v->prec == -1) ? write(1, "-", 1) : 0;
	if (!v->f_minus)
		size += (v->f_zero && v->prec == -1) \
								? ft_printer(i, '0') : ft_printer(i, ' ');
	size += manage_fl_prec(v, num, n, conv);
	tmp = ((n < 0 && v->prec > 0) || (n < 0  && \
						v->f_zero && v->prec == -1)) ? num + 1 : num;
	while (*tmp && tmp)
		size += write(1, tmp++, 1);
	size += (v->f_minus) ? ft_printer(i, ' ') : 0;
	free(num);
	return (size);
}

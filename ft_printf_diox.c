#include "ft_printf.h"
#include "libft/libft.h"

static long		arg_convert(va_list ag, t_pr *v)
{
	long n;

	n = (v->arg_mods[0]) ? va_arg(ag, long) : va_arg(ag, int);
	n = (v->arg_mods[1]) ? (char)n : n;
	n = (v->arg_mods[2]) ? (short)n : n;
	return (n);
}

static long		find_add_field_size(t_pr *v, long n, char *num)
{
	long i;

	if (n < 0)
		i = v->field - MAX(v->prec + 1, ((int)ft_strlen(num)));
	else
		i = v->field - MAX(v->prec, ((int)ft_strlen(num)));
	i -= (v->f_plus && n >= 0) ? 1 : 0;
	return ((i < 0) ? 0 : i);
}

static long		manage_fl_prec(t_pr *v, char *num, long n, long i)
{
	long s;

	s = 0;
	if (v->f_plus && !v->f_zero && n >= 0)
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

long			ft_print_i(va_list ag, t_pr *v, long i, long size)
{
	long	n;
	char	*num;
	char	*tmp;

	n = arg_convert(ag, v);
	num = (n == 0 && !v->prec) ? ft_strnew(1) : ft_ltoa(n);
	i = find_add_field_size(v, n, num);
	size += (v->f_plus && v->f_zero && n >= 0 && \
						v->prec == -1) ? write(1, "+", 1) : 0;
	size += (v->f_zero && n < 0 && \
					v->prec == -1) ? write(1, "-", 1) : 0;
	if (!v->f_minus)
		size += (v->f_zero && v->prec == -1) \
								? ft_printer(i, '0') : ft_printer(i, ' ');
	size += manage_fl_prec(v, num, n, i);
	tmp = ((n < 0 && v->prec > 0) || (n < 0  && \
						v->f_zero && v->prec == -1)) ? num + 1 : num;
	while (*tmp && tmp)
		size += write(1, tmp++, 1);
	size += (v->f_minus) ? ft_printer(i, ' ') : 0;
	free(num);
	return (size);
}

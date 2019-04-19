#include "ft_printf.h"
#include "libft/libft.h"

static int			ft_isconv(char c)
{
	if (c == 'd'|| c == 'i' || c == 'c' || c == 'u' \
			|| c == 'x' || c == 's' || c == 'o' || c == 'f' \
			|| c == 'X' || c == 'p' || c == '%')
		return (1);
	return (0);
}

static int	ft_isflag(char c)
{
	return (c == ' ' || c == '0' || c == '+' \
					|| c == '-' || c == '#');
}

t_pr	*init_val(void)
{
	t_pr	*vals;
	int		i;

	i = 0;
	if (!(vals = (t_pr *)malloc(sizeof(t_pr))))
		return (NULL);
	vals->prec = -1;
	vals->field = 0;
	vals->hex_flag = 0;
	vals->f_zero = 0;
	vals->f_plus = 0;
	vals->f_space = 0;
	vals->f_minus = 0;
	vals->f_d = 0;
	while (i < 4)
		vals->arg_mods[i++] = 0;
	return (vals);
}

static char	*parse_flags(t_pr **val, char *fmt)
{
	char	flags[10];
	int		i;

	i = 0;
	ft_bzero((void *)flags, 10);
	if (ft_isconv(*fmt) ||\
			(*fmt >= '1' && *fmt <= '9'))
			return (fmt);
	while (ft_isflag(*fmt))
	{
		flags[i++] = *fmt;
		fmt++;
	}
	if (ft_strchr(flags, '-'))
		(*val)->f_minus = 1;
	if (ft_strchr(flags, '#'))
		(*val)->f_d = 1;
	if (ft_strchr(flags, '+'))
		(*val)->f_plus = 1;
	if (ft_strchr(flags, '0') && !ft_strchr(flags, '-'))
		(*val)->f_zero = 1;
	if (ft_strchr(flags, ' ') && !ft_strchr(flags, '+'))
		(*val)->f_space = 1;
	return (fmt);
}

char	*parse_val(t_pr **val, char *fmt)
{
	fmt = parse_flags(val, fmt);
	if (ft_isdigit(fmt[0]))
	{
		(*val)->field = ft_atoi(fmt);
			while (ft_isdigit(*fmt) && *fmt)
				fmt++;
	}
	if (*fmt == '.')
		if (((*val)->prec = ft_atoi(fmt + 1)) <= 0)
			(*val)->prec = 0;
	while (*fmt)
	{
		(*val)->arg_mods[0] = (*fmt == 'l') ? 1 : 0;
		(*val)->arg_mods[1] = (*fmt == 'h' && \
							*(fmt + 1) == 'h') ? 1 : 0;
		(*val)->arg_mods[2] = (*fmt == 'h' && *(fmt + 1) != 'h' \
								&& *(fmt - 1) != 'h') ? 1 : 0;
		(*val)->arg_mods[3] = (*fmt == 'L') ? 1 : 0;
		if (ft_isconv(*fmt))
			break ;
		fmt++;
	}
	(*val)->hex_flag = (*fmt == 'X') ? 1 : 0;
	return (fmt);
}
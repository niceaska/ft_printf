#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>

typedef struct		s_pr
{
	int		prec;
	int		field;
	int		hex_flag;
	int 	f_zero;
	int		f_plus;
	int		f_space;
	int		f_minus;
	int		f_d;
	int		arg_mods[4];
}					t_pr;

int					ft_printf(const char *format, …);
char				*ft_pr_itoa_base(int n, int base, int flag);
char				*ft_pr_ltoa_base(long n, int base, int flag);
char				*ft_ltoa(long n);
char				*ft_utoa(unsigned int n);
char				*ft_ultoa(unsigned long n);

#endif
#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define MAX(a, b) (((a) > (b)) ? (a) : (b))

# include <libft.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
# include <inttypes.h>

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

int					ft_printf(const char *format, ...);
char				*ft_pr_itoa_base(int n, int base, int flag);
long				ft_print_i(va_list ag, t_pr *v, long i, char conv);
char				*ft_pr_ltoa_base(long long n, int base, int flag);
char				*ft_ultoa_base(unsigned long n, int base, int flag);
char				*ft_ltoa(long long n);
char				*ft_utoa(unsigned int n);
char				*ft_ultoa(unsigned long n);
t_pr				*init_val(void);
char				*parse_val(t_pr **val, char *fmt);
long				ft_print_ptr(va_list ag, t_pr *vals);
long				ft_print_str(va_list ag, t_pr *vals);
long				ft_print_c(va_list ag, t_pr *vals);
long				ft_printer(long i, char c);
long				arg_convert(va_list ag, t_pr *v);
long				manage_fl_prec(t_pr *v, char *num, long n, char conv);
char				*init_num_string(long n, t_pr *v, char conv);
long				ft_print_ox(va_list ag, t_pr *v, long i, char conv);
long				find_add_field_size(t_pr *v, long n, char *num, char conv);


#endif
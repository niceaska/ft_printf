#include <stdio.h>
#include "ft_printf.h"
#include "libft/libft.h"

int main(void)
{
	int i;
	i = ft_printf("Test %80.20d\n", -1000);
	printf("%d\n", i);
	i = printf("Test %80.20d\n", -1000);
	printf("%d\n", i);
	int n = -200;
	n = (char)n;
	printf("%d %2.3d\n", n, 200);
	/*long val;
	long double test = 20.54888888889;
	
	char *s = ft_strnew(120);
	char *p;
			long double swp;

	long n = (long long)test;
		printf("%ld\n", n);

	ft_strcpy(s, ft_ltoa(n));
	int siz = ft_strlen(s);
	s[siz++] = '.';
	while (siz < 52)
	{
		swp = test;
		test *= (long double)10.0f;
						printf("%Lf\n", test);

		test -= (long)swp * 10;
				printf("%Lf\n", test);

		val = (long)test;
		p = ft_itoa(val);
		s[siz] = *p;
		siz++;
	}
	printf("%s\n", s);
	printf("wtf is %.51f\n", 20.54888888889);*/

/*
	int c = printf("%.8c\n", 'a');
	printf("%0#5% %d\n", 66, c);
	printf("%d\n", (short)2000);
	printf("%0f\n", 0.5);

	printf("%.-10d", -100);*/
}

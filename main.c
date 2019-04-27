#include <stdio.h>
#include <limits.h>
#include "ft_printf.h"

int main(void)
{

ft_printf("{%}");
printf("{%}");

int i = 88;

	ft_printf("This is a simple test.\nSecond sentence.\n");
	ft_printf("");
	ft_printf("\n");


	ft_printf("ft_printf - %d\n", i);
	i = ft_printf("This is a simple test.\nSecond sentence.\n");
	ft_printf("ft_printf - %d\n", i);
	i = ft_printf("%#020X\n", -10);
	ft_printf("ft_printf - %d\n", i);
	i = ft_printf("%#020X\n", -10);
	ft_printf("ft_printf - %d\n", i);
	/*i = ft_printf("%# 20i\n", -10);
	ft_printf("ft_printf - %d\n", i);
	i = ft_printf("% 20i\n", -10);
	ft_printf("ft_printf - %d\n", i);
	i = ft_printf("Test %80.20d\n", -1000);
	ft_printf("%d\n", i);
	i = ft_printf("Test %80.20d\n", -1000);
	ft_printf("%d\n", i);

/*	
	long val;
	long double test = 20.54888888889;
	
	char *s = ft_strnew(120);
	char *p;
			long double swp;

	long n = (long long)test;
		ft_printf("%ld\n", n);

	ft_strcpy(s, ft_ltoa(n));
	int siz = ft_strlen(s);
	s[siz++] = '.';
	while (siz < 52)
	{
		swp = test;
		test *= (long double)10.0f;

		test -= (long)swp * 10;

		val = (long)test;
		p = ft_itoa(val);
		s[siz] = *p;
		siz++;
	}
	ft_printf("%s\n", s);
	ft_printf("wtf is %.47f\n", 20.54888888889);
*/
/*
	int c = ft_printf("%.8c\n", 'a');
	ft_printf("%0#5% %d\n", 66, c);
	ft_printf("%d\n", (short)2000);
	ft_printf("%0f\n", 0.5);

	ft_printf("%.-10d", -100);*/
}

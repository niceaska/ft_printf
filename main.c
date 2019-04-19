#include <stdio.h>
#include "ft_printf.h"

int main(void)
{
	int i;
	i = ft_printf("Test %-4c %-20.80s\n", 'a', "String is a devil");
	printf("%d\n", i);
	i = printf("Test %-4c %-20.80s\n", 'a', "String is a devil");
	printf("%d\n", i);
/*
	int c = printf("%.8c\n", 'a');
	printf("%0#5% %d\n", 66, c);
	printf("%d\n", (short)2000);
	printf("%0f\n", 0.5);

	printf("%.-10d", -100);*/
}

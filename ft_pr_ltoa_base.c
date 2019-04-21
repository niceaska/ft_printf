#include "ft_printf.h"

static size_t	get_size(long n, int base)
{
	size_t			size;
	unsigned long	val;

	size = (n < 0 && base == 10) ? 1 : 0;
	val = (n < 0 && base == 10) ? -n : n;
	while (val)
	{
		size++;
		val /= base;
	}
	return (size);
}

char			*ft_pr_ltoa_base(long long n, int base, int flag)
{
	char			*arr;
	size_t			size;
	unsigned long	val;

	if (((unsigned long)n == -9223372036854775808U) && base == 10)
		return (ft_strdup("-9223372036854775808"));
	else if (n == 0 || (base > 16 || base < 2))
		return (ft_strdup("0"));
	size = get_size(n, base);
	if (!(arr = (char *)malloc(sizeof(char) * size + 1)))
		return (NULL);
	arr[size] = '\0';
	arr[0] = (n < 0 && base == 10) ? '-' : arr[0];
	val = (n < 0 && base == 10) ? -n : n;
	while (val)
	{
		if (!flag)
			arr[--size] = (val % base > 9) ? val % base + 'a' - 10 :\
										val % base + '0';
		else
			arr[--size] = (val % base > 9) ? val % base + 'A' - 10 :\
										val % base + '0' ;
		val /= base;
	}
	return (arr);
}

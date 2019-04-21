#include "ft_printf.h"

static size_t	get_size(int n, int base)
{
	size_t			size;
	unsigned int	val;

	size = (n < 0 && base == 10) ? 1 : 0;
	val = n;
	while (val)
	{
		size++;
		val /= base;
	}
	return (size);
}

char			*ft_pr_itoa_base(int n, int base, int flag)
{
	char			*arr;
	size_t			size;
	unsigned int	val;

	if (n == -2147483648 && base == 10)
		return (ft_strdup("-2147483648"));
	else if (n == 0 || (base > 16 || base < 2))
		return (ft_strdup("0"));
	size = get_size(n, base);
	if (!(arr = (char *)malloc(sizeof(char) * size + 1)))
		return (NULL);
	arr[size] = '\0';
	arr[0] = (n < 0 && base == 10) ? '-' : arr[0];
	val = n;
	while (val)
	{
		if (!flag)
			arr[--size] = (val % base <= 9) ? val % base + '0' :\
										val % base + 'a' - 10;
		else
			arr[--size] = (val % base <= 9) ? val % base + '0' :\
										val % base + 'A' - 10;
		val /= base;
	}
	return (arr);
}

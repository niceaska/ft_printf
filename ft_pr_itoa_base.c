#include "libft/libft.h"

static size_t	get_size(int n, int base)
{
	size_t	size;

	size = (n < 0) ? 1 : 0;
	n = (n < 0) ? -n : n;
	while (n)
	{
		size++;
		n /= base;
	}
	return (size);
}

static char		*overflow_cases(int base)
{
	if (base == 10)
		return (ft_strdup("-2147483648"));
	else if (base == 8)
		return (ft_strdup("-20000000000"));
	else if (base == 16)
		 return (ft_strdup("-80000000"));

}

char			*ft_pr_itoa_base(int n, int base, int flag)
{
	char	*arr;
	size_t	size;

	if (n == -2147483648)
		return (overflow_cases(base));
	else if (n == 0 || (base > 16 || base < 2))
		return (ft_strdup("0"));
	size = get_size(n, base);
	if (!(arr = (char *)malloc(sizeof(char) * size + 1)))
		return (NULL);
	arr[size] = '\0';
	arr[0] = (n < 0) ? '-' : arr[0];
	n = (n < 0) ? -n : n;
	while (n)
	{
		if (!flag)
			arr[--size] = (n % base <= 9) ? n % base + '0' :\
										n % base + 'a' - 10;
		else
			arr[--size] = (n % base <= 9) ? n % base + '0' :\
										n % base + 'A' - 10;
		n /= base;
	}
	return (arr);
}
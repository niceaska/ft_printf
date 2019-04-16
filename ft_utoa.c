#include "ft_printf.h"
#include "libft/libft.h"

static unsigned long		get_size(unsigned long n)
{
	unsigned long	size;

	size = 0;
	while (n)
	{
		size++;
		n /= 10;
	}
	return (size);
}

char			*ft_utoa(unsigned int n)
{
	char			*arr;
	unsigned long	size;

	if (n == 0)
		return (ft_strdup("0"));
	size = get_size(n);
	if (!(arr = (char *)malloc(sizeof(char) * size + 1)))
		return (NULL);
	arr[size] = '\0';
	while (n)
	{
		arr[--size] = n % 10 + '0';
		n /= 10;
	}
	return (arr);
}

char			*ft_ultoa(unsigned long n)
{
	char			*arr;
	unsigned long	size;

	if (n == 0)
		return (ft_strdup("0"));
	size = get_size(n);
	if (!(arr = (char *)malloc(sizeof(char) * size + 1)))
		return (NULL);
	arr[size] = '\0';
	while (n)
	{
		arr[--size] = n % 10 + '0';
		n /= 10;
	}
	return (arr);
}

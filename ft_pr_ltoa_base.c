static size_t	get_size(long n, int base)
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
		return (ft_strdup("-9223372036854775808"));
	else if (base == 8)
		return (ft_strdup("-1000000000000000000000"));
	else if (base == 16)
		 return (ft_strdup("-8000000000000000"));
	return (NULL);
}

char			*ft_pr_ltoa_base(long n, int base, int flag)
{
	char	*arr;
	size_t	size;

	if (n == -9223372036854775808L)
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
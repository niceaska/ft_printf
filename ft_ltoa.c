static size_t	get_size(long n)
{
	int		size;

	size = (n < 0) ? 1 : 0;
	n = (n < 0) ? -n : n;
	while (n)
	{
		size++;
		n /= 10;
	}
	return (size);
}

char			*ft_ltoa(long n)
{
	char	*arr;
	size_t	size;

	if (n == -9223372036854775808L)
		return (ft_strdup("-9223372036854775808"));
	else if (n == 0)
		return (ft_strdup("0"));
	size = get_size(n);
	if (!(arr = (char *)malloc(sizeof(char) * size + 1)))
		return (NULL);
	arr[size] = '\0';
	arr[0] = (n < 0) ? '-' : arr[0];
	n = (n < 0) ? -n : n;
	while (n)
	{
		arr[--size] = n % 10 + '0';
		n /= 10;
	}
	return (arr);
}
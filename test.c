int	main()
{
	int i;
	i = 0;
	while (i < 100000000)
	{
		malloc(100000);
		i++;
	}
	char *toto;
	toto = malloc(100);
	ft_memset(toto, 'z', 10000);
	ft_putstr(toto);
	return (0);
}

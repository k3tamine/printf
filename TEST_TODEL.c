void	modif2(char **str)
{
	(*str)++;
}

void	modif(char **str)
{
	modif2(str);
}

int	main()
{
	char *toto;

	toto = malloc(100);
	toto = "abcdef";
	printf("%s\n", toto);
	modif(&toto);
	printf("%s\n", toto);
	toto++;
	printf("%s\n", toto);
	return (0);
}
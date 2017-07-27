int		get_base(char specifier)
{
	if (specifier == 'x' || specifier == 'X' || specifier == 'p')
		return (16);
	else if (specifier == 'u' || specifier == 'U' ||
				specifier == 'd' || specifier == 'D' ||
				specifier == 'i')
		return (10);
	else if (specifier == 'o' || specifier == 'O')
		return (8);
	else if (specifier == 'b' || specifier == 'B')
		return (2);
	return (-1);
}
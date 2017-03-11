#include "ft_printf.h"

int	is_unsigned(char c)
{
	return (c == 'o' || c == 'O' || c == 'x' || c == 'X' ||
			c == 'u' || c == 'U' || c == 'p');
}

int	is_signed(char c)
{
	return (c == 'd' || c == 'D' || c == 'i');
}

int	is_characters(char c)
{
	return (c == 'c' || c == 'C' || c == 's' || c == 'S');
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonon <mgonon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 04:11:46 by mgonon            #+#    #+#             */
/*   Updated: 2017/08/24 00:59:38 by mgonon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		check_is(char c)
{
	if (c == '#' || c == '0' || c == '-' || c == ' ' || c == '+')
		return (IS_FLAG);
	else if (c == 'l' || c == 'h' || c == 'j' || c == 'z')
		return (IS_LENGTH);
	else if (c == 'o' || c == 'O' || c == 'x' || c == 'X' ||
			c == 'u' || c == 'U' || c == 'p'|| c == 'b' || c == 'B')
		return (IS_UNSIGNED);
	else if (c == 'd' || c == 'D' || c == 'i')
		return (IS_SIGNED);
	else if (c == 'c' || c == 'C' || c == 's' || c == 'S')
		return (IS_CHARACTERS);
	else if (c == '%')
		return (6);
	else
		return (-1);
}

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

char	*intmaxtoa_base(intmax_t value, int base)
{
	char		*res;
	intmax_t	nb;
	int			sign;
	int			i;

	if (base < 2 || base > 16)
		return (NULL);
	nb = (value > 0) ? -value : value;
	sign = (value < 0 && base == 10) ? -1 : 0;
	i = (sign == -1) ? 2 : 1;
	while ((nb /= base) <= -1)
		i++;
	if (!(res = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	res[i] = '\0';
	nb = (value > 0) ? -value : value;
	while (i + sign)
	{
		res[--i] = (nb % base < 10) ? -(nb % base) + '0'
					: -(nb % base) + 'A' - 10;
		nb /= base;
	}
	if (i == 1)
		res[0] = '-';
	return (res);
}

char	*uintmaxtoa_base(uintmax_t value, int base)
{
	char		*res;
	uintmax_t	nb;
	int			i;

	if (base < 2 || base > 16)
		return (NULL);
	nb = value;
	i = 1;
	while ((nb /= base) >= 1)
		i++;
	if (!(res = (char*)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	res[i] = '\0';
	nb = value;
	while (i)
	{
		res[--i] = (nb % base < 10) ? nb % base + '0'
					: nb % base + 'a' - 10;
		nb /= base;
	}
	return (res);
}

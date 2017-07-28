/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonon <mgonon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 04:11:46 by mgonon            #+#    #+#             */
/*   Updated: 2017/07/28 03:25:12 by mgonon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	init_format(t_format *frmt)
{
	frmt->flags.minus = 0;
	frmt->flags.plus = 0;
	frmt->flags.space = 0;
	frmt->flags.sharp = 0;
	frmt->flags.zero = 0;
	frmt->width = 0;
	frmt->precision = -1;
	frmt->length.h = 0;
	frmt->length.l = 0;
	frmt->length.j = 0;
	frmt->length.z = 0;
	frmt->specifier = 0;
}

int	check_is(char c)
{
	if (c == '#' || c == '0' || c == '-' || c == ' ' || c == '+')
		return (IS_FLAG);
	else if (c == 'l' || c == 'h' || c == 'j' || c == 'z')
		return (IS_LENGTH);
	else if (c == 'p' || c == 'd' || c == 'i' ||
			 c == 'o' || c == 'O' || c == 'x' ||
			 c == 'X' || c == 'D' || c == 'u' ||
			 c == 'U' || c == 'C' || c == 'c' ||
			 c == 's' || c == 'S' || c == '%')
		return (IS_SPECIFIER);
	else if (c == 'o' || c == 'O' || c == 'x' || c == 'X' ||
			 c == 'u' || c == 'U' || c == 'p')
		return (IS_UNSIGNED);
	else if (c == 'd' || c == 'D' || c == 'i')
		return (IS_SIGNED);
	else if (c == 'c' || c == 'C' || c == 's' || c == 'S')
		return (IS_CHARACTERS);
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

char	*ft_sign_itoa_base(intmax_t value, int base)
{
	char	*res;
	long	nb;
	int		sign;
	int		i;

	if (base < 2 || base > 16)
		return (NULL);
	nb = (value < 0) ? -(long)value : value;
	sign = (value < 0 && base == 10) ? -1 : 0;
	i = (sign == -1) ? 2 : 1;
	while ((nb /= base) >= 1)
		i++;
	if (!(res = (char*)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	res[i] = '\0';
	nb = (value < 0) ? -(long)value : value;
	while (i + sign)
	{
		res[--i] = (nb % base < 10) ? nb % base + '0'
					: nb % base + 'A' - 10;
		nb /= base;
	}
	if (i == 1)
		res[0] = '-';
	return (res);
}

char	*ft_usign_itoa_base(uintmax_t value, int base)
{
	char	*res;
	long	nb;
	int		i;

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
					: nb % base + 'A' - 10;
		nb /= base;
	}
	return (res);
}
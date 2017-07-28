/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonon <mgonon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/28 02:07:07 by mgonon            #+#    #+#             */
/*   Updated: 2017/07/28 03:17:52 by mgonon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa_base(int value, int base)
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

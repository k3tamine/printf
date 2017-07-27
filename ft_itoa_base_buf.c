/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_buf.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonon <mgonon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 20:57:06 by mgonon            #+#    #+#             */
/*   Updated: 2017/07/27 14:32:35 by mgonon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#define BASE "0123456789ABCDEF"

static int	ft_calculate_size(intmax_t nb, int base, int sign)
{
	int	size;

	size = 1;
	while (nb / base * sign >= 1)
	{
		size++;
		nb /= base;
	}
	return (sign < 0) ? size + 1 : size;
}

// static char	ft_get_char(int	nb)
// {
// 	int		i;

// 	i = 0;
// 	while (i < nb)
// 		i++;
// 	return (BASE[i]);
// }

int			ft_itoa_base_buf(intmax_t n, int base, char *res)
{
	size_t	i;
	size_t	size;
	size_t	tmp;
	int		sign;

	if (base < 2 || base > 16 || !res)
		return (0);
	sign = (n < 0) ? -1 : 1;
	size = ft_calculate_size(n, base, sign);
	tmp = size;
	i = 0;
	if (sign == -1)
		res[i++] = '-';
	res[tmp] = '\0';
	while (i < tmp)
	{
		res[tmp - 1] = n % base * sign + '0';
		n /= base;
		tmp--;
	}
	return (size);
}

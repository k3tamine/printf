/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa_base_buf.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonon <mgonon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 20:57:06 by mgonon            #+#    #+#             */
/*   Updated: 2017/03/14 04:12:40 by mgonon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#define BASE "0123456789ABCDEF"

static int	ft_calculate_size(uintmax_t nb, int base)
{
	int	size;

	size = 1;
	while (nb / base >= 1)
	{
		size++;
		nb /= base;
	}
	return (size);
}

static char	ft_get_char(int	nb)
{
	int		i;

	i = 0;
	while (i < nb)
		i++;
	return (BASE[i]);
}

int			ft_uitoa_base_buf(uintmax_t n, int base, char *res)
{
	size_t	i;
	size_t	size;
	size_t	tmp;

	if (base < 2 || base > 16 || !res)
		return (0);
	size = ft_calculate_size(n, base);
	tmp = size;
	i = 0;
	res[tmp] = '\0';
	while (i < tmp)
	{
		res[tmp - 1] = ft_get_char(n % base);
		n /= base;
		tmp--;
	}
	// printf("\nbuf = %s\n", res);
	return (size);
}

// int	main()
// {
// 	char *toto;
// 	toto = malloc(10000);
// 	ft_uitoa_base_buf(42, 8, toto);
// 	printf("%s\n", toto);
// }
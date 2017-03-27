/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa_base_buf.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonon <mgonon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 20:57:06 by mgonon            #+#    #+#             */
/*   Updated: 2017/03/23 07:23:16 by mgonon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#define BASE "0123456789ABCDEF"
#define BASE_LOW "0123456789abcdef"

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

static char	ft_get_char(int	nb, int b_type)
{
	int		i;

	i = 0;
	while (i < nb)
		i++;
	if (b_type)
		return (BASE_LOW[i]);
	else
		return (BASE[i]);
}

int			ft_uitoa_base_buf(uintmax_t n, int base, char *res, int b_type)
{
	size_t	i;
	size_t	size;
	size_t	tmp;

	if (base < 2 || base > 16 || !res)
		return (0);
	size = ft_calculate_size(n, base);
	// printf("\nsize = %d\n", size);
	tmp = size;
	i = 0;
	res[tmp] = '\0';
	while (i < tmp)
	{
		res[tmp - 1] = ft_get_char(n % base, b_type);
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
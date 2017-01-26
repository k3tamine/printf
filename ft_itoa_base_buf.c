/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_buf.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonon <mgonon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 20:57:06 by mgonon            #+#    #+#             */
/*   Updated: 2017/01/26 11:10:54 by mgonon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#define BASE "0123456789ABCDEF"

int		ft_calculate_size(int nb, int base, int sign)
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

char	ft_get_char(int	nb)
{
	int		i;

	i = 0;
	while (i < nb)
		i++;
	return (BASE[i]);
}

int		ft_itoa_base_buf(int n, int base, char *res)
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

/*int	main()
{
	char *toto;

	toto = malloc(100);
	printf("%s\n", ft_itoa_base_buf(12345, 2, toto));
	printf("%s\n", ft_itoa_base_buf(-2147483648, 10, toto));
	printf("%s\n", ft_itoa_base_buf(12345, 16, toto));
}*/

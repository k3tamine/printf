/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unicode.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonon <mgonon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 17:13:58 by mgonon            #+#    #+#             */
/*   Updated: 2017/06/08 18:08:01 by mgonon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	unicode(unsigned int c)
{
	int i;

	if (c < 128)
		i = 1;
	else if (c < 2048)
		i = 2;
	else if (c < 65536)
		i = 3;
	else
		i = 4;
	while (i-- > 0)
	{
		write(1, &c, 1);
		c = c >> 8;
	}
}

int 	main()
{
	unicode(11831521);
	write(1, "\n", 1);
	unicode(0x1234);
	write(1, "\n", 1);
    return (1);
}
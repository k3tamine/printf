/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonon <mgonon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 00:04:54 by mgonon            #+#    #+#             */
/*   Updated: 2017/07/28 08:29:57 by mgonon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string.h"

void	*ft_memset(void *str, int c, size_t n)
{
	size_t			i;
	unsigned char	b;
	unsigned char	*current;

	i = 0;
	b = (unsigned char)c;
	current = (unsigned char *)str;
	while (n--)
	{
		*current = b;
		current++;
	}
	return (str);
}

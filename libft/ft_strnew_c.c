/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonon <mgonon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/27 13:21:15 by mgonon            #+#    #+#             */
/*   Updated: 2017/07/28 08:30:35 by mgonon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew_c(size_t size, char c)
{
	char	*str;

	str = (char *)malloc(sizeof(*str) * size + 1);
	if (!str)
		return (NULL);
	else
		ft_memset(str, c, size);
	str[size] = '\0';
	return (str);
}

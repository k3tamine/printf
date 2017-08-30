/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnjoin_free.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonon <mgonon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/17 18:59:22 by mgonon            #+#    #+#             */
/*   Updated: 2017/08/30 05:50:19 by mgonon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnjoin_free(char *s1, char *s2, size_t n, int to_free)
{
	char	*ret_str;
	size_t	len;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	ret_str = (char *)malloc(sizeof(*ret_str) * len + 1);
	if (!ret_str)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i] || i < n)
		ret_str[j++] = s1[i++];
	i = 0;
	while (s2[i])
		ret_str[j++] = s2[i++];
	ret_str[j] = '\0';
	if (to_free == 1)
		free(s1);
	else if (to_free == 2)
		free(s2);
	return (ret_str);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonon <mgonon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/30 04:46:05 by mgonon            #+#    #+#             */
/*   Updated: 2017/08/30 05:40:53 by mgonon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_free(char *s1, char *s2, int to_free)
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
	while (s1[i])
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

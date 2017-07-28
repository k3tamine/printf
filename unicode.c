/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unicode.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonon <mgonon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 17:13:58 by mgonon            #+#    #+#             */
/*   Updated: 2017/07/28 04:11:45 by mgonon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// TODO ==> STATIC get_unicode_char

char		*get_unicode_char(wint_t unicode_c)
{
	int 	i;
	int		j;
	char	*res_str;

	j = 0;
	if (unicode_c < 128)
		i = 1;
	else if (unicode_c < 2048)
		i = 2;
	else if (unicode_c < 65536)
		i = 3;
	else
		i = 4;
	while (i-- > 0)
	{
		res_str[j++] = unicode_c;
		// write(1, &unicode_c, 1);
		unicode_c = unicode_c >> 8;
	}
	return (res_str);
}

char		*get_unicode_str(wchar_t *unicode_str)
{
	char	*res_str;
	char	*to_add;
	char	*tmp;

	res_str = ft_strnew(0);
	while (*unicode_str)
	{
		if (!(get_unicode_char((wchar_t)(*unicode_str))))
			return (NULL);
		tmp = res_str;
		res_str = ft_strjoin(tmp, to_add);
		free(to_add);
		free(tmp);
		unicode_str++;
	}
	return (res_str);
}

// int 	main()
// {
// 	unicode(11831521);
// 	write(1, "\n", 1);
// 	unicode(0x1234);
// 	write(1, "\n", 1);
//     return (1);
// }
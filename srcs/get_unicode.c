/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_unicode.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonon <mgonon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 17:13:58 by mgonon            #+#    #+#             */
/*   Updated: 2017/08/16 17:32:45 by mgonon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char		*get_unicode_char(wint_t unicode)
{
	char	*encoding;

	if (MB_CUR_MAX == 1)
		return (NULL);
	encoding = (char*)ft_strnew(5);	
	if (unicode <= 0x7F)
		encoding[0] = unicode;
	else if (unicode <= 0x7FF)
	{
		encoding[0] = ((unicode >> 6) | 0xC0);
		encoding[1] = ((unicode & 0x3F) | 0x80);
	}
	else if((unicode <= 0xd7FF) || (unicode >= 0xE000 && unicode <= 0xFFFF))
	{
		encoding[0] = ((unicode >> 12) | 0xE0);
		encoding[1] = (((unicode >> 6) & 0x3F) | 0x80);
		encoding[2] = ((unicode & 0x3F) | 0x80);
	}
	else if (unicode >= 0x10000 && unicode <= 0x10FFFF)
	{
		encoding[0] = ((unicode >> 18) | 0xF0);
		encoding[1] = (((unicode >> 12) & 0x3F) | 0x80);
		encoding[2] = (((unicode >> 6) & 0x3F) | 0x80);
		encoding[3] = ((unicode & 0x3F) | 0x80);
	}
	else
		return (NULL);
	return (encoding);
}

char		*get_unicode_str(wchar_t *unicode_str)
{
	char	*res_str;
	char	*to_add;

	res_str = ft_strnew(0);
	while (*unicode_str)
	{
		if (!(to_add = get_unicode_char((wint_t)(*unicode_str))))
			return (NULL);
		res_str = ft_strjoin(res_str, to_add);
		free(to_add);
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
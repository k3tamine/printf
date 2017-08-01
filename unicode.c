/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unicode.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonon <mgonon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 17:13:58 by mgonon            #+#    #+#             */
/*   Updated: 2017/08/01 14:58:08 by mgonon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// TODO ==> STATIC get_unicode_char

// char		*get_unicode_char(wint_t unicode_c)
// {
// 	int 	i;
// 	int		j;
// 	char	*res_str;

// 	res_str = (char *)ft_strnew(5);
// 	j = 0;
// 	if (unicode_c < 128)
// 		i = 1;
// 	else if (unicode_c < 2048)
// 		i = 2;
// 	else if (unicode_c < 65536)
// 		i = 3;
// 	else
// 		i = 4;
// 	while (i-- > 0)
// 	{
// 		res_str[j++] = unicode_c;
// 		unicode_c = unicode_c >> 8;
// 	}
// 	return (res_str);
// }

static void		ft_unicode_encoder_four_digits(wint_t unicode, char *encoding)
{
	encoding[0] = (240 | (unicode >> 18));
	encoding[1] = (128 | ((unicode >> 12) & 63));
	encoding[2] = (128 | ((unicode >> 6) & 63));
	encoding[3] = (128 | (unicode & 63));
}

char			*get_unicode_char(wint_t unicode)
{
	char	*encoding;

	encoding = (char*)ft_strnew(5);
	if (unicode <= 127)
		encoding[0] = unicode;
	else if (unicode <= 2047)
	{
		encoding[0] = (192 | (unicode & 1984) >> 6);
		encoding[1] = (128 | (unicode & 63));
	}
	else if (55296 <= unicode && unicode <= 57343)
		encoding = NULL;
	else if (unicode <= 65535)
	{
		encoding[0] = (224 | (unicode >> 12));
		encoding[1] = (128 | ((unicode >> 6) & 63));
		encoding[2] = (128 | (unicode & 63));
	}
	else if (unicode <= 1114111)
		ft_unicode_encoder_four_digits(unicode, encoding);
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
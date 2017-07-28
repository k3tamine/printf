/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_char_arg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonon <mgonon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/28 03:31:27 by mgonon            #+#    #+#             */
/*   Updated: 2017/07/28 03:34:28 by mgonon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*get_arg_c(va_list ap, int *size)
{
	char	arg;
	char	*output;

	arg = (char)va_arg(ap, int);
	output = ft_strndup(&arg, 1);
	*size = 1;
	return (output);
}

static char	*get_arg_s(va_list ap, int *size)
{
	char	*arg;
	char	*output;

	arg = (char*)va_arg(ap, char*);
	if (arg != NULL)
		output = ft_strdup(arg);
	else
		output = ft_strdup("(null)");
	*size = ft_strlen(output);
	return (output);
}

static char	*get_arg_lc(va_list ap, int *size)
{
	wint_t	arg;
	char	*output;

	arg = (wint_t)va_arg(ap, wint_t);
	if ((output = ft_unicode_encoder(arg)) == NULL)
		return (NULL);
	if ((*size = ft_strlen(output)) == 0)
		*size = 1;
	return (output);
}

static char	*get_arg_ls(va_list ap, int *size)
{
	wchar_t	*arg;
	char	*output;

	arg = (wchar_t*)va_arg(ap, wchar_t*);
	if (arg != NULL)
	{
		if ((output = ft_unicode_encoder_string(arg)) == NULL)
			return (NULL);
	}
	else
		output = ft_unicode_encoder_string(L"(null)");
	*size = ft_strlen(output);
	return (output);
}

char		*ftpf_convert_characters(va_list ap, t_format frmt,
									int *size)
{
	char	*res_str;

	if (frmt.specifier == 'C' ||
				(frmt.specifier == 'c' && frmt.length.l == 1))
		res_str = get_arg_lc(ap, size);
	else if (frmt.specifier == 'S' ||
				(frmt.specifier == 's' && frmt.length.l == 1))
		res_str = get_arg_ls(ap, size);
	else if (frmt.specifier == 'c')
		res_str = get_arg_c(ap, size);
	else if (frmt.specifier == 's')
		res_str = get_arg_s(ap, size);
	return (res_str);
}
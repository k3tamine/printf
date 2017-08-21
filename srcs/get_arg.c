/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_arg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonon <mgonon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/28 01:51:48 by mgonon            #+#    #+#             */
/*   Updated: 2017/08/21 20:14:24 by mgonon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static intmax_t		get_signed_arg(va_list args,
									char specifier, t_length length)
{
	intmax_t arg;

	if (length.l >= 2)
		arg = (intmax_t)va_arg(args, long long);
	else if (length.l == 1 || specifier == 'D')
		arg = (intmax_t)va_arg(args, long);
	else if (length.z >= 1)
		arg = va_arg(args, ssize_t);
	else if (length.j >= 1)
		arg = va_arg(args, long long);
	else if (length.h >= 2)
		arg = (intmax_t)(char)va_arg(args, int);
	else if (length.h == 1)
		arg = (intmax_t)(short)va_arg(args, int);
	else
		arg = (intmax_t)va_arg(args, int);
	return (arg);
}

static uintmax_t	get_unsigned_arg(va_list args,
									char specifier, t_length length)
{
	uintmax_t arg;

	if (length.l >= 2)
		arg = (uintmax_t)va_arg(args, unsigned long long);
	else if (length.l == 1 || specifier == 'U' ||
			specifier == 'O' || specifier == 'B')
		arg = (uintmax_t)va_arg(args, unsigned long);
	else if (length.z >= 1)
		arg = (uintmax_t)va_arg(args, size_t);
	else if (length.j >= 1)
		arg = va_arg(args, unsigned long long);
	else if (length.h >= 2)
		arg = (uintmax_t)(unsigned char)va_arg(args, unsigned int);
	else if (length.h == 1)
		arg = (uintmax_t)(unsigned short)va_arg(args, unsigned int);
	else
		arg = (uintmax_t)va_arg(args, unsigned int);
	return (arg);
}

char				*get_str_arg(va_list args, t_format frmt, int *tmp_len)
{
	uintmax_t	usign_arg;
	intmax_t	sign_arg;
	int			base;
	char		*res_str;

	base = get_base(frmt.specifier);
	if (check_is(frmt.specifier) == IS_CHARACTERS)
		return (get_char_arg(args, frmt, tmp_len));
	else if (check_is(frmt.specifier) == IS_UNSIGNED)
	{
		usign_arg = get_unsigned_arg(args, frmt.specifier, frmt.length);
		res_str = uintmaxtoa_base(usign_arg, base);
	}
	else if (check_is(frmt.specifier) == IS_SIGNED)
	{
		sign_arg = get_signed_arg(args, frmt.specifier, frmt.length);
		res_str = intmaxtoa_base(sign_arg, base);
	}
	else
		res_str = ft_strnew_c(1, frmt.specifier);
	*tmp_len = ft_strlen(res_str);
	return (res_str);
}

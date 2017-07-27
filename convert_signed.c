/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_signed.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonon <mgonon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/27 13:57:37 by mgonon            #+#    #+#             */
/*   Updated: 2017/07/27 14:42:41 by mgonon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static intmax_t	get_arg(va_list args, char specifier, t_length length)
{
	intmax_t output;

	if (length.l >= 2)
		output = (intmax_t)va_arg(args, long long);
	else if (length.l == 1 || specifier == 'D')
		output = (intmax_t)va_arg(args, long);
	else if (length.z >= 1)
		output = va_arg(args, ssize_t);
	else if (length.j >= 1)
		output = va_arg(args, intmax_t);
	else if (length.h >= 2)
		output = (intmax_t)(char)va_arg(args, int);
	else if (length.h == 1)
		output = (intmax_t)(short)va_arg(args, int);
	else
		output = (intmax_t)va_arg(args, int);
	return (output);
}

char			*convert_signed(va_list args, t_format frmt,
									int *size)
{
	intmax_t	arg;
	int			base;
	char		*s;

	arg = get_arg(args, frmt.specifier, frmt.length);
	base = get_base(frmt.specifier);
	s = ft_intmaxt_itoa_base(args, base);
	*size = ft_strlen(s);
	return (s);
}
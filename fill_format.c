/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   feed_format.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonon <mgonon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 04:11:46 by mgonon            #+#    #+#             */
/*   Updated: 2017/07/28 02:38:16 by mgonon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	get_flags(char const **format, t_format *frmt)
{
	while (check_is(**format) == IS_FLAG)
	{
		if (**format == '+')
			frmt->flags.plus = 1;
		else if (**format == '-')
			frmt->flags.minus = 1;
		else if (**format == ' ')
			frmt->flags.space = 1;
		else if (**format == '#')
			frmt->flags.sharp = 1;
		else if (**format == '0')
			frmt->flags.zero = 1;
		(*format)++;
	}
}

static void	get_width(char const **format, t_format *frmt, va_list args)
{
	if (ft_isdigit(**format))
	{
		frmt->width = ft_atoi(*format);
		while (ft_isdigit(**format))
			(*format)++;
	}
	else if (**format == '*')
	{
		(*format)++;
		frmt->width = va_arg(args, int);
		if (frmt->width < 0)
		{
			frmt->flags.minus = 1;
			frmt->width *= -1;
		}
	}
}

static void	get_precision(char const **format, t_format *frmt, va_list args)
{
	(*format)++;
	if (ft_isdigit(**format))
	{
		frmt->precision = ft_atoi(*format);
		while (ft_isdigit(**format))
			(*format)++;
	}
	else if (**format == '*')
	{
		(*format)++;
		frmt->precision = va_arg(args, int);
	}
	else
		frmt->precision = 0;	
}

static void	get_length(char const **format, t_format *frmt)
{
	while (check_is(**format) == IS_LENGTH)
	{
		if (**format == 'h')
			frmt->length.h++;
		else if (**format == 'l')
			frmt->length.l++;
		else if (**format == 'j')
			frmt->length.j = 1;
		else if (**format == 'z')
			frmt->length.z = 1;
		(*format)++;
	}
}

void	fill_format(char const **format, t_format *frmt, va_list args)
{
	while (check_is(**format) == IS_FLAG ||
		   check_is(**format) == IS_LENGTH ||
		   ft_isdigit(**format)
		   || **format == '*' || **format == '.')
	{
		if (check_is(**format) == IS_FLAG)
			get_flags(format, frmt);
		else if (ft_isdigit(**format) || **format == '*')
			get_width(format, frmt, args);
		else if (**format == '.')
			get_precision(format, frmt, args);
		else if (check_is(**format) == IS_LENGTH)
			get_length(format, frmt);
	}
	if (check_is(**format) == IS_SPECIFIER)
	{
		frmt->specifier = **format;
		(*format)++;
	}
	else
		// frmt->specifier = '\0';
		frmt->specifier = 'z';
	if (frmt->precision >= 0 && frmt->flags.zero)
		frmt->flags.zero = 0;
}
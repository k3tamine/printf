/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   feed_frmt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonon <mgonon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 04:11:46 by mgonon            #+#    #+#             */
/*   Updated: 2017/01/16 04:20:05 by mgonon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	get_flags(char const **format, t_format *frmt)
{
	while (is_flag(**format))
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

void	get_width(char const **format, t_format *frmt, va_list args)
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

void	get_precision(char const **format, t_format *frmt, va_list args)
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
	// else
	// 	frmt->precision = 0;	
}

void	get_length(char const **format, t_format *frmt)
{
	while (is_length(**format))
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
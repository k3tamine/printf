/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_unsigned.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonon <mgonon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/28 05:24:59 by mgonon            #+#    #+#             */
/*   Updated: 2017/08/17 19:12:47 by mgonon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	apply_zero_cases(char **res_str, int *size, t_format *frmt)
{
	int	i;

	i = 0;
	while ((*res_str)[i])
	{
		if (ft_isdigit((*res_str)[i]) == 0)
			return ;
		i++;
	}
	if (frmt->precision == 0)
	{
		**res_str = '\0';
		*size = 0;
	}
	if (frmt->specifier == 'x' || frmt->specifier == 'X')
		frmt->flags.sharp = 0;
}

static void	apply_sharp_flag(char **res_str, int *size, char id)
{
	if (id == 'o' || id == 'O')
	{
		if (**res_str == '0')
			return ;
		*res_str = ft_strjoin("0", *res_str);
		*size += 1;
	}
	else if (id == 'x' || id == 'X' || id == 'p')
	{
		*res_str = ft_strjoin("0x", *res_str);
		*size += 2;
	}
}

static void	apply_precision(char **res_str, int *size, t_format frmt)
{
	int		precision;
	char	*to_add;

	precision = frmt.precision;
	to_add = ft_strnew_c(precision - *size, '0');
	*res_str = ft_strjoin(to_add, *res_str);
	*size = precision;
	free(to_add);
}

static void	apply_width_nominus(char **res_str, int *size, t_format frmt)
{
	int		width;
	char	*to_add;

	width = frmt.width;
	if (frmt.flags.zero == 0 || frmt.precision > 0)
		to_add = ft_strnew_c(width - *size, ' ');
	else if (frmt.flags.sharp &&
			(frmt.specifier == 'x' || frmt.specifier == 'X' ||
			frmt.specifier == 'p'))
	{
		(*res_str) += 2;
		to_add = ft_strnew_c(width - *size + 2, '0');
		to_add[0] = '0';
		to_add[1] = 'x';
	}
	else
		to_add = ft_strnew_c(width - *size, '0');
	*res_str = ft_strjoin(to_add, *res_str);
	*size = width;
	free(to_add);
}

void		fill_unsigned(char **res_str, int *size, t_format frmt)
{
	if (frmt.precision > *size)
		apply_precision(res_str, size, frmt);
	if (ft_atoi(*res_str) == 0)
		apply_zero_cases(res_str, size, &frmt);
	if (frmt.flags.sharp)
		apply_sharp_flag(res_str, size, frmt.specifier);
	if (frmt.width > *size && !frmt.flags.minus)
		apply_width_nominus(res_str, size, frmt);
	if (frmt.width > *size && frmt.flags.minus)
		apply_width_minus(res_str, size, frmt.width);
	if (frmt.specifier == 'X')
		ft_strupper(*res_str);
}

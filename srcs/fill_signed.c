/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_signed.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonon <mgonon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/28 05:38:12 by mgonon            #+#    #+#             */
/*   Updated: 2017/08/16 17:32:34 by mgonon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	apply_plus_space_flag(char **data, int *size, t_flags flags)
{
	if (**data != '-')
	{
		if (flags.plus)
			*data = ft_strjoin("+", *data);
		else
			*data = ft_strjoin(" ", *data);
		*size += 1;
	}
}

static void	apply_precision(char **data, int *size, t_format frmt)
{
	int		precision;
	char	*to_add;

	precision = frmt.precision;
	if ((precision <= *size && **data != '-') || precision <= *size - 1)
		return ;
	if (**data != '-')
	{
		to_add = ft_strnew_c(precision - *size, '0');
		*size = precision;
	}
	else
	{
		(*data) += 1;
		to_add = ft_strnew_c(precision - *size + 2, '0');
		to_add[0] = '-';
		*size = precision + 1;
	}
	*data = ft_strjoin(to_add, *data);
	free(to_add);
}

static void	apply_width_nominus(char **data, int *size, t_format frmt)
{
	int		width;
	char	*to_add;

	width = frmt.width;
	if (frmt.flags.zero == 0 || frmt.precision >= 0)
		to_add = ft_strnew_c(width - *size, ' ');
	else if (**data != '-' && **data != ' ' && **data != '+')
		to_add = ft_strnew_c(width - *size, '0');
	else
	{
		to_add = ft_strnew_c(width - *size + 1, '0');
		to_add[0] = **data;
		(*data) += 1;
	}
	*data = ft_strjoin(to_add, *data);
	*size = width;
	free(to_add);
}

void		apply_width_minus(char **data, int *size, int width)
{
	char	*tmp;

	tmp = *data;
	*data = ft_strnew_c(width, ' ');
	ft_strncpy(*data, tmp, *size);
	*size = width;
	free(tmp);
}

void		fill_signed(char **data, int *size, t_format frmt)
{
	if (frmt.precision > 0)
		apply_precision(data, size, frmt);
	if (frmt.precision == 0 && ft_atoi(*data) == 0)
	{
		**data = '\0';
		*size = 0;
	}
	if ((frmt.flags.space || frmt.flags.plus))
		apply_plus_space_flag(data, size, frmt.flags);
	if (frmt.width > *size)
	{
		if (frmt.flags.minus)
			apply_width_minus(data, size, frmt.width);
		else
			apply_width_nominus(data, size, frmt);
	}
}

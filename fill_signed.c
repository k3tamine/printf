/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_signed.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonon <mgonon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/28 05:38:12 by mgonon            #+#    #+#             */
/*   Updated: 2017/07/28 08:41:45 by mgonon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	apply_plus_space_flag(char **data, int *size, t_flags flags)
{
	char *tmp;

	if (**data != '-')
	{
		tmp = *data;
		if (flags.plus)
			*data = ft_strjoin("+", *data);
		else
			*data = ft_strjoin(" ", *data);
		*size += 1;
		free(tmp);
	}
}

static void	apply_precision(char **data, int *size, t_format frmt)
{
	int		precision;
	char	*to_add;
	char	*tmp;

	precision = frmt.precision;
	if ((precision <= *size && **data != '-') || precision <= *size - 1)
		return ;
	tmp = *data;
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
	free(tmp);
	free(to_add);
}

static void	apply_width_nominus(char **data, int *size, t_format frmt)
{
	int		width;
	char	*to_add;
	char	*tmp;

	width = frmt.width;
	tmp = *data;
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
	free(tmp);
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
	if (frmt.width > *size && frmt.flags.minus == 0)
		apply_width_nominus(data, size, frmt);
	if (frmt.width > *size && frmt.flags.minus == 1)
		apply_width_minus(data, size, frmt.width);
}
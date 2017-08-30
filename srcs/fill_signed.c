/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_signed.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonon <mgonon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/28 05:38:12 by mgonon            #+#    #+#             */
/*   Updated: 2017/08/30 05:46:31 by mgonon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	apply_plus_space_flag(char **str, int *size, t_flags flags)
{
	if (**str != '-')
	{
		if (flags.plus)
			*str = ft_strjoin_free("+", *str, 2);
		else
			*str = ft_strjoin_free(" ", *str, 2);
		*size += 1;
	}
}

static void	apply_precision(char **str, int *size, t_format frmt)
{
	int		precision;
	char	*to_add;
	char	*tmp;

	precision = frmt.precision;
	if ((precision <= *size && **str != '-') || precision <= *size - 1)
		return ;
	if (**str != '-')
	{
		to_add = ft_strnew_c(precision - *size, '0');
		*size = precision;
	}
	else
	{
		tmp = *str;
		*str = ft_strdup(*str + 1);
		free(tmp);
		to_add = ft_strnew_c(precision - *size + 2, '0');
		to_add[0] = '-';
		*size = precision + 1;
	}
	*str = ft_strjoin_free(to_add, *str, 2);
	free(to_add);
}

static void	apply_width_nominus(char **str, int *size, t_format frmt)
{
	char	*to_add;
	char	*tmp;

	if (!frmt.flags.zero || frmt.precision >= 0)
		to_add = ft_strnew_c(frmt.width - *size, ' ');
	else if (**str != '-' && **str != ' ' && **str != '+')
		to_add = ft_strnew_c(frmt.width - *size, '0');
	else
	{
		to_add = ft_strnew_c(frmt.width - *size + 1, '0');
		to_add[0] = **str;
		tmp = *str;
		*str = ft_strdup(*str + 1);
		free(tmp);
	}
	*str = ft_strjoin_free(to_add, *str, 2);
	*size = frmt.width;
	free(to_add);
}

void		apply_width_minus(char **str, int *size, int width)
{
	char	*tmp;

	tmp = *str;
	*str = ft_strnew_c(width, ' ');
	ft_strncpy(*str, tmp, *size);
	*size = width;
	free(tmp);
}

void		fill_signed(char **str, int *size, t_format frmt)
{
	if (frmt.precision > 0)
		apply_precision(str, size, frmt);
	if (frmt.precision == 0 && ft_atoi(*str) == 0)
	{
		**str = '\0';
		*size = 0;
	}
	if ((frmt.flags.space || frmt.flags.plus))
		apply_plus_space_flag(str, size, frmt.flags);
	if (frmt.width > *size)
	{
		if (frmt.flags.minus)
			apply_width_minus(str, size, frmt.width);
		else
			apply_width_nominus(str, size, frmt);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_unsigned.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonon <mgonon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/28 05:24:59 by mgonon            #+#    #+#             */
/*   Updated: 2017/08/30 05:44:42 by mgonon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	apply_zero_cases(char **str, int *size, t_format *frmt)
{
	int	i;

	i = 0;
	while ((*str)[i])
	{
		if (ft_isdigit((*str)[i]) == 0)
			return ;
		i++;
	}
	if (frmt->precision == 0)
	{
		**str = '\0';
		*size = 0;
	}
	if (frmt->specifier == 'x' || frmt->specifier == 'X')
		frmt->flags.sharp = 0;
}

static void	apply_sharp_flag(char **str, int *size, char id)
{
	if (id == 'o' || id == 'O')
	{
		if (**str == '0')
			return ;
		*str = ft_strjoin_free("0", *str, 2);
		*size += 1;
	}
	else if (id == 'x' || id == 'X' || id == 'p')
	{
		*str = ft_strjoin_free("0x", *str, 2);
		*size += 2;
	}
}

static void	apply_precision(char **str, int *size, t_format frmt)
{
	char	*to_add;

	to_add = ft_strnew_c(frmt.precision - *size, '0');
	*str = ft_strjoin_free(to_add, *str, 2);
	*size = frmt.precision;
	free(to_add);
}

static void	apply_width_nominus(char **str, int *size, t_format frmt)
{
	char	*tmp;
	char	*to_add;

	if (frmt.flags.zero == 0 || frmt.precision > 0)
		to_add = ft_strnew_c(frmt.width - *size, ' ');
	else if (frmt.flags.sharp &&
			(frmt.specifier == 'x' || frmt.specifier == 'X' ||
										frmt.specifier == 'p'))
	{
		tmp = *str;
		*str = ft_strdup(*str + 2);
		free(tmp);
		to_add = ft_strnew_c(frmt.width - *size + 2, '0');
		to_add[0] = '0';
		to_add[1] = 'x';
	}
	else
		to_add = ft_strnew_c(frmt.width - *size, '0');
	*str = ft_strjoin_free(to_add, *str, 2);
	*size = frmt.width;
	free(to_add);
}

void		fill_unsigned(char **str, int *size, t_format frmt)
{
	if (frmt.precision > *size)
		apply_precision(str, size, frmt);
	if (ft_atoi(*str) == 0)
		apply_zero_cases(str, size, &frmt);
	if (frmt.flags.sharp)
		apply_sharp_flag(str, size, frmt.specifier);
	if (frmt.width > *size)
	{
		if (frmt.flags.minus)
			apply_width_minus(str, size, frmt.width);
		else
			apply_width_nominus(str, size, frmt);
	}
	if (frmt.specifier == 'X')
		ft_strupper(*str);
}

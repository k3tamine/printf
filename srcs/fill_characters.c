/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_characters.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonon <mgonon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/28 05:34:57 by mgonon            #+#    #+#             */
/*   Updated: 2017/08/24 02:57:45 by mgonon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	octets_to_print(char *str)
{
	char	octet;

	octet = *str;
	if ((octet & 128) == 0)
		return (1);
	if ((octet & 224) == 192)
		return (2);
	if ((octet & 240) == 224)
		return (3);
	if ((octet & 248) == 240)
		return (4);
	return (0);
}

static void	apply_precision(char **str, int *size, t_format frmt)
{
	int	to_print;
	int	i;

	if ((frmt.specifier == 'c' || frmt.specifier == 'C'))
		return ;
	if (frmt.specifier == 'S')
	{
		i = 0;
		to_print = 0;
		while (to_print + i <= frmt.precision)
		{
			to_print += i;
			i = octets_to_print(*str + to_print);
		}
		(*str)[to_print] = '\0';
		*size = to_print;
	}
	else
	{
		(*str)[frmt.precision] = '\0';
		*size = frmt.precision;
	}
}

static void	apply_width(char **str, int *size, t_format frmt)
{
	char	*to_add;

	if (frmt.width > *size)
	{
		if (!frmt.flags.zero || frmt.flags.minus)
			to_add = ft_strnew_c(frmt.width - *size, ' ');
		else
			to_add = ft_strnew_c(frmt.width - *size, '0');
		if (to_add == NULL)
			return ;
		if (!frmt.flags.minus && frmt.specifier == 'c')
			*str = ft_strnjoin(to_add, *str, 1);
		else if (!frmt.flags.minus)
			*str = ft_strjoin(to_add, *str);
		else if (frmt.specifier == 'c')
			*str = ft_strnjoin(*str, to_add, 1);
		else
			*str = ft_strjoin(*str, to_add);
		*size = frmt.width;
		free(to_add);
	}
}

void		fill_characters(char **str, int *size,
							t_format frmt)
{
	if (frmt.precision > -1 && frmt.precision < *size)
		apply_precision(str, size, frmt);
	if (frmt.width > 0)
		apply_width(str, size, frmt);
}

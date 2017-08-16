/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_characters.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonon <mgonon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/28 05:34:57 by mgonon            #+#    #+#             */
/*   Updated: 2017/08/16 17:32:28 by mgonon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	octets_to_print(char *str)
{
	char	octet;

	octet = *str;
	// printf("LA octet = %c\n", octet);
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

static void	apply_precision(char **data, int *size, t_format frmt)
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
			i = octets_to_print(*data + to_print);
		}
		(*data)[to_print] = '\0';
		*size = to_print;
	}
	else
	{
		(*data)[frmt.precision] = '\0';
		*size = frmt.precision;
	}
}

// static void	apply_width(char **data, int *size, t_format frmt)
// {
// 	int		width;
// 	char	*tmp;

// 	width = frmt.width;
// 	if (width > *size)
// 	{
// 		tmp = *data;
// 		if (!frmt.flags.zero || frmt.flags.minus)
// 			*data = ft_strnew_c(width, ' ');
// 		else
// 			*data = ft_strnew_c(width, '0');
// 		if (!frmt.flags.minus)
// 			ft_strncpy(*data + width - *size, tmp, *size);
// 		else
// 			ft_strncpy(*data, tmp, *size);
// 		*size = width;
// 		free(tmp);
// 	}
// }

static void		apply_width(char **data, int *size, t_format frmt)
{
	int		width;
	char	*to_add;

	width = frmt.width;
	if (width > *size)
	{
		if (!frmt.flags.zero || frmt.flags.minus)
			to_add = ft_strnew_c(width - *size, ' ');
		else
			to_add = ft_strnew_c(width - *size, '0');
		if (to_add == NULL)
			return ;
		if (!frmt.flags.minus)
			*data = ft_strjoin(to_add, *data);
		else
			*data = ft_strjoin(*data, to_add);
		*size = width;
		free(to_add);
	}
}

void		fill_characters(char **data, int *size,
							t_format frmt)
{
	if (frmt.precision > -1 && frmt.precision < *size)
		apply_precision(data, size, frmt);
	if (frmt.width > 0)
		apply_width(data, size, frmt);
}
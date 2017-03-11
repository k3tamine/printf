/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_di.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonon <mgonon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 23:46:34 by mgonon            #+#    #+#             */
/*   Updated: 2017/03/02 18:53:00 by mgonon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	apply_precision(int precision, int size, int nb)
{
	char	buf[4096];
	int		ret;
	int		i;

	ret = precision - size;
	i = -1;
	if (nb < 0)
		size--;
	if (precision <= size)
		return (0);
	while (++i < precision - size)
		buf[i] = '0';
	write(1, buf, precision - size);
	return (ret);
}

static int	apply_width(int width, int size, int len, char c)
{
	char	buf[4096];
	int		ret;
	int		i;

	if (size < len)
		size = len;
	i = -1;
	if (width <= size)
		return (0);
	while (++i < width - size)
		buf[i] = c;
	write(1, buf, width - size);
	return (width - size);
}

static int	apply_classic(int nb, int len, char *buf, t_format *frmt)
{
	int		add_len;
	int		i;

	i = 0;
	add_len = 0;
	if (nb < 0)
		i = 1;
	if (frmt->flags.space && !frmt->flags.plus && nb >= 0 && (++add_len))
		write(1, " ", 1);
	if (!frmt->flags.zero)
	{
		if (!frmt->flags.plus)
			add_len += frmt->flags.minus ? 0
				: apply_width(frmt->width, frmt->precision + i, len, ' ');
		else
			add_len += frmt->flags.minus ? 0
				: apply_width(frmt->width - 1, frmt->precision, len, ' ');
	}
	if (frmt->flags.plus && nb >= 0 && (++add_len))
		write(1, "+", 1);
	else if (nb < 0)
		write(1, "-", 1);
	if (nb < 0 && frmt->precision > 0 && !frmt->width)
		add_len++;
	if (frmt->flags.zero)
		add_len += frmt->flags.minus ? apply_precision(frmt->precision, len, nb)
			: apply_width(frmt->width, frmt->precision, add_len + len, '0');
	else
		add_len += apply_precision(frmt->precision, len, nb);
	write(1, buf + i, len - i);
	add_len += frmt->flags.minus ?
		apply_width(frmt->width, add_len + len, len, ' ') : 0;
	return (add_len);
}

int	handle_di(int nb, char *buf, t_format *frmt)
{
	int		i;
	int		len;
	char	tmp;

	i = -1;
	len = 0;
	if (nb != 0 || (frmt->width == 0 && frmt->precision == -1))
	{
		// printf("\n\n nb = %lld\n\n", (unsigned long long)nb);
		if (ft_strchr("diu", frmt->specifier))
			len = ft_itoa_base_buf(nb, 10, buf);
		else if (ft_strchr("o", frmt->specifier))
			len = ft_itoa_base_buf(nb, 8, buf);
		else if (ft_strchr("xX", frmt->specifier))
			len = ft_itoa_base_buf(nb, 16, buf);
	}
	else
		buf[0] = '\0';
	len += apply_classic(nb, len, buf, frmt);
	return (len);
}

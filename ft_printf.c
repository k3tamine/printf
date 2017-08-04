/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonon <mgonon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 12:47:48 by mgonon            #+#    #+#             */
/*   Updated: 2017/08/04 13:21:10 by mgonon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// static const t_conv g_conv[] = {
// 	{ "dDiuUoOxXp", fill_unsigned }
// 	//{ "%", toto_limit}
// };

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

static void		fill_str_res(char **res_str, int *tmp_len, t_format frmt)
{
	if (check_is(frmt.specifier) == IS_UNSIGNED)
		fill_unsigned(res_str, tmp_len, frmt);
	else if (check_is(frmt.specifier) == IS_SIGNED)
		fill_signed(res_str, tmp_len, frmt);
	else if (check_is(frmt.specifier) == IS_CHARACTERS)
		fill_characters(res_str, tmp_len, frmt);
	else
	{
		if (frmt.width > 0)
			apply_width(res_str, tmp_len, frmt);
	}
}

static char		*get_result_str(const char **format,
								va_list args, int *tmp_len, int full_len)
{
	t_format	frmt;
	char		*res_str;

	init_format(&frmt);
	fill_format(format, &frmt, args);
	res_str = get_str_arg(args, frmt, tmp_len);
	if (res_str)
		fill_str_res(&res_str, tmp_len, frmt);
	return (res_str);
}

static int		put_n_str(const char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '%')
		i++;
	write(1, str, i);
	return (i);
}

int				ft_printf(const char *format, ...)
{
	int			full_len;
	int			tmp_len;
	char		*res_str;
	int			len_test;
	va_list		args;

	len_test = 0;
	full_len = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format != '%')
		{
			// put_n_str(format);
			// len_test = put_n_str(format);
			// format += len_test;
			// full_len += len_test;
			ft_putchar(*format++);
		}
		else
		{
			format++;
			if (!(res_str = get_result_str(&format, args, &tmp_len, full_len)))
				return (-1);
			write(1, res_str, tmp_len);
			full_len += tmp_len - 1;
			free(res_str);
		}
		full_len++;
	}
	va_end(args);
	return (full_len);
}

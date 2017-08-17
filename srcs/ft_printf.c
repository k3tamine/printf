/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonon <mgonon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 12:47:48 by mgonon            #+#    #+#             */
/*   Updated: 2017/08/17 19:05:47 by mgonon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static const t_conv g_conv[] = {
	{ "oOxXuUp", fill_unsigned },
	{ "dDi", fill_signed},
	{ "cCsS", fill_characters}
};

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
	int	i;

	i = -1;
	while (++i < 3)
	{
		if (ft_strchr(g_conv[i].specifier, frmt.specifier))
		{
			g_conv[i].fill_str(res_str, tmp_len, frmt);
			break ;
		}
	}
	if (i == 3 && frmt.width > 0)
		apply_width(res_str, tmp_len, frmt);
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

static void		buf_handler(char *buf, char c, int *i, int print)
{
	if (!print && *i < B_SIZE && c != '\n')
	{
		buf[*i] = c;
		(*i)++;
	}
	else
	{
		write(1, buf, *i);
		*i = 0;
		if (!print)
		{
			buf[*i] = c;
			(*i)++;
		}
	}
}

int				ft_printf(const char *format, ...)
{
	char		*res_str;
	t_norme		n;
	va_list		args;

	n.i = 0;
	n.f_len = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format != '%')
			buf_handler(n.buf, *format++, &(n.i), 0);
		else
		{
			buf_handler(n.buf, *format++, &(n.i), 1);
			if (!(res_str = get_result_str(&format, args, &(n.t_len), n.f_len)))
				return (-1);
			write(1, res_str, n.t_len);
			n.f_len += n.t_len - 1;
			free(res_str);
		}
		(n.f_len)++;
	}
	buf_handler(n.buf, *format, &(n.i), 1);
	va_end(args);
	return (n.f_len);
}

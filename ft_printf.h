/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonon <mgonon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 00:44:49 by mgonon            #+#    #+#             */
/*   Updated: 2017/03/16 13:10:42 by mgonon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>
# include <wchar.h>
# include "libft/libft.h"

typedef struct		s_flags
{
	int	minus;
	int	plus;
	int	space;
	int	sharp;
	int	zero;
}					t_flags;

typedef struct		s_length
{
	int	l;
	int	h;
	int	j;
	int	z;
}					t_length;

typedef struct	s_format
{
	t_flags		flags;
	int			width;
	int			precision;
	t_length	length;
	char		specifier;
}				t_format;

typedef struct	s_conv
{
	char	*specifier;
	int		(*handle)(intmax_t, char *, t_format *);
}				t_conv;

int			is_flag(char c);
int			is_length(char c);
int			is_specifier(char c);
void		init_format(t_format *frmt);
void		get_flags(char const **format, t_format *frmt);
void		get_width(char const **format, t_format *frmt, va_list args);
void		get_precision(char const **format, t_format *frmt, va_list args);
void		get_length(char const **format, t_format *frmt);
void		get_format(char const **format, t_format *frmt, va_list args);
int			get_result_str(const char **format, va_list args, t_format *frmt);
int			ft_itoa_base_buf(intmax_t n, int base, char *res);
int			ft_uitoa_base_buf(uintmax_t n, int base, char *res, int b_type);
int			handle_di(intmax_t nb, char *buf, t_format *frmt);
int			ft_printf(const char *format, ...);
int			is_signed(char c);
int			is_unsigned(char c);
int			is_characters(char c);
intmax_t	get_signed_arg(va_list args, char id, t_length length);
uintmax_t	get_unsigned_arg(va_list args, char speci, t_length length);
int			apply_precision(int precision, int size, intmax_t nb);
int			apply_width(int width, int size, int len, char c);
int			handle_s(char *str, t_format *frmt);
int			handle_c(char c, t_format *frmt);

#endif

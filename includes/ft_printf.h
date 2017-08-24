/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonon <mgonon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 00:44:49 by mgonon            #+#    #+#             */
/*   Updated: 2017/08/24 02:18:41 by mgonon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define IS_FLAG 1
# define IS_LENGTH 2
# define IS_UNSIGNED 3
# define IS_SIGNED 4
# define IS_CHARACTERS 5
# define B_SIZE	4096
# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <wchar.h>
# include <limits.h>
# include "../libft/libft.h"

typedef struct	s_flags
{
	int	minus;
	int	plus;
	int	space;
	int	sharp;
	int	zero;
}				t_flags;

typedef struct	s_length
{
	int	l;
	int	h;
	int	j;
	int	z;
}				t_length;

typedef struct	s_format
{
	t_flags		flags;
	t_length	length;
	int			width;
	int			precision;
	char		specifier;
}				t_format;

typedef struct	s_conv
{
	const char	*specifier;
	void		(*fill_str)(char **, int *, t_format);
}				t_conv;

typedef struct	s_norme
{
	char	buf[B_SIZE];
	int		i;
	int		f_len;
	int		t_len;
}				t_norme;

int				ft_printf(const char *format, ...);
void			fill_format(char const **format, t_format *frmt, va_list args);
int				check_is(char c);
int				get_base(char specifier);
char			*get_str_arg(va_list args, t_format frmt, int *tmp_len);
char			*intmaxtoa_base(intmax_t value, int base);
char			*uintmaxtoa_base(uintmax_t value, int base);
char			*get_unicode_str(wchar_t *unicode_str);
char			*get_char_arg(va_list args, t_format frmt, int *tmp_len);
void			fill_unsigned(char **res_str, int *tmp_len, t_format frmt);
void			fill_signed(char **res_str, int *tmp_len, t_format frmt);
void			fill_characters(char **res_str, int *tmp_len, t_format frmt);
void			apply_width_minus(char **data, int *size, int width);
char			*get_unicode_char(wint_t unicode_c);

#endif

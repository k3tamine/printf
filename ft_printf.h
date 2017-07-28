/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonon <mgonon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 00:44:49 by mgonon            #+#    #+#             */
/*   Updated: 2017/07/28 04:18:45 by mgonon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define IS_FLAG 1
# define IS_LENGTH 2
# define IS_SPECIFIER 3
# define IS_UNSIGNED 4
# define IS_SIGNED 5
# define IS_CHARACTERS 6
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

typedef struct		s_format
{
	t_flags		flags;
	t_length	length;
	int			width;
	int			precision;
	char		specifier;
}					t_format;

typedef struct		s_conv
{
	char	*specifier;
	int		(*handle)(intmax_t, char *, t_format *);
}					t_conv;

void	fill_format(char const **format, t_format *frmt, va_list args);
int		check_is(char c);
int		get_base(char specifier);
void	init_format(t_format *frmt);
char	*get_str_arg(va_list args, t_format frmt, int *tmp_len);
char	*ft_sign_itoa_base(intmax_t value, int base);
char	*ft_usign_itoa_base(uintmax_t value, int base);
char	*get_unicode_str(wchar_t *unicode_str);
//TODEL
char	*get_unicode_char(wint_t unicode_c);
char	*get_char_arg(va_list args, t_format frmt, int *tmp_len);



#endif

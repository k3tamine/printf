/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonon <mgonon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 00:44:49 by mgonon            #+#    #+#             */
/*   Updated: 2017/02/12 10:01:10 by mgonon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include "libft/libft.h"

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
	int		(*handle)(int, char *, t_format *);
}				t_conv;

int		is_flag(char c);
int		is_length(char c);
int		is_specifier(char c);
void	get_flags(char const **format, t_format *frmt);
void	get_width(char const **format, t_format *frmt, va_list args);
void	get_precision(char const **format, t_format *frmt, va_list args);
void	get_length(char const **format, t_format *frmt);
int		ft_itoa_base_buf(int n, int base, char *res);
int		handle_d(int nb, char *buf, t_format *frmt);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonon <mgonon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 00:44:49 by mgonon            #+#    #+#             */
/*   Updated: 2017/07/27 14:39:13 by mgonon           ###   ########.fr       */
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

int	is_characters(char c);
int	is_signed(char c);
int	is_unsigned(char c);
int	is_flag(char c);
int	is_length(char c);
int	is_specifier(char c);
int	get_base(char specifier);

#endif

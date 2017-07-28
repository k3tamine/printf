/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonon <mgonon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 12:47:48 by mgonon            #+#    #+#             */
/*   Updated: 2017/07/28 04:19:00 by mgonon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// static const t_conv g_conv[] = {
// 	{ "dDiuUoOxXp", handle_di }
// 	//{ "%", toto_limit}
// };

intmax_t	get_arg(t_format frmt, va_list args)
{
	intmax_t	arg;

	if (check_is(frmt.specifier) == IS_SIGNED)
		arg = get_signed_arg(args, frmt.specifier, frmt.length);
	else if (check_is(frmt.specifier) == IS_SIGNED)
		arg = get_unsigned_arg(args, frmt.specifier, frmt.length);
	return (arg);
}

static void	apply_width(char **data, int *size, t_format frmt)
{
	int		width;
	char	*to_add;
	char	*tmp;

	width = frmt.width;
	if (width > *size)
	{
		tmp = *data;
		if (frmt.flags.zero == 0 || frmt.flags.minus == 1)
			to_add = ft_strnew_c(width - *size, ' ');
		else
			to_add = ft_strnew_c(width - *size, '0');
		if (to_add == NULL)
			return ;
		if (frmt.flags.minus)
			*data = ft_strjoin(*data, to_add);
		else
			*data = ft_strjoin(to_add, *data);
		*size = width;
		free(tmp);
		free(to_add);
	}
}

// void		ftpf_process_data(char **data, int *size, t_format frmt)
// {
// 	if (ftpf_is_unsigned_conv(frmt.specifier))
// 		ftpf_process_unsigned(data, size, frmt);
// 	else if (ftpf_is_signed_conv(frmt.specifier))
// 		ftpf_process_signed(data, size, frmt);
// 	else if (ftpf_is_characters_conv(frmt.specifier))
// 		ftpf_process_characters(data, size, frmt);
// 	else
// 	{
// 		if (frmt.width > 0)
// 			apply_width(data, size, frmt);
// 	}
// }

static char	*get_result_str(const char **format, va_list args, int *tmp_len, int full_len)
{
	t_format	frmt;
	char		*res_str;

	init_format(&frmt);
	fill_format(format, &frmt, args);
	res_str = get_str_arg(args, frmt, tmp_len);
	if (res_str)
		fill_str(&res_str, tmp_len, full_len);
	return (res_str);
}

int		put_n_str(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '%')
		i++;
	write(1, str, i);
	return (i);
}

int			ft_printf(const char *format, ...)
{
	int			full_len;
	int			tmp_len;
	char		*res_str;
	va_list		args;

	full_len = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format != '%')
			ft_putchar(*format++);
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


// int	main()
// {
	// // ft_printf("ft_printf .10d, 12345 = %.10d\n", 12345);
	// // printf("printf 10.10d, 12345 = %.10d\n", 12345);
	// // ft_printf("toto %.10d eogiwhod %32d", 12, 24);


  /* Verification des decimals, %i et %d */

//   ft_printf("%d\n", ft_printf("1chiffre 1 %d chiffre 2 %d\n", 42, -42));
//   printf("%d\n", printf("1chiffre 1 %d chiffre 2 %d\n", 42, -42));

//   ft_printf("%d\n", ft_printf("2chiffre 1 %   d chiffre 2 % d\n", 42, -42));
//   printf("%d\n", printf("2chiffre 1 %   d chiffre 2 % d\n", 42, -42));

//   ft_printf("%d\n", ft_printf("3chiffre 1 %12d chiffre 2 %12d\n", 42, -42));
//   printf("%d\n", printf("3chiffre 1 %12d chiffre 2 %12d\n", 42, -42));

//   ft_printf("%d\n", ft_printf("4chiffre 1 %-12d chiffre 2 %-12d\n", 42, -42));
//   printf("%d\n", printf("4chiffre 1 %-12d chiffre 2 %-12d\n", 42, -42));

//   ft_printf("%d\n", ft_printf("5chiffre 1 %0d chiffre 2 %0d\n", 42, -42));
//   printf("%d\n", printf("5chiffre 1 %0d chiffre 2 %0d\n", 42, -42));

//   ft_printf("%d\n", ft_printf("6chiffre 1 %012d chiffre 2 %012d\n", 42, -42));
//   printf("%d\n", printf("6chiffre 1 %012d chiffre 2 %012d\n", 42, -42));

//   ft_printf("%d\n", ft_printf("7chiffre 1 %-012d chiffre 2 %012d\n", 42, -42));
//   printf("%d\n", printf("7chiffre 1 %-012d chiffre 2 %012d\n", 42, -42));

//   ft_printf("%d\n", ft_printf("8chiffre 1 %*d chiffre 2 %*d\n", 42, 6, 6, 6));
//   printf("%d\n", printf("8chiffre 1 %*d chiffre 2 %*d\n", 42, 6, 6, 6));

//   ft_printf("%d\n", ft_printf("9chiffre 1 %+d chiffre 2 %+d\n", 42, 6, -42, 6));
//   printf("%d\n", printf("9chiffre 1 %+d chiffre 2 %+d\n", 42, 6, -42, 6));

//   ft_printf("%d\n", ft_printf("10chiffre 1 %+12d chiffre 2 %+12d\n", 42, 6, -42, 6));
//   printf("%d\n", printf("10chiffre 1 %+12d chiffre 2 %+12d\n", 42, 6, -42, 6));

//   ft_printf("%d\n", ft_printf("11chiffre 1 %*12d chiffre 2 %*12d\n", 42, -6, 42, 6));
//   printf("%d\n", printf("11chiffre 1 %*12d chiffre 2 %*12d\n", 42, -6, 42, 6));
  
//   ft_printf("%d\n", ft_printf("12chiffre 1 %-+5d chiffre 2 %-+5d\n", 42, -42));
//   printf("%d\n", printf("12chiffre 1 %-+5d chiffre 2 %-+5d\n", 42, -42));  

//   ft_printf("%d\n", ft_printf("13chiffre 1 %-+05d chiffre 2 %-+05d\n", 42, -42));
//   printf("%d\n", printf("13chiffre 1 %-+05d chiffre 2 %-+05d\n", 42, -42));

//   ft_printf("%d\n", ft_printf("14chiffre 1 %+-5d chiffre 2 %+-5d\n", 42, -42));
//   printf("%d\n", printf("14chiffre 1 %+-5d chiffre 2 %+-5d\n", 42, -42));

//   ft_printf("%d\n", ft_printf("15chiffre 1 %.d chiffre 2 %.d\n", 42, -42));
//   printf("%d\n", printf("15chiffre 1 %.d chiffre 2 %.d\n", 42, -42));

//   ft_printf("%d\n", ft_printf("16chiffre 1 %.6d chiffre 2 %.6d\n", 42, -42));
//   printf("%d\n", printf("16chiffre 1 %.6d chiffre 2 %.6d\n", 42, -42));

//   ft_printf("%d\n", ft_printf("16chiffre 1 %.8d chiffre 2 %.8d\n", -442, -42));
//   printf("%d\n", printf("16chiffre 1 %.8d chiffre 2 %.8d\n", -442, -42));

//   	ft_printf("1chiffre 1 %-010.5d chiffre 2 %-010.5d\n", 42, -42);
//   printf("1chiffre 1 %-010.5d chiffre 2 %-010.5d\n", 42, -42);

//   	ft_printf("2chiffre 1 %010.5d chiffre 2 %010.5d\n", 42, -42);
//   printf("2chiffre 1 %010.5d chiffre 2 %010.5d\n", 42, -42);

//  	ft_printf("2chiffre 1 % d chiffre 2 % d\n", 42, -42);
//   printf("2chiffre 1 % d chiffre 2 % d\n", 42, -42);

//  	ft_printf("3chiffre 1 %12d chiffre 2 %12d\n", 42, -42);
//   printf("3chiffre 1 %12d chiffre 2 %12d\n", 42, -42);

//  	ft_printf("4chiffre 1 %-012d chiffre 2 %-012d\n", 42, -42);
//   printf("4chiffre 1 %-012d chiffre 2 %-012d\n", 42, -42);

//  	ft_printf("5chiffre 1 %010d chiffre 2 %010d\n", 42, -42);
//   printf("5chiffre 1 %010d chiffre 2 %010d\n", 42, -42);

//  	ft_printf("6chiffre 1 %012d chiffre 2 %012d\n", 42, -42);
//   printf("6chiffre 1 %012d chiffre 2 %012d\n", 42, -42);

//  	ft_printf("7chiffre 1 %-012d chiffre 2 %012d\n", 42, -42);
//   printf("7chiffre 1 %-012d chiffre 2 %012d\n", 42, -42);

//  	ft_printf("8chiffre 1 %*d chiffre 2 %*d\n", 42, 6, 6, 6);
//   printf("8chiffre 1 %*d chiffre 2 %*d\n", 42, 6, 6, 6);

//  	ft_printf("9chiffre 1 %+d chiffre 2 %+d\n", 42, 6, -42, 6);
//   printf("9chiffre 1 %+d chiffre 2 %+d\n", 42, 6, -42, 6);

//  	ft_printf("10chiffre 1 %+12d chiffre 2 %+12d\n", 42, 6, -42, 6);
//   printf("10chiffre 1 %+12d chiffre 2 %+12d\n", 42, 6, -42, 6);

//  	ft_printf("11chiffre 1 %*12d chiffre 2 %*12d\n", 42, -6, 42, 6);
//   printf("11chiffre 1 %*12d chiffre 2 %*12d\n", 42, -6, 42, 6);
  
//  	ft_printf("12chiffre 1 %-+5d chiffre 2 %-+5d\n", 42, -42);
//   printf("12chiffre 1 %-+5d chiffre 2 %-+5d\n", 42, -42);  

//  	ft_printf("13chiffre 1 %-+05d chiffre 2 %-+05d\n", 42, -42);
//   printf("13chiffre 1 %-+05d chiffre 2 %-+05d\n", 42, -42);

//  	ft_printf("14chiffre 1 %+-5d chiffre 2 %+-5d\n", 42, -42);
//   printf("14chiffre 1 %+-5d chiffre 2 %+-5d\n", 42, -42);

//  	ft_printf("15chiffre 1 %.d chiffre 2 %.d\n", 42, -42);
//   printf("15chiffre 1 %.d chiffre 2 %.d\n", 42, -42);

//  	ft_printf("16chiffre 1 %.6d chiffre 2 %.6d\n\n\n", 42, -42);
//   printf("16chiffre 1 %.6d chiffre 2 %.6d\n", 42, -42);




















	
// 	int	ret;

// 	// test for %d 0; //
// 	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n          test for %%d 0;\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");

// 	printf("------------------------------------\n");
// 	ret = printf("{%d}\n", 0);
// 	printf("%35s%d\n", "printf('%d', 0) ret : ", ret);
// 	ret = ft_printf("{%d}\n", 0);
// 	printf("%35s%d\n", "ft_printf('%d', 0) ret : ", ret);
// 	printf("------------------------------------\n");

// 	ret = printf("{%+d}\n", 0);
// 	printf("%35s%d\n", "printf('%+d', 0) ret : ", ret);
// 	ret = ft_printf("{%+d}\n", 0);
// 	printf("%35s%d\n", "ft_printf('%+d', 0) ret : ", ret);
// 	printf("------------------------------------\n");

// 	ret = printf("{%.d}\n", 0);
// 	printf("%35s%d\n", "printf('%.d', 0) ret : ", ret);
// 	ret = ft_printf("{%.d}\n", 0);
// 	printf("%35s%d\n", "ft_printf('%.d', 0) ret : ", ret);
// 	printf("------------------------------------\n");

// 	ret = printf("{%.5d}\n", 0);
// 	printf("%35s%d\n", "printf('%.5d', 0) ret : ", ret);
// 	ret = ft_printf("{%.5d}\n", 0);
// 	printf("%35s%d\n", "ft_printf('%.5d', 0) ret : ", ret);
// 	printf("------------------------------------\n");

// 	ret = printf("{%.0d}\n", 0);
// 	printf("%35s%d\n", "printf('%.0d', 0) ret : ", ret);
// 	ret = ft_printf("{%.0d}\n", 0);
// 	printf("%35s%d\n", "ft_printf('%.0d', 0) ret : ", ret);
// 	printf("------------------------------------\n");

// 	ret = printf("{%5.d}\n", 0);
// 	printf("%35s%d\n", "printf('%5.d', 0) ret : ", ret);
// 	ret = ft_printf("{%5.d}\n", 0);
// 	printf("%35s%d\n", "ft_printf('%5.d', 0) ret : ", ret);
// 	printf("------------------------------------\n");

// 	ret = printf("{%5.5d}\n", 0);
// 	printf("%35s%d\n", "printf('%5.5d', 0) ret : ", ret);
// 	ret = ft_printf("{%5.5d}\n", 0);
// 	printf("%35s%d\n", "ft_printf('%5.5d', 0) ret : ", ret);
// 	printf("------------------------------------\n");

// 	ret = printf("{%3.5d}\n", 0);
// 	printf("%35s%d\n", "printf('%3.5d', 0) ret : ", ret);
// 	ret = ft_printf("{%3.5d}\n", 0);
// 	printf("%35s%d\n", "ft_printf('%3.5d', 0) ret : ", ret);
// 	printf("------------------------------------\n");

// 	ret = printf("{%5.3d}\n", 0);
// 	printf("%35s%d\n", "printf('%5.3d', 0) ret : ", ret);
// 	ret = ft_printf("{%5.3d}\n", 0);
// 	printf("%35s%d\n", "ft_printf('%5.3d', 0) ret : ", ret);
// 	printf("------------------------------------\n");

// 	ret = printf("{%+010.d}\n", 0);
// 	printf("%35s%d\n", "printf('%+010.d', 0) ret : ", ret);
// 	ret = ft_printf("{%+010.d}\n", 0);
// 	printf("%35s%d\n", "ft_printf('%+010.d', 0) ret : ", ret);
// 	printf("------------------------------------\n");

// 	ret = printf("{%+010.5d}\n", 0);
// 	printf("%35s%d\n", "printf('% 010.5d', 0) ret : ", ret);
// 	ret = ft_printf("{%+010.5d}\n", 0);
// 	printf("%35s%d\n", "ft_printf('% 010.5d', 0) ret : ", ret);
// 	printf("------------------------------------\n");

// 	ret = printf("{% .d}\n", 0);
// 	printf("%35s%d\n", "printf('% .d', 0) ret : ", ret);
// 	ret = ft_printf("{% .d}\n", 0);
// 	printf("%35s%d\n", "ft_printf('% .d', 0) ret : ", ret);
// 	printf("------------------------------------\n");

// 	ret = printf("{%+.d}\n", 0);
// 	printf("%35s%d\n", "printf('%+.d', 0) ret : ", ret);
// 	ret = ft_printf("{%+.d}\n", 0);
// 	printf("%35s%d\n", "ft_printf('%+.d', 0) ret : ", ret);
// 	printf("------------------------------------\n");

// 	ret = printf("{%3.2d}\n", 0);
// 	printf("%35s%d\n", "printf('%3.2d', 0) ret : ", ret);
// 	ret = ft_printf("{%3.2d}\n", 0);
// 	printf("%35s%d\n", "ft_printf('%3.2d', 0) ret : ", ret);
// 	printf("------------------------------------\n");

// 	ret = printf("{%-3.2d}\n", 0);
// 	printf("%35s%d\n", "printf('%-3.2d', 0) ret : ", ret);
// 	ret = ft_printf("{%-3.2d}\n", 0);
// 	printf("%35s%d\n", "ft_printf('%-3.2d', 0) ret : ", ret);
// 	printf("------------------------------------\n");

// 	// test for %d 1; //
// 	ret = printf("{%+010.d}\n", 1);
// 	printf("%35s%d\n", "printf('%+010.d', 1) ret : ", ret);
// 	ret = ft_printf("{%+010.d}\n", 1);
// 	printf("%35s%d\n", "ft_printf('%+010.d', 1) ret : ", ret);
// 	printf("------------------------------------\n");

// 	ret = printf("{%+010.0d}\n", 1);
// 	printf("%35s%d\n", "printf('%+010.0d', 1) ret : ", ret);
// 	ret = ft_printf("{%+010.0d}\n", 1);
// 	printf("%35s%d\n", "ft_printf('%+010.0d', 1) ret : ", ret);
// 	printf("------------------------------------\n");

// 	ret = printf("{%+10d}\n", 1);
// 	printf("%35s%d\n", "printf('%+10d', 1) ret : ", ret);
// 	ret = ft_printf("{%+10d}\n", 1);
// 	printf("%35s%d\n", "ft_printf('%+10d', 1) ret : ", ret);
// 	printf("------------------------------------\n");

// 	ret = printf("{%+010.5d}\n", 1);
// 	printf("%35s%d\n", "printf('%+010.5d', 1) ret : ", ret);
// 	ret = ft_printf("{%+010.5d}\n", 1);
// 	printf("%35s%d\n", "ft_printf('%+010.5d', 1) ret : ", ret);
// 	printf("------------------------------------\n");

// 	ret = printf("{%d}\n", -1);
// 	printf("%35s%d\n", "printf('%d', -1) ret : ", ret);
// 	ret = ft_printf("{%d}\n", -1);
// 	printf("%35s%d\n", "ft_printf('%d', -1) ret : ", ret);
// 	printf("------------------------------------\n");

// 	// test for %d 42; //
// 	printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n          test for %%d 42;\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");

// 	printf("------------------------------------\n");
// 	ret = printf("{%5d}\n", 42);
// 	printf("%35s%d\n", "printf('%5d', 42) ret : ", ret);
// 	ret = ft_printf("{%5d}\n", 42);
// 	printf("%35s%d\n", "ft_printf('%5d', 42) ret : ", ret);
// 	printf("------------------------------------\n");

// 	ret = printf("{%05d}\n", 42);
// 	printf("%35s%d\n", "printf('%05d', 42) ret : ", ret);
// 	ret = ft_printf("{%05d}\n", 42);
// 	printf("%35s%d\n", "ft_printf('%05d', 42) ret : ", ret);
// 	printf("------------------------------------\n");

// 	ret = printf("{%0+5d}\n", 42);
// 	printf("%35s%d\n", "printf('%0+5d', 42) ret : ", ret);
// 	ret = ft_printf("{%0+5d}\n", 42);
// 	printf("%35s%d\n", "ft_printf('%0+5d', 42) ret : ", ret);
// 	printf("------------------------------------\n");

// 	ret = printf("{%5d}\n", -42);
// 	printf("%35s%d\n", "printf('%5d', -42) ret : ", ret);
// 	ret = ft_printf("{%5d}\n", -42);
// 	printf("%35s%d\n", "ft_printf('%5d', -42) ret : ", ret);
// 	printf("------------------------------------\n");

// 	ret = printf("{%05d}\n", -42);
// 	printf("%35s%d\n", "printf('%05d', -42) ret : ", ret);
// 	ret = ft_printf("{%05d}\n", -42);
// 	printf("%35s%d\n", "ft_printf('%05d', -42) ret : ", ret);
// 	printf("------------------------------------\n");

// 	ret = printf("{%-05d}\n", -42);
// 	printf("%35s%d\n", "printf('%-05d', -42) ret : ", ret);
// 	ret = ft_printf("{%-05d}\n", -42);
// 	printf("%35s%d\n", "ft_printf('%-05d', -42) ret : ", ret);
// 	printf("------------------------------------\n");

// 	ret = printf("{%-05d}\n", 42);
// 	printf("%35s%d\n", "printf('%-05d', 42) ret : ", ret);
// 	ret = ft_printf("{%-05d}\n", 42);
// 	printf("%35s%d\n", "ft_printf('%-05d', 42) ret : ", ret);
// 	printf("------------------------------------\n");

// 	// test for %*d ; //
// 	printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n          test for %%*d ;\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");

// 	printf("------------------------------------\n");
// 	ret = printf("{%*d}\n", -5, 5);	
// 	printf("%35s%d\n", "printf('%*d', -5, 5) ret : ", ret);
// 	ret = ft_printf("{%*d}\n", -5, 5);
// 	printf("%35s%d\n", "ft_printf('%*d', -5, 5) ret : ", ret);
// 	printf("------------------------------------\n");

// 	ret = printf("{%*d}\n", 0, 0);
// 	printf("%35s%d\n", "printf('%*d', 0, 0) ret : ", ret);
// 	ret = ft_printf("{%*d}\n", 0, 0);
// 	printf("%35s%d\n", "ft_printf('%*d', 0, 0) ret : ", ret);
// 	printf("------------------------------------\n");

// 	printf("%d\n", printf("%10.5d\n", 42));
// 	ft_printf("%d\n", ft_printf("%10.5d\n", 42));

// 	ft_printf("%d\n", ft_printf("%.10d\n", 4242));
// 	ft_printf("%d\n", printf("%.10d\n", 4242));
// 	printf("%d\n", printf("%.10d\n", 4242));
// 	printf("%d\n", ft_printf("%.10d\n", 4242));

// 	return (0);
// }

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonon <mgonon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 18:26:17 by sspinazz          #+#    #+#             */
/*   Updated: 2017/03/23 07:23:42 by mgonon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int		main(int ac, char **av)
{
	int	ret;
	int	toto;

	// printf("@moulitest: %10s\n", NULL);
	// ft_printf("@moulitest: %10s\n", NULL);

	// printf("ret = %D\n\n", ft_printf("%03.2D\n", -1L));
	// printf("ret = %D\n\n", printf("%03.2ld\n", -1L));

	// printf("ret = %D\n\n", ft_printf("@moulitest: %#.o %#.0o\n", 0, 0));
	// printf("ret = %D\n\n", printf("@moulitest: %#.o %#.0o\n", 0, 0));

	// printf("ret = %d\n\n", ft_printf("%#O\n", 1));
	// printf("ret = %d\n\n", printf("%#O\n", 1));

	// printf("ret = %d\n\n", ft_printf("%C", 'ÁM-^L´'));
	// printf("ret = %d\n\n", printf("%C", 'ÁM-^L´'));
	
	// printf("ret = %d\n\n", ft_printf("%p\n", &ret));
	// printf("ret = %d\n\n", printf("%p\n", &ret));

	// printf("ret = %d\n\n", ft_printf("%C", 'ÁM-^L´'));
	// printf("ret = %d\n\n", printf("%C", 'ÁM-^L´'));

	// test for %d 0; //
	// printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n          test for %%d 0;\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");

	// printf("------------------------------------\n");
	// ret = printf("{%d}\n", 0);
	// printf("%35s%d\n", "printf('%d', 0) ret : ", ret);
	// ret = ft_printf("{%d}\n", 0);
	// printf("%35s%d\n", "ft_printf('%d', 0) ret : ", ret);
	// printf("------------------------------------\n");

	// ret = printf("{%+d}\n", 0);
	// printf("%35s%d\n", "printf('%+d', 0) ret : ", ret);
	// ret = ft_printf("{%+d}\n", 0);
	// printf("%35s%d\n", "ft_printf('%+d', 0) ret : ", ret);
	// printf("------------------------------------\n");

	// ret = printf("{%.d}\n", 0);
	// printf("%35s%d\n", "printf('%.d', 0) ret : ", ret);
	// ret = ft_printf("{%.d}\n", 0);
	// printf("%35s%d\n", "ft_printf('%.d', 0) ret : ", ret);
	// printf("------------------------------------\n");

	// ret = printf("{%.5d}\n", 0);
	// printf("%35s%d\n", "printf('%.5d', 0) ret : ", ret);
	// ret = ft_printf("{%.5d}\n", 0);
	// printf("%35s%d\n", "ft_printf('%.5d', 0) ret : ", ret);
	// printf("------------------------------------\n");

	// ret = printf("{%.0d}\n", 0);
	// printf("%35s%d\n", "printf('%.0d', 0) ret : ", ret);
	// ret = ft_printf("{%.0d}\n", 0);
	// printf("%35s%d\n", "ft_printf('%.0d', 0) ret : ", ret);
	// printf("------------------------------------\n");

	// ret = printf("{%5.d}\n", 0);
	// printf("%35s%d\n", "printf('%5.d', 0) ret : ", ret);
	// ret = ft_printf("{%5.d}\n", 0);
	// printf("%35s%d\n", "ft_printf('%5.d', 0) ret : ", ret);
	// printf("------------------------------------\n");

	// ret = printf("{%5.5d}\n", 0);
	// printf("%35s%d\n", "printf('%5.5d', 0) ret : ", ret);
	// ret = ft_printf("{%5.5d}\n", 0);
	// printf("%35s%d\n", "ft_printf('%5.5d', 0) ret : ", ret);
	// printf("------------------------------------\n");

	// ret = printf("{%3.5d}\n", 0);
	// printf("%35s%d\n", "printf('%3.5d', 0) ret : ", ret);
	// ret = ft_printf("{%3.5d}\n", 0);
	// printf("%35s%d\n", "ft_printf('%3.5d', 0) ret : ", ret);
	// printf("------------------------------------\n");

	// ret = printf("{%5.3d}\n", 0);
	// printf("%35s%d\n", "printf('%5.3d', 0) ret : ", ret);
	// ret = ft_printf("{%5.3d}\n", 0);
	// printf("%35s%d\n", "ft_printf('%5.3d', 0) ret : ", ret);
	// printf("------------------------------------\n");

	// ret = printf("{%+010.d}\n", 0);
	// printf("%35s%d\n", "printf('%+010.d', 0) ret : ", ret);
	// ret = ft_printf("{%+010.d}\n", 0);
	// printf("%35s%d\n", "ft_printf('%+010.d', 0) ret : ", ret);
	// printf("------------------------------------\n");

	// ret = printf("{%+010.5d}\n", 0);
	// printf("%35s%d\n", "printf('% 010.5d', 0) ret : ", ret);
	// ret = ft_printf("{%+010.5d}\n", 0);
	// printf("%35s%d\n", "ft_printf('% 010.5d', 0) ret : ", ret);
	// printf("------------------------------------\n");

	// ret = printf("{% .d}\n", 0);
	// printf("%35s%d\n", "printf('% .d', 0) ret : ", ret);
	// ret = ft_printf("{% .d}\n", 0);
	// printf("%35s%d\n", "ft_printf('% .d', 0) ret : ", ret);
	// printf("------------------------------------\n");

	// ret = printf("{%+.d}\n", 0);
	// printf("%35s%d\n", "printf('%+.d', 0) ret : ", ret);
	// ret = ft_printf("{%+.d}\n", 0);
	// printf("%35s%d\n", "ft_printf('%+.d', 0) ret : ", ret);
	// printf("------------------------------------\n");

	// ret = printf("{%3.2d}\n", 0);
	// printf("%35s%d\n", "printf('%3.2d', 0) ret : ", ret);
	// ret = ft_printf("{%3.2d}\n", 0);
	// printf("%35s%d\n", "ft_printf('%3.2d', 0) ret : ", ret);
	// printf("------------------------------------\n");

	// ret = printf("{%-3.2d}\n", 0);
	// printf("%35s%d\n", "printf('%-3.2d', 0) ret : ", ret);
	// ret = ft_printf("{%-3.2d}\n", 0);
	// printf("%35s%d\n", "ft_printf('%-3.2d', 0) ret : ", ret);
	// printf("------------------------------------\n");

	// // test for %d 1; //
	// ret = printf("{%+010.d}\n", 1);
	// printf("%35s%d\n", "printf('%+010.d', 1) ret : ", ret);
	// ret = ft_printf("{%+010.d}\n", 1);
	// printf("%35s%d\n", "ft_printf('%+010.d', 1) ret : ", ret);
	// printf("------------------------------------\n");

	// ret = printf("{%d}\n", -1);
	// printf("%35s%d\n", "printf('%d', -1) ret : ", ret);
	// ret = ft_printf("{%d}\n", -1);
	// printf("%35s%d\n", "ft_printf('%d', -1) ret : ", ret);
	// printf("------------------------------------\n");

	// // test for %d 42; //
	// printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n          test for %%d 42;\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");

	// printf("------------------------------------\n");
	// ret = printf("{%5d}\n", 42);
	// printf("%35s%d\n", "printf('%5d', 42) ret : ", ret);
	// ret = ft_printf("{%5d}\n", 42);
	// printf("%35s%d\n", "ft_printf('%5d', 42) ret : ", ret);
	// printf("------------------------------------\n");

	// ret = printf("{%05d}\n", 42);
	// printf("%35s%d\n", "printf('%05d', 42) ret : ", ret);
	// ret = ft_printf("{%05d}\n", 42);
	// printf("%35s%d\n", "ft_printf('%05d', 42) ret : ", ret);
	// printf("------------------------------------\n");

	// ret = printf("{%0+5d}\n", 42);
	// printf("%35s%d\n", "printf('%0+5d', 42) ret : ", ret);
	// ret = ft_printf("{%0+5d}\n", 42);
	// printf("%35s%d\n", "ft_printf('%0+5d', 42) ret : ", ret);
	// printf("------------------------------------\n");

	// ret = printf("{%5d}\n", -42);
	// printf("%35s%d\n", "printf('%5d', -42) ret : ", ret);
	// ret = ft_printf("{%5d}\n", -42);
	// printf("%35s%d\n", "ft_printf('%5d',- 42) ret : ", ret);
	// printf("------------------------------------\n");

	// ret = printf("{%05d}\n", -42);
	// printf("%35s%d\n", "printf('%05d', -42) ret : ", ret);
	// ret = ft_printf("{%05d}\n", -42);
	// printf("%35s%d\n", "ft_printf('%05d', -42) ret : ", ret);
	// printf("------------------------------------\n");

	// ret = printf("{%-05d}\n", -42);
	// printf("%35s%d\n", "printf('%-05d', -42) ret : ", ret);
	// ret = ft_printf("{%-05d}\n", -42);
	// printf("%35s%d\n", "ft_printf('%-05d', -42) ret : ", ret);
	// printf("------------------------------------\n");

	// ret = printf("{%-05d}\n", 42);
	// printf("%35s%d\n", "printf('%-05d', 42) ret : ", ret);
	// ret = ft_printf("{%-05d}\n", 42);
	// printf("%35s%d\n", "ft_printf('%-05d', 42) ret : ", ret);
	// printf("------------------------------------\n");

	// // test for %*d ; //
	// printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n          test for %%*d ;\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");

	// printf("------------------------------------\n");
	// ret = printf("{%*d}\n", -5, 5);
	// printf("%35s%d\n", "printf('%*d', -5, 5) ret : ", ret);
	// ret = ft_printf("{%*d}\n", -5, 5);
	// printf("%35s%d\n", "ft_printf('%*d', -5, 5) ret : ", ret);
	// printf("------------------------------------\n");

	// ret = printf("{%*d}\n", 0, 0);
	// printf("%35s%d\n", "printf('%*d', 0, 0) ret : ", ret);
	// ret = ft_printf("{%*d}\n", 0, 0);
	// printf("%35s%d\n", "ft_printf('%*d', 0, 0) ret : ", ret);
	// printf("------------------------------------\n");

 //  ft_printf("%d\n", ft_printf("1octal 1 %o octal 2 %o\n", 42, -42));
 //  printf("%d\n", printf("1octal 1 %o octal 2 %o\n", 42, -42));

 //  ft_printf("%d\n", ft_printf("2octal 1 %   o octal 2 % o\n", 42, -42));
 //  printf("%d\n", printf("2octal 1 %   o octal 2 % o\n", 42, -42));

 //  ft_printf("%d\n", ft_printf("4octal 1 %12o octal 2 %12o\n", 42, -42));
 //  printf("%d\n", printf("4octal 1 %12o octal 2 %12o\n", 42, -42));

 //  ft_printf("%d\n", ft_printf("4octal 1 %-12o octal 2 %-12o\n", 42, -42));
 //  printf("%d\n", printf("4octal 1 %-12o octal 2 %-12o\n", 42, -42));

 //  ft_printf("%d\n", ft_printf("5octal 1 %0o octal 2 %0o\n", 42, -42));
 //  printf("%d\n", printf("5octal 1 %0o octal 2 %0o\n", 42, -42));

 //  ft_printf("%d\n", ft_printf("6octal 1 %012o octal 2 %012o\n", 42, -42));
 //  printf("%d\n", printf("6octal 1 %012o octal 2 %012o\n", 42, -42));

 //  ft_printf("%d\n", ft_printf("7octal 1 %-012o octal 2 %012o\n", 42, -42));
 //  printf("%d\n", printf("7octal 1 %-012o octal 2 %012o\n", 42, -42));

 //  ft_printf("%d\n", ft_printf("8octal 1 %*o octal 2 %*o\n", 42, 6, 6, 6));
 //  printf("%d\n", printf("8octal 1 %*o octal 2 %*o\n", 42, 6, 6, 6));

 //  ft_printf("%d\n", ft_printf("9octal 1 %+o octal 2 %+o\n", 42, 6, -42, 6));
 //  printf("%d\n", printf("9octal 1 %+o octal 2 %+o\n", 42, 6, -42, 6));

 //  ft_printf("%d\n", ft_printf("10octal 1 %+12o octal 2 %+12o\n", 42, 6, -42, 6));
 //  printf("%d\n", printf("10octal 1 %+12o octal 2 %+12o\n", 42, 6, -42, 6));

 //  ft_printf("%d\n", ft_printf("11octal 1 %*12o octal 2 %*12o\n", 42, -6, -42, 6));
 //  printf("%d\n", printf("11octal 1 %*12o octal 2 %*12o\n", 42, -6, -42, 6));

 //  ft_printf("%d\n", ft_printf("12octal 1 %-+5o octal 2 %-+5o\n", 42, -42));
 //  printf("%d\n", printf("12octal 1 %-+5o octal 2 %-+5o\n", 42, -42));

 //  ft_printf("%d\n", ft_printf("13octal 1 %-+05o octal 2 %-+05o\n", 42, -42));
 //  printf("%d\n", printf("13octal 1 %-+05o octal 2 %-+05o\n", 42, -42));

 //  ft_printf("%d\n", ft_printf("14octal 1 %+-5o octal 2 %+-5o\n", 42, -42));
 //  printf("%d\n", printf("14octal 1 %+-5o octal 2 %+-5o\n", 42, -42));

 //  ft_printf("%d\n", ft_printf("15octal 1 %.o octal 2 %.o\n", 42, -42));
 //  printf("%d\n", printf("15octal 1 %.o octal 2 %.o\n", 42, -42));

 //  ft_printf("%d\n", ft_printf("16octal 1 %.6o octal 2 %.6o\n", 42, -42));
 //  printf("%d\n", printf("16octal 1 %.6o octal 2 %.6o\n", 42, -42));
	return (0);
}

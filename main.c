/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonon <mgonon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 18:26:17 by sspinazz          #+#    #+#             */
/*   Updated: 2017/08/03 11:59:23 by mgonon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

//https://www.ibisc.univ-evry.fr/~petit/Enseignement/Modelisation-en-C/printf-conversions-format.pdf
//https://forum.intra.42.fr/topics/15759/messages/1#57314

int		main(int ac, char **av)
{
	int	ret;
	int	toto;

	int test;
	int test2;
	int test3;
	int test4;
	int test5;
	int test6;
	int test7;
	int test_simple_mix;
	printf("\n\n\n\n========= TEST DEBUT =========\n\n");

	// printf("ret = %D\n\n", printf("test %p\n", &ret));
	// printf("ret = %D\n\n", ft_printf("{%15ZPK}", 123));
	// printf("ret = %D\n\n", printf("{%15ZPK}", 123));
	printf("ret = %D\n\n", printf("{%*c}\n", -15, 0));
	printf("ret = %D\n\n", ft_printf("{%*c}\n", -15, 0));
	// printf("\n\n========= TEST END =========\n\n");

	printf("long_min = %ld\n", LONG_MIN);
	printf("long_long_min = %lld\n", LONG_LONG_MIN);
	// printf("itoa = %lld\n", intmaxtoa_base(-9223372036854775808, 10));

	printf("ret = %D\n\n", printf("s: %s, p: %p, d:%d\n", "a string", &test_simple_mix, 42));
	printf("ret = %D\n\n", ft_printf("s: %s, p: %p, d:%d\n", "a string", &test_simple_mix, 42));


  /* Memes tests avec les %c */

  ft_printf("%d\n", ft_printf("1caractere 1 %c caractere 2 %c\n", 'a', 'c'));
  printf("%d\n\n", printf("1caractere 1 %c caractere 2 %c\n\n", 'a', 'c'));

  ft_printf("%d\n", ft_printf("2caractere 1 %   c caractere 2 % c\n", 'a', 'c'));
  printf("%d\n\n", printf("3caractere 1 %   c caractere 2 % c\n\n", 'a', 'c'));

  ft_printf("%d\n", ft_printf("4caractere 1 %12c caractere 2 %12c\n", 'a', 'c'));
  printf("%d\n\n", printf("4caractere 1 %12c caractere 2 %12c\n\n", 'a', 'c'));

  ft_printf("%d\n", ft_printf("4caractere 1 %-12c caractere 2 %-12c\n", 'a', 'c'));
  printf("%d\n\n", printf("4caractere 1 %-12c caractere 2 %-12c\n\n", 'a', 'c'));

  ft_printf("%d\n", ft_printf("5caractere 1 %0c caractere 2 %0c\n", 'a', 'c'));
  printf("%d\n\n", printf("5caractere 1 %0c caractere 2 %0c\n\n", 'a', 'c'));

  ft_printf("%d\n", ft_printf("6caractere 1 %012c caractere 2 %012c\n", 'a', 'c'));
  printf("%d\n\n", printf("6caractere 1 %012c caractere 2 %012c\n\n", 'a', 'c'));

  ft_printf("%d\n", ft_printf("7caractere 1 %-012c caractere 2 %012c\n", 'a', 'c'));
  printf("%d\n\n", printf("7caractere 1 %-012c caractere 2 %012c\n\n", 'a', 'c'));

  ft_printf("%d\n", ft_printf("8caractere 1 %*c caractere 2 %*c\n", 'a', 6, 6, 6));
  printf("%d\n\n", printf("8caractere 1 %*c caractere 2 %*c\n\n", 'a', 6, 6, 6));

  ft_printf("%d\n", ft_printf("9caractere 1 %+c caractere 2 %+c\n", 'a', 6, 'c', 6));
  printf("%d\n\n", printf("9caractere 1 %+c caractere 2 %+c\n\n", 'a', 6, 'c', 6));

  ft_printf("%d\n", ft_printf("10caractere 1 %+12c caractere 2 %+12c\n", 'a', 6, 'c', 6));
  printf("%d\n\n", printf("10caractere 1 %+12c caractere 2 %+12c\n\n", 'a', 6, 'c', 6));

  ft_printf("%d\n", ft_printf("11caractere 1 %*12c caractere 2 %*12c\n", 'a', -6, 'a', 6));
  printf("%d\n\n", printf("11caractere 1 %*12c caractere 2 %*12c\n\n", 'a', -6, 'a', 6));

  ft_printf("%d\n", ft_printf("12caractere 1 %-+5c caractere 2 %-+5c\n", 'a', 'c'));
  printf("%d\n\n", printf("12caractere 1 %-+5c caractere 2 %-+5c\n\n", 'a', 'c'));

  ft_printf("%d\n", ft_printf("13caractere 1 %-+05.12c caractere 2 %-+05c\n", 'a', 'c'));
  printf("%d\n\n", printf("13caractere 1 %-+05.12c caractere 2 %-+05c\n\n", 'a', 'c'));

  ft_printf("%d\n", ft_printf("14caractere 1 %+-5c caractere 2 %+-5c\n", 'a', 'c'));
  printf("%d\n\n", printf("14caractere 1 %+-5c caractere 2 %+-5c\n\n", 'a', 'c'));

  ft_printf("%d\n", ft_printf("15caractere 1 %.c caractere 2 %.c\n", 'a', 'c'));
  printf("%d\n\n", printf("15caractere 1 %.c caractere 2 %.c\n\n", 'a', 'c'));

  ft_printf("%d\n", ft_printf("16caractere 1 %.6c caractere 2 %.6c\n", 'a', 'c'));
  printf("%d\n\n", printf("16caractere 1 %.6c caractere 2 %.6c\n\n", 'a', 'c'));

// 	printf("ret = %D\n\n", printf("%p\n", &test));
// 	printf("ret = %D\n\n", printf("%p\n", &test2));
// 	printf("ret = %D\n\n", printf("%p\n", &test3));
// 	printf("ret = %D\n\n", printf("%p\n", &test4));
// 	printf("ret = %D\n\n", printf("%p\n", &test5));
// 	printf("ret = %D\n\n", printf("%p\n", &test6));
// 	printf("ret = %D\n\n", printf("%p\n", &test7));

	
// 	printf("@moulitest: %10s\n", NULL);
// 	ft_printf("@moulitest: %10s\n", NULL);

// 	printf("ret = %D\n\n", ft_printf("%03.2D\n", -1L));
// 	printf("ret = %D\n\n", printf("%03.2ld\n", -1L));

// 	printf("ret = %D\n\n", ft_printf("@moulitest: %#.o %#.0o\n", 0, 0));
// 	printf("ret = %D\n\n", printf("@moulitest: %#.o %#.0o\n", 0, 0));

// 	printf("ret = %d\n\n", ft_printf("%#O\n", 1));
// 	printf("ret = %d\n\n", printf("%#O\n", 1));

	
// 	printf("ret = %d\n\n", ft_printf("%p\n", &ret));
// 	printf("ret = %d\n\n", printf("%p\n", &ret));



// 	// test for %d 0; //
// 	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n          test for %%d 0;\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");

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

// 	ret = printf("{%d}\n", -1);
// 	printf("%35s%d\n", "printf('%d', -1) ret : ", ret);
// 	ret = ft_printf("{%d}\n", -1);
// 	printf("%35s%d\n", "ft_printf('%d', -1) ret : ", ret);
// 	printf("------------------------------------\n");

// 	// test for %d 42; //
// 	printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n          test for %%d 42;\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");

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
// 	printf("%35s%d\n", "ft_printf('%5d',- 42) ret : ", ret);
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
// 	printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n          test for %%*d ;\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");

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

//   ft_printf("%d\n", ft_printf("1octal 1 %o octal 2 %o\n", 42, -42));
//   printf("%d\n", printf("1octal 1 %o octal 2 %o\n", 42, -42));

//   ft_printf("%d\n", ft_printf("2octal 1 %   o octal 2 % o\n", 42, -42));
//   printf("%d\n", printf("2octal 1 %   o octal 2 % o\n", 42, -42));

//   ft_printf("%d\n", ft_printf("4octal 1 %12o octal 2 %12o\n", 42, -42));
//   printf("%d\n", printf("4octal 1 %12o octal 2 %12o\n", 42, -42));

//   ft_printf("%d\n", ft_printf("4octal 1 %-12o octal 2 %-12o\n", 42, -42));
//   printf("%d\n", printf("4octal 1 %-12o octal 2 %-12o\n", 42, -42));

//   ft_printf("%d\n", ft_printf("5octal 1 %0o octal 2 %0o\n", 42, -42));
//   printf("%d\n", printf("5octal 1 %0o octal 2 %0o\n", 42, -42));

//   ft_printf("%d\n", ft_printf("6octal 1 %012o octal 2 %012o\n", 42, -42));
//   printf("%d\n", printf("6octal 1 %012o octal 2 %012o\n", 42, -42));

//   ft_printf("%d\n", ft_printf("7octal 1 %-012o octal 2 %012o\n", 42, -42));
//   printf("%d\n", printf("7octal 1 %-012o octal 2 %012o\n", 42, -42));

//   ft_printf("%d\n", ft_printf("8octal 1 %*o octal 2 %*o\n", 42, 6, 6, 6));
//   printf("%d\n", printf("8octal 1 %*o octal 2 %*o\n", 42, 6, 6, 6));

//   ft_printf("%d\n", ft_printf("9octal 1 %+o octal 2 %+o\n", 42, 6, -42, 6));
//   printf("%d\n", printf("9octal 1 %+o octal 2 %+o\n", 42, 6, -42, 6));

//   ft_printf("%d\n", ft_printf("10octal 1 %+12o octal 2 %+12o\n", 42, 6, -42, 6));
//   printf("%d\n", printf("10octal 1 %+12o octal 2 %+12o\n", 42, 6, -42, 6));

//   ft_printf("%d\n", ft_printf("11octal 1 %*12o octal 2 %*12o\n", 42, -6, -42, 6));
//   printf("%d\n", printf("11octal 1 %*12o octal 2 %*12o\n", 42, -6, -42, 6));

//   ft_printf("%d\n", ft_printf("12octal 1 %-+5o octal 2 %-+5o\n", 42, -42));
//   printf("%d\n", printf("12octal 1 %-+5o octal 2 %-+5o\n", 42, -42));

//   ft_printf("%d\n", ft_printf("13octal 1 %-+05o octal 2 %-+05o\n", 42, -42));
//   printf("%d\n", printf("13octal 1 %-+05o octal 2 %-+05o\n", 42, -42));

//   ft_printf("%d\n", ft_printf("14octal 1 %+-5o octal 2 %+-5o\n", 42, -42));
//   printf("%d\n", printf("14octal 1 %+-5o octal 2 %+-5o\n", 42, -42));

//   ft_printf("%d\n", ft_printf("15octal 1 %.o octal 2 %.o\n", 42, -42));
//   printf("%d\n", printf("15octal 1 %.o octal 2 %.o\n", 42, -42));

//   ft_printf("%d\n", ft_printf("16octal 1 %.6o octal 2 %.6o\n", 42, -42));
//   printf("%d\n", printf("16octal 1 %.6o octal 2 %.6o\n", 42, -42));
	return (0);
}

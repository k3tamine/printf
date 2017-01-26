/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sspinazz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 18:26:17 by sspinazz          #+#    #+#             */
/*   Updated: 2017/01/26 17:10:47 by sspinazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_printf.h"
#include <stdio.h>

int		main(int ac, char **av)
{
	int	ret;

	// test for %d 0; //
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n          test for %%d 0;\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");

	printf("------------------------------------\n");
	ret = printf("{%d}\n", 0);
	printf("%35s%d\n", "printf('%d', 0) ret : ", ret);
	ret = ft_printf("{%d}\n", 0);
	printf("%35s%d\n", "ft_printf('%d', 0) ret : ", ret);
	printf("------------------------------------\n");

	ret = printf("{%+d}\n", 0);
	printf("%35s%d\n", "printf('%+d', 0) ret : ", ret);
	ret = ft_printf("{%+d}\n", 0);
	printf("%35s%d\n", "ft_printf('%+d', 0) ret : ", ret);
	printf("------------------------------------\n");

	ret = printf("{%.d}\n", 0);
	printf("%35s%d\n", "printf('%.d', 0) ret : ", ret);
	ret = ft_printf("{%.d}\n", 0);
	printf("%35s%d\n", "ft_printf('%.d', 0) ret : ", ret);
	printf("------------------------------------\n");

	ret = printf("{%.5d}\n", 0);
	printf("%35s%d\n", "printf('%.5d', 0) ret : ", ret);
	ret = ft_printf("{%.5d}\n", 0);
	printf("%35s%d\n", "ft_printf('%.5d', 0) ret : ", ret);
	printf("------------------------------------\n");

	ret = printf("{%.0d}\n", 0);
	printf("%35s%d\n", "printf('%.0d', 0) ret : ", ret);
	ret = ft_printf("{%.0d}\n", 0);
	printf("%35s%d\n", "ft_printf('%.0d', 0) ret : ", ret);
	printf("------------------------------------\n");

	ret = printf("{%5.d}\n", 0);
	printf("%35s%d\n", "printf('%5.d', 0) ret : ", ret);
	ret = ft_printf("{%5.d}\n", 0);
	printf("%35s%d\n", "ft_printf('%5.d', 0) ret : ", ret);
	printf("------------------------------------\n");

	ret = printf("{%5.5d}\n", 0);
	printf("%35s%d\n", "printf('%5.5d', 0) ret : ", ret);
	ret = ft_printf("{%5.5d}\n", 0);
	printf("%35s%d\n", "ft_printf('%5.5d', 0) ret : ", ret);
	printf("------------------------------------\n");

	ret = printf("{%3.5d}\n", 0);
	printf("%35s%d\n", "printf('%3.5d', 0) ret : ", ret);
	ret = ft_printf("{%3.5d}\n", 0);
	printf("%35s%d\n", "ft_printf('%3.5d', 0) ret : ", ret);
	printf("------------------------------------\n");

	ret = printf("{%5.3d}\n", 0);
	printf("%35s%d\n", "printf('%5.3d', 0) ret : ", ret);
	ret = ft_printf("{%5.3d}\n", 0);
	printf("%35s%d\n", "ft_printf('%5.3d', 0) ret : ", ret);
	printf("------------------------------------\n");

	ret = printf("{%+010.d}\n", 0);
	printf("%35s%d\n", "printf('%+010.d', 0) ret : ", ret);
	ret = ft_printf("{%+010.d}\n", 0);
	printf("%35s%d\n", "ft_printf('%+010.d', 0) ret : ", ret);
	printf("------------------------------------\n");

	ret = printf("{%+010.5d}\n", 0);
	printf("%35s%d\n", "printf('% 010.5d', 0) ret : ", ret);
	ret = ft_printf("{%+010.5d}\n", 0);
	printf("%35s%d\n", "ft_printf('% 010.5d', 0) ret : ", ret);
	printf("------------------------------------\n");

	ret = printf("{% .d}\n", 0);
	printf("%35s%d\n", "printf('% .d', 0) ret : ", ret);
	ret = ft_printf("{% .d}\n", 0);
	printf("%35s%d\n", "ft_printf('% .d', 0) ret : ", ret);
	printf("------------------------------------\n");

	ret = printf("{%+.d}\n", 0);
	printf("%35s%d\n", "printf('%+.d', 0) ret : ", ret);
	ret = ft_printf("{%+.d}\n", 0);
	printf("%35s%d\n", "ft_printf('%+.d', 0) ret : ", ret);
	printf("------------------------------------\n");

	ret = printf("{%3.2d}\n", 0);
	printf("%35s%d\n", "printf('%3.2d', 0) ret : ", ret);
	ret = ft_printf("{%3.2d}\n", 0);
	printf("%35s%d\n", "ft_printf('%3.2d', 0) ret : ", ret);
	printf("------------------------------------\n");

	ret = printf("{%-3.2d}\n", 0);
	printf("%35s%d\n", "printf('%-3.2d', 0) ret : ", ret);
	ret = ft_printf("{%-3.2d}\n", 0);
	printf("%35s%d\n", "ft_printf('%-3.2d', 0) ret : ", ret);
	printf("------------------------------------\n");

	// test for %d 1; //
	ret = printf("{%+010.d}\n", 1);
	printf("%35s%d\n", "printf('%+010.d', 1) ret : ", ret);
	ret = ft_printf("{%+010.d}\n", 1);
	printf("%35s%d\n", "ft_printf('%+010.d', 1) ret : ", ret);
	printf("------------------------------------\n");

	ret = printf("{%d}\n", -1);
	printf("%35s%d\n", "printf('%d', -1) ret : ", ret);
	ret = ft_printf("{%d}\n", -1);
	printf("%35s%d\n", "ft_printf('%d', -1) ret : ", ret);
	printf("------------------------------------\n");

	// test for %d 42; //
	printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n          test for %%d 42;\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");

	printf("------------------------------------\n");
	ret = printf("{%5d}\n", 42);
	printf("%35s%d\n", "printf('%5d', 42) ret : ", ret);
	ret = ft_printf("{%5d}\n", 42);
	printf("%35s%d\n", "ft_printf('%5d', 42) ret : ", ret);
	printf("------------------------------------\n");

	ret = printf("{%05d}\n", 42);
	printf("%35s%d\n", "printf('%05d', 42) ret : ", ret);
	ret = ft_printf("{%05d}\n", 42);
	printf("%35s%d\n", "ft_printf('%05d', 42) ret : ", ret);
	printf("------------------------------------\n");

	ret = printf("{%0+5d}\n", 42);
	printf("%35s%d\n", "printf('%0+5d', 42) ret : ", ret);
	ret = ft_printf("{%0+5d}\n", 42);
	printf("%35s%d\n", "ft_printf('%0+5d', 42) ret : ", ret);
	printf("------------------------------------\n");

	ret = printf("{%5d}\n", -42);
	printf("%35s%d\n", "printf('%5d', -42) ret : ", ret);
	ret = ft_printf("{%5d}\n", -42);
	printf("%35s%d\n", "ft_printf('%5d',- 42) ret : ", ret);
	printf("------------------------------------\n");

	ret = printf("{%05d}\n", -42);
	printf("%35s%d\n", "printf('%05d', -42) ret : ", ret);
	ret = ft_printf("{%05d}\n", -42);
	printf("%35s%d\n", "ft_printf('%05d', -42) ret : ", ret);
	printf("------------------------------------\n");

	ret = printf("{%-05d}\n", -42);
	printf("%35s%d\n", "printf('%-05d', -42) ret : ", ret);
	ret = ft_printf("{%-05d}\n", -42);
	printf("%35s%d\n", "ft_printf('%-05d', -42) ret : ", ret);
	printf("------------------------------------\n");

	ret = printf("{%-05d}\n", 42);
	printf("%35s%d\n", "printf('%-05d', 42) ret : ", ret);
	ret = ft_printf("{%-05d}\n", 42);
	printf("%35s%d\n", "ft_printf('%-05d', 42) ret : ", ret);
	printf("------------------------------------\n");

	// test for %*d ; //
	printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n          test for %%*d ;\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");

	printf("------------------------------------\n");
	ret = printf("{%*d}\n", -5, 5);
	printf("%35s%d\n", "printf('%*d', -5, 5) ret : ", ret);
	ret = ft_printf("{%*d}\n", -5, 5);
	printf("%35s%d\n", "ft_printf('%*d', -5, 5) ret : ", ret);
	printf("------------------------------------\n");

	ret = printf("{%*d}\n", 0, 0);
	printf("%35s%d\n", "printf('%*d', 0, 0) ret : ", ret);
	ret = ft_printf("{%*d}\n", 0, 0);
	printf("%35s%d\n", "ft_printf('%*d', 0, 0) ret : ", ret);
	printf("------------------------------------\n");

	return (0);
}

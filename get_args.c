#include "ft_printf.h"

intmax_t	get_signed_arg(va_list args, char speci, t_length length)
{
	intmax_t arg;

	if (length.l >= 2)
		arg = (intmax_t)va_arg(args, long long);
	else if (length.l == 1 || speci == 'D')
		arg = (intmax_t)va_arg(args, long);
	else if (length.z >= 1)
		arg = va_arg(args, ssize_t);
	else if (length.j >= 1)
		arg = va_arg(args, intmax_t);
	else if (length.h >= 2)
		arg = (intmax_t)(char)va_arg(args, int);
	else if (length.h == 1)
		arg = (intmax_t)(short)va_arg(args, int);
	else
		arg = (intmax_t)va_arg(args, int);
	return (arg);
}

uintmax_t	get_unsigned_arg(va_list args, char speci, t_length length)
{
	uintmax_t arg;

	if (length.l >= 2)
		arg = (uintmax_t)va_arg(args, unsigned long long);
	else if (length.l == 1 || speci == 'U' || speci == 'O' || speci == 'B')
		arg = (uintmax_t)va_arg(args, unsigned long);
	else if (length.z >= 1)
		arg = (uintmax_t)va_arg(args, size_t);
	else if (length.j >= 1)
		arg = va_arg(args, uintmax_t);
	else if (length.h >= 2)
		arg = (uintmax_t)(unsigned char)va_arg(args, unsigned int);
	else if (length.h == 1)
		arg = (uintmax_t)(unsigned short)va_arg(args, unsigned int);
	else
		arg = (uintmax_t)va_arg(args, unsigned int);
	return (arg);
}
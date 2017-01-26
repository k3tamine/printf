#include "ft_printf.h"

void	shift_index(char *buf, int nb)
{
	int 	i;
	char	tmp;

	i = -1;
	while (++i < nb)
	{
		tmp = buf[i + 1];
		buf[i + 1] = buf[i];
	}
}

size_t	apply_precision(int precision, int size, int nb)
{
	char	buf[100];
	int		i;

	i = -1;
	if (nb < 0)
		size--;
	if (precision <= size)
		return (0);
	while (++i < precision - size)
		buf[i] = '0';
	write(1, buf, precision - size);
	return (precision - size);
}

size_t	apply_width(int width, int size, int nb)
{
	char	buf[100];
	int		i;

	i = -1;
	if (nb < 0)
		size--;
	size--;
	if (width <= size)
		return (0);
	while (++i < width - size)
		buf[i] = ' ';
	write(1, buf, width - size);
	return (width - size);
}

char	*handle_d(int nb, char *buf, t_format *frmt)
{
	int		i;
	int		len;
	char	tmp;

	i = -1;
	len = ft_itoa_base_buf(nb, 10, 	buf);
	if (frmt->flags.minus)
	{
		if (nb < 0)
			write(1, "-", 1);
		else if (frmt->flags.plus)
			write(1, "+", 1);
		apply_precision(frmt->precision, len, nb);
		if (nb < 0)
			write(1, buf + 1, len - 1);
		else
			write(1, buf, len);
		//printf("\n%d\n", len + frmt->precision);
		apply_width(frmt->width, len + frmt->precision, nb);
		// if (frmt->flags.plus)
		// 	apply_width(frmt->width, len + frmt->precision + 1, nb);
		// else
		// 	apply_width(frmt->width, len + frmt->precision + 1, nb);
	}
	return (NULL);
}

// char	*handle_d(int nb, char *buf, t_format *frmt)
// {
// 	int		i;
// 	int		len;
// 	char	tmp;

// 	i = -1;
// 	len = ft_itoa_base_buf(nb, 10, 	buf);
// 	if (frmt->flags.plus && nb >= 0)
// 	{
// 		shift_index(buf, len);
// 		buf[i] = '+';
// 		len++;
// 	}
// 	//printf(" LEN + %d\n", len);
// 	if (frmt->precision != -42)
// 	{
// 		while (++i < frmt->precision - len)
// 		{
// 			//printf("len = %d\n", frmt->precision - len);
// 			//printf("buf[8] = %c\n", buf[8]);
// 			buf[i + frmt->precision - len] = buf[i];
// 			buf[i] = '0';
// 		}
// 	}
// 	i = -1;
// 	if (frmt->width != -42)
// 	{
// 		while (++i < frmt->width - len)
// 		{
// 			//printf("len = %d\n", frmt->width - len);
// 			//printf("buf[8] = %c\n", buf[8]);
// 			if (frmt->flags.minus)
// 				buf[i + len] = ' ';
// 			else
// 			{
// 				buf[i + frmt->width - len] = buf[i];
// 				// if (frmt->flags.zero)
// 				// {
// 				// 	if (frmt->flags.plus && i == 0)
// 				// 	{
// 				// 		if (nb >= 0)
// 				// 		{
// 				// 			shift_index(buf, len);
// 				// 			buf[i] = '+';
// 				// 		}
// 				// 		else
// 				// 		{
// 				// 			buf[i] = '-';
// 				// 			buf[i + 1] = '0';
// 				// 		}
// 				// 		continue;
// 				// 	}
// 				// 	buf[i + len] = '0';
// 				// }
// 				// else
// 				// 	buf[i + len] = ' ';
// 				if (frmt->flags.zero)
// 					buf[i] = '0';
// 				else
// 					buf[i] = ' ';
// 			}
// 		}
// 	}

// 	// if (frmt->flags.plus)
// 	// {
// 	// 	if 
// 	// }
// 	return (buf);
// }
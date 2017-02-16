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

int	apply_precision(int precision, int size, int nb)
{
	char	buf[4096];
	int		ret;
	int		i;

	ret = precision - size;
	i = -1;
	if (nb < 0)
		size--;
	if (precision <= size)
		return (0);
	while (++i < precision - size)
		buf[i] = '0';
	write(1, buf, precision - size);
	return (ret);
}

int	apply_width(int width, int size, int nb, int len)
{
	char	buf[4096];
	int		ret;
	int		i;

	if (size < len)
		size = len;
	i = -1;
	// ret = width - size;
	// if (nb < 0)
		// width--;
	if (width <= size)
		return (0);
	// printf("\nwidth = %d, size = %d, nb = %d\n", width, size, nb);
	while (++i < width - size)
		buf[i] = ' ';
	write(1, buf, width - size);
	return (width - size);
}

// int	apply_minus(int nb, int len, char *buf, t_format *frmt)
// {
// 	int	add_len;

// 	add_len = len;
// 	if (frmt->flags.plus && nb > 0)
// 		write(1, "+", 1);
// 	else if (nb < 0)
// 		write(1, "-", 1);
// 	add_len += apply_precision(frmt->precision, len, nb);
// 	// printf("\n add_len = %d, frmt->width = %d, nb = %d\n", add_len, frmt->width, nb);
// 	write(1, buf, len);
// 	add_len += apply_width(frmt->width, add_len, nb, len);
// 	return (add_len);
// }

int	apply_classic(int nb, int len, char *buf, t_format *frmt)
{
	int	add_len;
	int	i;

	i = 0;
	add_len = len;
	add_len += frmt->flags.minus ? 0 : apply_width(frmt->width, frmt->precision, nb, len);
	// printf("\nICCCCII\n");
	if (frmt->flags.plus && nb > 0)
		write(1, "+", 1);
	else if (nb < 0)
	{
		write(1, "-", 1);
		i = 1;
	}
	// printf("\n len = %d, frmt->width = %d, nb = %d\n", len, frmt->width, nb);
	add_len += frmt->flags.minus ? apply_precision(frmt->precision, len, nb) : 0;
	// printf("\n add_len = %d, frmt->width = %d, nb = %d\n", add_len, frmt->width, nb);
	write(1, buf + i, len - i);
	add_len += frmt->flags.minus ? apply_width(frmt->width, add_len, nb, len) : 
		apply_precision(frmt->precision, len, nb);
	return (add_len);
}

int	handle_d(int nb, char *buf, t_format *frmt)
{
	int		i;
	int		len;
	char	tmp;

	i = -1;
	len = ft_itoa_base_buf(nb, 10, 	buf);
	// if (frmt->flags.minus)
	// 	len += apply_minus(nb, len, buf, frmt);
	// else
		len += apply_classic(nb, len, buf, frmt);
	return (len);
}

// char	*handle_d(int nb, char *buf, t_format *frmt)
// {
// 	int		i;
// 	int		len;
// 	char	tmp;

// 	i = -1;
// 	len = ft_itoa_base_buf(nb, 10, 	buf);
// 	if (frmt->flags.minus)
// 	{
// 		if (nb < 0)
// 			write(1, "-", 1);
// 		else if (frmt->flags.plus)
// 			write(1, "+", 1);
// 		apply_precision(frmt->precision, len, nb);
// 		if (nb < 0)
// 			write(1, buf + 1, len - 1);
// 		else
// 			write(1, buf, len);
// 		//printf("\n%d\n", len + frmt->precision);
// 		apply_width(frmt->width, len + frmt->precision, nb);
// 		// if (frmt->flags.plus)
// 		// 	apply_width(frmt->width, len + frmt->precision + 1, nb);
// 		// else
// 		// 	apply_width(frmt->width, len + frmt->precision + 1, nb);
// 	}
// 	return (NULL);
// }
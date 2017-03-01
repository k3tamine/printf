#include "ft_printf.h"

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
	// printf("\nret_prec = %d\n", ret);
	write(1, buf, precision - size);
	return (ret);
}

int	apply_width(int width, int size, int len, char c)
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
		buf[i] = c;
	write(1, buf, width - size);
	// printf("\nret_width = %d\n", width - size);
	return (width - size);
}

// //TODO
// int	apply_width_preci(int width, int size, int nb, int len)
// {
// 	char	buf[4096];
// 	int		ret;
// 	int		i;

// 	if (size < len)
// 		size = len;
// 	i = -1;
// 	// ret = width - size;
// 	// if (nb < 0)
// 		// width--;
// 	if (width <= size)
// 		return (0);
// 	// printf("\nwidth = %d, size = %d, nb = %d\n", width, size, nb);
// 	while (++i < width - size)
// 		buf[i] = ' ';
// 	write(1, buf, width - size);
// 	return (width - size);
// }

int	apply_classic(int nb, int len, char *buf, t_format *frmt)
{
	int		add_len;
	int		i;

	i = 0;
	add_len = 0;
	if (nb < 0)
		i = 1;
	if (frmt->flags.space && !frmt->flags.plus && nb >= 0 && (++add_len))
		write(1, " ", 1);
	if (!frmt->flags.zero)
	{
		if (!frmt->flags.plus)
			add_len += frmt->flags.minus ? 0 : apply_width(frmt->width, frmt->precision + i, len, ' ');
		else
			add_len += frmt->flags.minus ? 0 : apply_width(frmt->width - 1, frmt->precision, len, ' ');
	}
	// printf("\nadd_len1 = %d\n", add_len);
	if (frmt->flags.plus && nb >= 0 && (++add_len))
		write(1, "+", 1);
	else if (nb < 0)
		write(1, "-", 1);
	// printf("\nadd_len2 = %d\n", add_len);
	if (frmt->flags.zero)
		add_len += frmt->flags.minus ? apply_precision(frmt->precision, len, nb) 
			: apply_width(frmt->width, frmt->precision, add_len + len, '0');
	else
		add_len += apply_precision(frmt->precision, len, nb);
	write(1, buf + i, len - i);
	// printf("\nadd_len3 = %d\n", add_len);
	add_len += frmt->flags.minus ? apply_width(frmt->width, add_len + len, len, ' ') : 
		0;
	// printf("\nadd_len4 = %d\n", add_len);
	return (add_len);
	// printf("\n len = %d, frmt->width = %d, nb = %d\n", len, frmt->width, nb);
	// printf("\n add_len = %d, frmt->width = %d, nb = %d\n", add_len, frmt->width, nb);
}

// int	apply_zero(int nb, int len, char *buf, t_format *frmt)
// {

// }

int	handle_d(int nb, char *buf, t_format *frmt)
{
	int		i;
	int		len;
	char	tmp;

	i = -1;
	len = 0;

	if (nb != 0 || (frmt->width == 0 && frmt->precision == -1))
		len = ft_itoa_base_buf(nb, 10, 	buf);
	else
		buf[0] = '\0';
	// if (frmt->flags.minus)
	// 	len += apply_minus(nb, len, buf, frmt);
	// else
	// if (frmt->flags.zero)
	// 	len += apply_zero(nb, len, buf, frmt);
	// else
	// printf("\nlen = %d\n", len);
		len += apply_classic(nb, len, buf, frmt);
	// printf("\nlen2 = %d\n", len);
	return (len);
}
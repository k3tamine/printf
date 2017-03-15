#include "ft_printf.h"

int	handle_s(char *str, t_format *frmt)
{
	int	add_len;
	int	len;

	add_len = 0;
	if (!str)
		str = "(null)";
	len = ft_strlen(str);
	if (frmt->specifier == '%' && frmt->precision == 0)
		frmt->precision = 1;
	if (frmt->width && !frmt->flags.minus)
		add_len += frmt->precision != -1 && *str ? apply_width(frmt->width, frmt->precision, 0, ' ')
	: apply_width(frmt->width, len, 0, ' ');
	if (frmt->precision != -1 && *str)
	{
		add_len += frmt->precision;
		write(1, str, frmt->precision);
		if (frmt->width && frmt->flags.minus)
			add_len += apply_width(frmt->width, frmt->precision, 0, ' ');
	}
	else
	{
		add_len += len;
		write(1, str, len);
		if (frmt->width && frmt->flags.minus)
			add_len += apply_width(frmt->width, len, 0, ' ');
	}
	return (add_len);
}

int	handle_c(char c, t_format *frmt)
{
	char	*str;
	int		len;

	len = 0;
	if (c == 0)
	{
		len++;
		if (frmt->width > 0)
			frmt->width--;
	}
	str = (char *)malloc(sizeof(*str) * 2);
	str[0] = c;
	str[1] = '\0';
	len += handle_s(str, frmt);
	free(str);
	return (len);
}
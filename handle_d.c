#include "ft_printf.h"

char	*handle_d(int nb, char *buf, t_format *frmt)
{
	int	i;
	int	len;

	i = -1;
	len = ft_itoa_base_buf(nb, 10, 	buf);
	printf(" LEN + %d\n", len);
	if (frmt->precision != -42)
	{
		while (++i < frmt->precision - len)
		{
			printf("len = %d\n", frmt->precision - len);
			printf("buf[8] = %c\n", buf[8]);
			buf[i + frmt->precision - len] = buf[i];
			buf[i] = '0';
		}
	}
	return (buf);
}
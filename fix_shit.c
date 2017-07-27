static int	apply_invalid_spec(uintmax_t nb, int len, char *buf, t_format *frmt)
{
	int		add_len;

	add_len = 0;
	if ((nb != 0 || frmt->specifier == 'o') && ((frmt->flags.sharp && !frmt->width) ||
	(frmt->flags.sharp && (frmt->flags.minus || frmt->flags.zero))))
		add_len += apply_usharp(buf, frmt->specifier, 1);
	if (!frmt->flags.zero)
	{
		if (nb != 0 && frmt->flags.sharp && !frmt->flags.minus && frmt->width)
		{
			frmt->width -= apply_usharp(buf, frmt->specifier, 0);
			add_len += apply_usharp(buf, frmt->specifier, 0);
		}
		add_len += frmt->flags.minus ? 0
			: apply_width(frmt->width, frmt->precision, len, ' ');
		if (nb != 0 && frmt->flags.sharp && !frmt->flags.minus && frmt->width)
			apply_usharp(buf, frmt->specifier, 1);
		add_len += apply_precision(frmt->precision, len, nb);
	}
	else
		add_len += frmt->flags.minus ? apply_precision(frmt->precision, len, nb)
			: apply_width(frmt->width, frmt->precision, add_len + len, '0');
	write(1, buf, len);
	add_len += frmt->flags.minus ?
		apply_width(frmt->width, add_len + len, len, ' ') : 0;
	return (add_len);
}
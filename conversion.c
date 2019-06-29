/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junpark <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/02 14:03:52 by junpark           #+#    #+#             */
/*   Updated: 2019/06/11 01:59:44 by junpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flag	print_conversion(const char *format, int a, t_flag f, va_list ap)
{
	f = handle_flags(f);
	if (format[a] == 'd' || format[a] == 'i')
		f = handle_d_i(f, va_arg(ap, long long int));
	else if (format[a] == 'u')
		f = handle_u(f, va_arg(ap, unsigned long long int));
	else if (format[a] == 'o')
		f = handle_o(f, va_arg(ap, unsigned long long int));
	else if (format[a] == 'x' || format[a] == 'X')
		f = handle_x(f, format[a], va_arg(ap, unsigned long long int));
	else if (format[a] == 'c')
		f = handle_c(f, va_arg(ap, int));
	else if (format[a] == 's')
		f = handle_s(f, va_arg(ap, char *));
	else if (format[a] == 'p')
		f = handle_p(f, va_arg(ap, unsigned long long int));
	else if (format[a] == '%')
		f = handle_perc(f);
	return (f);
}

int		check_conversion(const char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || \
		c == 'i' || c == 'o' || c == 'u' || c == 'x' || \
		c == 'X' || c == 'f' || c == '%')
		return (1);
	return (0);
}

char	*pf_itoa(long long int value, int base)
{
	long long int	n;
	char			*str;
	int				sign;
	int				i;

	if (value - 1 == 9223372036854775807)
		return (ft_strdup("-9223372036854775808"));
	n = (value < 0) ? -(long long int)value : value;
	sign = (value < 0 && base == 10) ? -1 : 0;
	i = (sign == -1) ? 2 : 1;
	while ((n /= base) >= 1)
		i++;
	str = (char*)malloc(sizeof(char) * (i + 1));
	str[i] = '\0';
	n = (value < 0) ? -(long long int)value : value;
	while (i-- + sign)
	{
		str[i] = (n % base < 10) ? n % base + '0' : n % base + 'A' - 10;
		n /= base;
	}
	(i == 0) ? str[i] = '-' : 0;
	return (str);
}

char	*pf_uitoa(unsigned long long int value, int base)
{
	unsigned long long int	n;
	char					*str;
	int						i;

	i = 1;
	n = value;
	while ((n /= base) >= 1)
		i++;
	str = (char*)malloc(sizeof(char) * (i + 1));
	str[i] = '\0';
	n = value;
	while (i--)
	{
		str[i] = (n % base < 10) ? n % base + '0' : n % base + 'A' - 10;
		n /= base;
	}
	return (str);
}

char	*pf_strnew(size_t size)
{
	char *tmp;

	tmp = (char *)malloc(sizeof(char) * size);
	tmp[size] = '\0';
	return (tmp);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junpark <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 22:42:35 by junpark           #+#    #+#             */
/*   Updated: 2019/06/11 01:58:11 by junpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	t_flag	f;
	va_list	ap;

	va_start(ap, format);
	ft_memset(&f, 0, sizeof(t_flag));
	while (format[f.i] != '\0')
	{
		if (format[f.i] != '%')
		{
			write(1, &format[f.i], 1);
			f.i++;
			f.count++;
		}
		else
		{
			f.i++;
			f = parse_input(format, f, ap);
		}
	}
	va_end(ap);
	return (f.count);
}

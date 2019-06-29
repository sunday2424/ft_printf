/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junpark <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 14:45:55 by junpark           #+#    #+#             */
/*   Updated: 2019/06/26 03:22:04 by junpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flag	parse_input(const char *format, t_flag f, va_list ap)
{
	while (format[f.i] != '\0')
	{
		if (check_flags(format[f.i]))
			f = save_flags(format[f.i++], f);
		else if (check_width(format, f.i))
		{
			f = save_width(format, f.i, f);
			f.i += check_width(format, f.i);
		}
		else if (check_precision(format, f.i))
		{
			f = save_precision(format, f.i, f);
			f.i += check_precision(format, f.i);
		}
		else if (check_length(format[f.i]))
			f = save_length(format[f.i++], f);
		else if (check_conversion(format[f.i]))
		{
			f = print_conversion(format, f.i, f, ap);
			f.i++;
			break ;
		}
	}
	return (f);
}

int		check_flags(const char c)
{
	if (c == '-' || c == '+' || c == ' ' || c == '#' || c == '0')
		return (1);
	return (0);
}

int		check_width(const char *format, int i)
{
	int count;

	if (format[i] >= '1' && format[i] <= '9')
	{
		count = 0;
		while (format[i] >= '0' && format[i] <= '9')
		{
			i++;
			count++;
		}
		return (count);
	}
	return (0);
}

int		check_precision(const char *format, int i)
{
	int	count;

	if (format[i] == '.')
	{
		count = 1;
		i++;
		while (format[i] >= '0' && format[i] <= '9')
		{
			i++;
			count++;
		}
		return (count);
	}
	return (0);
}

int		check_length(const char c)
{
	if (c == 'h' || c == 'l')
		return (1);
	return (0);
}

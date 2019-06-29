/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_param.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junpark <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/02 14:03:15 by junpark           #+#    #+#             */
/*   Updated: 2019/06/02 14:03:19 by junpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flag	save_flags(const char c, t_flag f)
{
	if (c == '-')
		f.negative += 1;
	else if (c == '+')
		f.positive += 1;
	else if (c == ' ')
		f.space += 1;
	else if (c == '#')
		f.hash += 1;
	else if (c == '0')
		f.zero += 1;
	return (f);
}

t_flag	save_width(const char *format, int i, t_flag f)
{
	char	*tmp;
	int		count;
	int		j;

	count = check_width(format, i);
	tmp = ft_strnew(count);
	tmp[count] = '\0';
	j = 0;
	while (j < count)
	{
		tmp[j] = format[i];
		j++;
		i++;
	}
	f.w = ft_atoi(tmp);
	free(tmp);
	return (f);
}

t_flag	save_precision(const char *format, int i, t_flag f)
{
	char	*tmp;
	int		count;
	int		j;

	count = check_precision(format, i) - 1;
	tmp = ft_strnew(count);
	j = 0;
	tmp[count] = '\0';
	while (j < count)
	{
		tmp[j] = (char)format[i + 1];
		j++;
		i++;
	}
	j = ft_atoi(tmp);
	if (count == 0 || (j == 0))
		f.prec = -1;
	else
		f.prec = j;
	free(tmp);
	return (f);
}

t_flag	save_length(const char c, t_flag f)
{
	if (c == 'h' && f.length == 1)
		f.length = 2;
	else if (c == 'l' && f.length == 3)
		f.length = 4;
	else if (c == 'h')
		f.length = 1;
	else if (c == 'l')
		f.length = 3;
	return (f);
}

t_flag	handle_flags(t_flag f)
{
	if (f.positive && f.space)
		f.space = 0;
	if (f.negative || f.space || f.prec)
		f.zero = 0;
	if (f.space)
		f.space = 1;
	return (f);
}

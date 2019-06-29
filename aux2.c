/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junpark <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 00:22:06 by junpark           #+#    #+#             */
/*   Updated: 2019/06/26 03:27:16 by junpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*str_gen(char *str, t_flag f)
{
	char	*tmp;
	int		i;

	i = pf_strlen(str, f);
	tmp = pf_strnew(i);
	if (f.negative && f.prec > 0 && i > f.prec)
		tmp = case_neg(str, tmp, i, f);
	else if (f.prec > 0 && i > f.prec)
		tmp = str_gen_ext(str, tmp, i, f);
	else
		tmp = str_gen_ext2(str, tmp, i, f);
	return (tmp);
}

char	*case_neg(char *str, char *tmp, int i, t_flag f)
{
	int j;
	int k;

	ft_memset(tmp, ' ', i);
	j = (f.positive) ? 1 : 0;
	if (f.positive)
		tmp[j - 1] = (str[0] != '-') ? '+' : '-';
	k = 0;
	while (k < f.prec)
	{
		tmp[j] = '0';
		j++;
		k++;
	}
	return (tmp);
}

char	*str_gen_ext(char *str, char *tmp, int i, t_flag f)
{
	int j;

	(f.zero && (int)ft_strlen(str) <= f.prec) ? \
	ft_memset(tmp, '0', i) : ft_memset(tmp, ' ', i);
	i = ((int)ft_strlen(str) > f.prec) ? (int)ft_strlen(str) : f.prec;
	j = ((int)ft_strlen(str) > f.prec && str[0] == '-') ? \
	pf_strlen(str, f) - i + 1 : pf_strlen(str, f) - i;
	if (f.zero && (f.positive || f.space))
	{
		if (f.positive)
			tmp[0] = (str[0] != '-') ? '+' : '-';
		if (f.space)
			tmp[0] = (str[0] != '-') ? ' ' : '-';
	}
	else if (f.positive)
		tmp[j - 1] = (str[0] != '-') ? '+' : '-';
	else if (f.space)
		tmp[j - 1] = (str[0] != '-') ? ' ' : '-';
	while (tmp[j] != '\0')
		tmp[j++] = '0';
	return (tmp);
}

char	*str_gen_ext2(char *str, char *tmp, int i, t_flag f)
{
	int j;

	j = i - (int)ft_strlen(str);
	(f.zero || f.prec > (int)ft_strlen(str)) ? \
	ft_memset(tmp, '0', i) : ft_memset(tmp, ' ', i);
	if (f.positive)
	{
		if (f.zero || f.negative)
			tmp[0] = (str[0] != '-') ? '+' : '-';
		else
		{
			if (str[0] != '-')
				tmp[j - 1] = '+';
			else
				tmp[j] = '-';
		}
	}
	if (f.space)
		tmp = str_gen_ext3(str, tmp, j, f);
	return (tmp);
}

char	*str_gen_ext3(char *str, char *tmp, int j, t_flag f)
{
	if (f.zero || f.negative)
		tmp[0] = (str[0] != '-') ? '+' : '-';
	else
	{
		if (str[0] != '-')
			tmp[j - 1] = ' ';
		else
			tmp[j] = '-';
	}
	return (tmp);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auxiliary.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junpark <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 21:34:52 by junpark           #+#    #+#             */
/*   Updated: 2019/06/10 21:34:54 by junpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*hash_neg_o(char *str, char *tmp, t_flag f)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (f.negative)
	{
		j = (f.prec > (int)ft_strlen(str)) ? \
		f.prec - (int)ft_strlen(str) : j;
	}
	if (f.hash)
		tmp[j++] = '0';
	while (tmp[j] != '\0' && str[i] != '\0')
		tmp[j++] = str[i++];
	return (tmp);
}

char	*hash_neg_x(char *str, char *tmp, t_flag f, char c)
{
	int	i;
	int	j;

	i = 0;
	j = (f.prec > (int)ft_strlen(str)) ? \
	pf_strlen(str, f) - (int)ft_strlen(str) : 0;
	if (f.negative || f.zero)
	{
		tmp = hash_neg_x_ext(str, tmp, f, c);
		return (tmp);
	}
	if (f.hash && !f.negative && !f.zero)
	{
		tmp = hash_neg_x_ext2(str, tmp, f, c);
		return (tmp);
	}
	while (tmp[j] != '\0' && str[i] != '\0')
		tmp[j++] = str[i++];
	return (tmp);
}

char	*hash_neg_x_ext(char *str, char *tmp, t_flag f, char c)
{
	int i;
	int	j;

	i = 0;
	j = (f.prec > (int)ft_strlen(str)) ? \
	pf_strlen(str, f) - (int)ft_strlen(str) : 0;
	j = (f.prec > (int)ft_strlen(str)) ? f.prec - (int)ft_strlen(str) : j;
	if (f.hash)
	{
		tmp[0] = '0';
		tmp[1] = (c == 'x') ? 'x' : 'X';
		j = (pf_strlen(str, f) > (int)ft_strlen(str)) ? 2 : j;
		if (f.prec)
		{
			j = (j == 2 && (pf_strlen(str, f) < ((int)ft_strlen(str) + \
			f.prec))) ? pf_strlen(str, f) - (int)ft_strlen(str) : f.prec;
			j = (f.prec && f.prec < (int)ft_strlen(str)) ? 2 : j;
		}
	}
	while (tmp[j] != '\0' && str[i] != '\0')
		tmp[j++] = str[i++];
	return (tmp);
}

char	*hash_neg_x_ext2(char *str, char *tmp, t_flag f, char c)
{
	int	i;
	int	j;

	i = 0;
	j = (f.prec > (int)ft_strlen(str)) ? \
	pf_strlen(str, f) - (int)ft_strlen(str) : 0;
	if (f.prec > (int)ft_strlen(str) || f.zero)
		j = pf_strlen(str, f) - f.prec - 2;
	j = (f.negative) ? 0 : j;
	tmp[j++] = '0';
	tmp[j++] = (c == 'x') ? 'x' : 'X';
	j = pf_strlen(str, f) - (int)ft_strlen(str);
	while (tmp[j] != '\0' && str[i] != '\0')
		tmp[j++] = str[i++];
	return (tmp);
}

char	*hash_neg_p(char *str, char *tmp, t_flag f)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (f.hash)
	{
		tmp[j++] = '0';
		tmp[j++] = 'x';
	}
	while (tmp[j] != '\0' && str[i] != '\0')
		tmp[j++] = str[i++];
	return (tmp);
}

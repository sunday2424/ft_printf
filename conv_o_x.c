/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_o_x.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junpark <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 16:41:47 by junpark           #+#    #+#             */
/*   Updated: 2019/06/26 17:34:33 by junpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flag	handle_o(t_flag f, unsigned long long int i)
{
	unsigned long long int	tmp;
	char					*ret;

	tmp = i;
	if (f.length == 0)
		tmp = (unsigned int)tmp;
	else if (f.length == 1)
		tmp = (unsigned short int)tmp;
	else if (f.length == 2)
		tmp = (unsigned char)tmp;
	else if (f.length == 3)
		tmp = (unsigned long int)tmp;
	ret = pf_uitoa(tmp, 8);
	if (f.hash && (f.prec <= (int)ft_strlen(ret)))
		f.aw += 1;
	if (f.hash && tmp == 0)
		f.aw -= 1;
	f = print_o(ret, f);
	free(ret);
	return (f);
}

t_flag	print_o(char *str, t_flag f)
{
	char	*tmp;
	int		i;
	int		j;

	tmp = str_gen(str, f);
	i = -1;
	j = pf_strlen(str, f) - ft_strlen(str) - 1;
	if (!f.negative && pf_strlen(str, f) > (int)ft_strlen(str))
	{
		if (f.hash)
			tmp[j] = '0';
		while (tmp[++j] != '\0' && str[++i] != '\0')
			tmp[j] = str[i];
	}
	else
		tmp = hash_neg_o(str, tmp, f);
	ft_putstr(tmp);
	f.count += (int)ft_strlen(tmp);
	free(tmp);
	return (f);
}

t_flag	handle_x(t_flag f, char c, unsigned long long int i)
{
	char					*ret;
	int						a;

	a = -1;
	if (f.length == 0)
		i = (unsigned int)i;
	else if (f.length == 1)
		i = (unsigned short int)i;
	else if (f.length == 2)
		i = (unsigned char)i;
	else if (f.length == 3)
		i = (unsigned long int)i;
	ret = pf_uitoa(i, 16);
	if (c == 'x')
		while (ret[++a] != '\0')
			if (ret[a] >= 'A' && ret[a] <= 'Z')
				ret[a] += 32;
	f.hash = (i == 0) ? 0 : f.hash;
	if (f.hash && i != 0)
		f.aw += 2;
	f = print_x(ret, f, c);
	free(ret);
	return (f);
}

t_flag	print_x(char *str, t_flag f, char c)
{
	char	*tmp;

	tmp = str_gen(str, f);
	if (!f.negative && f.w > (int)ft_strlen(str))
		tmp = print_x_ext(str, tmp, f, c);
	else
		tmp = hash_neg_x(str, tmp, f, c);
	ft_putstr(tmp);
	f.count += (int)ft_strlen(tmp);
	free(tmp);
	return (f);
}

char	*print_x_ext(char *str, char *tmp, t_flag f, char c)
{
	int	i;
	int	j;
	int	k;

	i = -1;
	j = (f.w > (int)ft_strlen(str)) ? f.w - ft_strlen(str) - 1 : 0;
	if (f.hash)
	{
		j = (pf_strlen(str, f) == f.w && f.zero) ? 1 : j;
		if (f.w && f.prec)
		{
			k = (f.prec >= (int)ft_strlen(str)) ? f.prec : (int)ft_strlen(str);
			j = (pf_strlen(str, f) > k + 2) ? pf_strlen(str, f) - k - 1 : j;
		}
		tmp[j - 1] = '0';
		tmp[j] = (c == 'x') ? 'x' : 'X';
		if ((pf_strlen(str, f) == f.w && f.zero) || \
		(pf_strlen(str, f) > f.prec + 2))
			j = pf_strlen(str, f) - ft_strlen(str) - 1;
		j = (pf_strlen(str, f) == f.w && f.zero) ? \
		pf_strlen(str, f) - ft_strlen(str) - 1 : j;
	}
	while (tmp[++j] != '\0' && str[++i] != '\0')
		tmp[j] = str[i];
	return (tmp);
}

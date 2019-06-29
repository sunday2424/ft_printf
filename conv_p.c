/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_p.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junpark <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 01:09:27 by junpark           #+#    #+#             */
/*   Updated: 2019/06/11 01:09:29 by junpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flag	handle_p(t_flag f, unsigned long long int i)
{
	unsigned long long int	tmp;
	char					*ret;
	int						a;

	a = -1;
	tmp = i;
	ret = pf_uitoa(tmp, 16);
	while (ret[++a] != '\0')
		if (ret[a] >= 'A' && ret[a] <= 'Z')
			ret[a] += 32;
	f.hash = 1;
	if (f.hash)
		f.aw += 2;
	f = print_p(ret, f);
	free(ret);
	return (f);
}

t_flag	print_p(char *str, t_flag f)
{
	char	*tmp;
	int		i;
	int		j;

	i = size_x(str, f);
	tmp = ft_strnew(i);
	f.zero ? ft_memset(tmp, '0', i) : ft_memset(tmp, ' ', i);
	i = -1;
	if (f.negative == 0 && f.w > (int)ft_strlen(str))
	{
		j = (f.w > (int)ft_strlen(str)) ? f.w - ft_strlen(str) - 1 : 0;
		if (f.hash)
		{
			tmp[j - 1] = '0';
			tmp[j] = 'x';
		}
		while (tmp[++j] != '\0' && str[++i] != '\0')
			tmp[j] = str[i];
	}
	else
		tmp = hash_neg_p(str, tmp, f);
	ft_putstr(tmp);
	f.count += (int)ft_strlen(tmp);
	free(tmp);
	return (f);
}

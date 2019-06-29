/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_u.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junpark <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 17:33:27 by junpark           #+#    #+#             */
/*   Updated: 2019/06/26 17:34:16 by junpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flag	handle_u(t_flag f, unsigned long long int i)
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
	ret = pf_uitoa(tmp, 10);
	if (f.positive)
		f.aw += 1;
	if (f.space)
		f.aw += 1;
	f = print_u(ret, f);
	free(ret);
	return (f);
}

t_flag	print_u(char *str, t_flag f)
{
	char	*tmp;
	int		i;
	int		j;

	tmp = str_gen(str, f);
	i = -1;
	j = pf_strlen(str, f) - ft_strlen(str) - 1;
	if (!f.negative && pf_strlen(str, f) > (int)ft_strlen(str))
	{
		if (f.positive && str[0] != '-')
			tmp = zero_plus(tmp, f, j);
		while (tmp[++j] != '\0' && str[++i] != '\0')
			tmp[j] = str[i];
	}
	else
		tmp = print_u_ext(str, tmp, j, f);
	ft_putstr(tmp);
	f.count += (int)ft_strlen(tmp);
	free(tmp);
	return (f);
}

char	*print_u_ext(char *str, char *tmp, int j, t_flag f)
{
	int	i;

	i = -1;
	if (f.negative && (pf_strlen(str, f) > (int)ft_strlen(str)))
	{
		j = (f.prec) ? f.prec - (int)ft_strlen(str) - 1 : -1;
		j = (j < -1 && f.prec != -1) ? -1 : j;
		while (tmp[++j] != '\0' && str[++i] != '\0')
			tmp[j] = str[i];
	}
	else
		while (tmp[++j] != '\0' && str[++i] != '\0')
			tmp[j] = str[i];
	return (tmp);
}

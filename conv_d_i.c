/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_d_i.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junpark <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 16:41:38 by junpark           #+#    #+#             */
/*   Updated: 2019/06/26 17:35:40 by junpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flag	handle_d_i(t_flag f, long long int i)
{
	long long int	tmp;
	char			*ret;

	tmp = i;
	if (f.length == 0)
		tmp = (int)tmp;
	else if (f.length == 1)
		tmp = (short int)tmp;
	else if (f.length == 2)
		tmp = (char)tmp;
	else if (f.length == 3)
		tmp = (long int)tmp;
	if (tmp < 0)
		f.positive = 1;
	ret = pf_itoa(tmp, 10);
	if ((f.positive && ret[0] != '-') || ((ret[0] == '-') && \
	(f.prec > (int)ft_strlen(ret))) || (f.space && ret[0] != '-'))
		f.aw += 1;
	f = print_d_i(ret, f);
	free(ret);
	return (f);
}

t_flag	print_d_i(char *str, t_flag f)
{
	char	*tmp;
	int		i;
	int		j;

	i = (str[0] == '-') ? 1 : 0;
	j = pf_strlen(str, f);
	tmp = str_gen(str, f);
	if (!f.negative && (j > (int)ft_strlen(str)))
	{
		j = (str[0] == '-') ? pf_strlen(str, f) - (int)ft_strlen(str) + 1 \
		: pf_strlen(str, f) - (int)ft_strlen(str);
		while (tmp[j] != '\0' && str[i] != '\0')
			tmp[j++] = str[i++];
	}
	else
		tmp = print_d_i_ext(str, tmp, j, f);
	ft_putstr(tmp);
	f.count += (int)ft_strlen(tmp);
	free(tmp);
	return (f);
}

char	*print_d_i_ext(char *str, char *tmp, int j, t_flag f)
{
	int i;

	i = (str[0] == '-') ? 1 : 0;
	if (f.negative)
	{
		j = (str[0] == '-') ? 1 : 0;
		if (j == 0 && f.space && str[0] != '-')
		{
			tmp[0] = ' ';
			j = 1;
		}
		if (f.prec > (int)ft_strlen(str))
			j = (f.positive) ? j + (f.prec - (int)ft_strlen(str)) + 1 \
			: j + (f.prec - (int)ft_strlen(str));
		while (tmp[j] != '\0' && str[i] != '\0')
			tmp[j++] = str[i++];
	}
	else
		tmp = print_d_i_ext2(str, tmp, j, f);
	return (tmp);
}

char	*print_d_i_ext2(char *str, char *tmp, int j, t_flag f)
{
	int	i;

	i = (str[0] == '-') ? 1 : 0;
	if (f.space || f.positive)
		j = (str[0] == '-') ? j - (int)ft_strlen(str) + 1 : \
		j - (int)ft_strlen(str);
	else
		j = (str[0] == '-') ? 1 : 0;
	while (tmp[j] != '\0' && str[i] != '\0')
		tmp[j++] = str[i++];
	return (tmp);
}

int		pf_strlen(char *str, t_flag f)
{
	int	i;

	i = ((int)ft_strlen(str) > f.prec) ? ft_strlen(str) : f.prec;
	if (i >= f.w)
		i = i + f.aw;
	else
		i = f.w;
	return (i);
}

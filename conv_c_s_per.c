/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_c_s_per.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junpark <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 23:22:52 by junpark           #+#    #+#             */
/*   Updated: 2019/06/26 03:25:15 by junpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flag	handle_s(t_flag f, char *str)
{
	char	*tmp;
	int		i;
	int		a;

	if (str)
	{
		a = (f.w > (int)ft_strlen(str)) ? f.w : ft_strlen(str);
		i = -1;
		tmp = pf_strnew(a);
		ft_memset(tmp, ' ', a);
		tmp = handle_s_ext(str, tmp, i, f);
		ft_putstr(tmp);
		f.count += (int)ft_strlen(tmp);
	}
	else
	{
		tmp = ft_strdup("(null)");
		ft_putstr(tmp);
		f.count += (int)ft_strlen(tmp);
	}
	free(tmp);
	return (f);
}

char	*handle_s_ext(char *str, char *tmp, int i, t_flag f)
{
	int j;

	if (f.negative == 0 && (f.w > (int)ft_strlen(str)))
	{
		j = f.w - ft_strlen(str) - 1;
		if (!f.prec)
			while (tmp[++j] != '\0' && str[++i] != '\0')
				tmp[j] = str[i];
		else
			while (tmp[++j] != '\0' && str[++i] != '\0' && i < f.prec)
				tmp[j] = str[i];
	}
	else
	{
		if (!f.prec)
			while (tmp[++i] != '\0' && str[i] != '\0')
				tmp[i] = str[i];
		else
			while (tmp[++i] != '\0' && str[i] != '\0' && i < f.prec)
				tmp[i] = str[i];
	}
	return (tmp);
}

t_flag	handle_c(t_flag f, char c)
{
	char	*tmp;
	int		i;
	int		a;

	i = 0;
	a = (f.w > 1) ? f.w : 1;
	tmp = ft_strnew(a);
	ft_memset(tmp, ' ', a);
	if (f.negative && (f.w > 1))
		while (tmp[i] != '\0')
		{
			if (i == 0)
				tmp[i] = c;
			i++;
		}
	else
		tmp[ft_strlen(tmp) - 1] = c;
	ft_putstr(tmp);
	i = 0;
	if (c == 0 || c == -0)
		handle_c_ext(tmp);
	f.count += (c == 0 || c == -0) ? 1 : (int)ft_strlen(tmp);
	free(tmp);
	return (f);
}

void	handle_c_ext(char *tmp)
{
	tmp[0] = 0;
	write(1, &tmp[0], 1);
}

t_flag	handle_perc(t_flag f)
{
	char	*tmp;
	int		i;
	int		a;

	i = 0;
	a = (f.w > 1) ? f.w : 1;
	tmp = ft_strnew(a);
	f.zero ? ft_memset(tmp, '0', a) : ft_memset(tmp, ' ', a);
	if (f.negative && (f.w > 1))
		tmp[0] = '%';
	else
		tmp[a - 1] = '%';
	ft_putstr(tmp);
	f.count += (int)ft_strlen(tmp);
	free(tmp);
	return (f);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junpark <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 18:24:21 by junpark           #+#    #+#             */
/*   Updated: 2019/06/27 18:24:22 by junpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		size_x(char *str, t_flag f)
{
	int	i;
	int	ret;

	if (f.aw != 0)
	{
		i = ft_strlen(str) - f.w;
		if (i == 1)
			ret = f.w + f.aw;
		else if (i == -1)
			ret = ft_strlen(str) + f.aw;
		else
			ret = ((int)ft_strlen(str) >= f.w) ? ft_strlen(str) + f.aw : f.w;
		return (ret);
	}
	ret = ((int)ft_strlen(str) >= f.w) ? ft_strlen(str) + f.aw : f.w;
	return (ret);
}

char	*zero_plus(char *str, t_flag f, int i)
{
	if (f.positive && str[i] == ' ')
		str[i] = '+';
	else if (f.positive && str[i] == '0')
		str[0] = '+';
	return (str);
}

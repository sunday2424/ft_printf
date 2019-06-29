/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junpark <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 22:42:41 by junpark           #+#    #+#             */
/*   Updated: 2019/06/26 03:25:43 by junpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <unistd.h>
# include <stdarg.h>

typedef struct	s_flag
{
	int			positive;
	int			negative;
	int			space;
	int			hash;
	int			zero;
	int			w;
	int			prec;
	int			length;
	int			aw;
	int			i;
	int			count;
}				t_flag;

int				ft_printf(const char *format, ...);

t_flag			parse_input(const char *format, t_flag f, va_list ap);
int				check_flags(const char c);
int				check_width(const char *format, int i);
int				check_precision(const char *format, int i);
int				check_length(const char c);

t_flag			save_flags(const char c, t_flag f);
t_flag			save_width(const char *format, int i, t_flag f);
t_flag			save_precision(const char *format, int i, t_flag f);
t_flag			save_length(const char c, t_flag f);
t_flag			handle_flags(t_flag f);

t_flag			print_conversion(const char *format, int a, t_flag f, \
				va_list ap);
int				check_conversion(const char c);
char			*pf_itoa(long long int value, int base);
char			*pf_uitoa(unsigned long long int value, int base);
char			*pf_strnew(size_t size);

char			*str_gen(char *str, t_flag f);
char			*case_neg(char *str, char *tmp, int i, t_flag f);
char			*str_gen_ext(char *str, char *tmp, int i, t_flag f);
char			*str_gen_ext2(char *str, char *tmp, int i, t_flag f);
char			*str_gen_ext3(char *str, char *tmp, int j, t_flag f);

t_flag			handle_s(t_flag f, char *str);
char			*handle_s_ext(char *str, char *tmp, int i, t_flag f);
t_flag			handle_c(t_flag f, char c);
void			handle_c_ext(char *tmp);
t_flag			handle_perc(t_flag f);

t_flag			handle_u(t_flag f, unsigned long long int i);
t_flag			print_u(char *str, t_flag f);
char			*print_u_ext(char *str, char *tmp, int j, t_flag f);

t_flag			handle_d_i(t_flag f, long long int i);
t_flag			print_d_i(char *str, t_flag f);
char			*print_d_i_ext(char *str, char *tmp, int j, t_flag f);
char			*print_d_i_ext2(char *str, char *tmp, int j, t_flag f);
int				pf_strlen(char *str, t_flag f);

t_flag			handle_o(t_flag f, unsigned long long int i);
t_flag			print_o(char *str, t_flag f);
t_flag			handle_x(t_flag f, char c, unsigned long long int i);
t_flag			print_x(char *str, t_flag f, char c);
char			*print_x_ext(char *str, char *tmp, t_flag f, char c);

t_flag			handle_p(t_flag f, unsigned long long int i);
t_flag			print_p(char *str, t_flag f);

char			*hash_neg_o(char *str, char *tmp, t_flag f);
char			*hash_neg_x(char *str, char *tmp, t_flag f, char c);
char			*hash_neg_x_ext(char *str, char *tmp, t_flag f, char c);
char			*hash_neg_x_ext2(char *str, char *tmp, t_flag f, char c);
char			*hash_neg_p(char *str, char *tmp, t_flag f);

int				size_x(char *str, t_flag f);
char			*zero_plus(char *str, t_flag f, int i);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpitic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 16:07:40 by bpitic            #+#    #+#             */
/*   Updated: 2018/03/29 16:41:52 by bpitic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <wchar.h>
# include <fcntl.h>

typedef struct	s_vars
{
	int			nr;
	int			k;
	int			mn;
	int			mx;
	int			ret;
	char		c;
	char		*s;
	char		*sp;
	int			i;
}				t_vars;

int				ft_printf(const char *restrict format, ...);
void			first_param(int *index, char *format, t_vars *z);
void			other_params1(int *index, char *format, t_vars *z, va_list arg);
void			other_params2(int *index, char *format, t_vars *z, va_list arg);
void			case_c(t_vars *z, int *index, char *format, va_list arg);
void			case_d_or_i(int *index, t_vars *z, char *format, va_list arg);
void			case_u(int *index, t_vars *z, char *format, va_list arg);
void			case_s(int *index, t_vars *z, char *format, va_list arg);
void			min_width(t_vars *z, int *index, char *format);
void			increment(int *index, char *format);
void			just_print(int *index, char *format, t_vars *z);
void			precision(t_vars *z, int *index, char *format);
void			case_x(int *index, t_vars *z, char *format, va_list arg);
void			case_bigx(int *index, t_vars *z, char *format, va_list arg);
void			case_o(int *index, t_vars *z, char *format, va_list arg);
void			case_bigs(int *index, t_vars *z, char *format, va_list arg);
void			case_bigc(int *index, t_vars *z, char *format, va_list arg);
void			case_p(int *index, t_vars *z, char *format, va_list arg);
void			case_ll_d_i(int *index, t_vars *z, char *format, va_list arg);
void			case_j_d(int *index, t_vars *z, char *format, va_list arg);
void			case_h_d_i(int *index, t_vars *z, char *format, va_list arg);
void			case_ll_x(int *index, t_vars *z, char *format, va_list arg);
void			case_j_x(int *index, t_vars *z, char *format, va_list arg);
void			case_h_x(int *index, t_vars *z, char *format, va_list arg);
void			case_hh_x(int *index, t_vars *z, char *format, va_list arg);
void			case_hh_d_i(int *index, t_vars *z, char *format, va_list arg);
void			case_procent(int *index, t_vars *z, char *format);
void			case_h_u(int *index, t_vars *z, char *format, va_list arg);
void			case_j_u(int *index, t_vars *z, char *format, va_list arg);
void			case_ll_u(int *index, t_vars *z, char *format, va_list arg);
void			case_h_o(int *index, t_vars *z, char *format, va_list arg);
void			case_j_o(int *index, t_vars *z, char *format, va_list arg);
void			case_ll_o(int *index, t_vars *z, char *format, va_list arg);
void			case_hh_o(int *index, t_vars *z, char *format, va_list arg);
int				ft_len2(unsigned long long i);
void			ft_putnbr2(unsigned int i);
int				prec1(int index, char *format);
char			*crop(char *str, int mx);
int				ft_len(unsigned int i);
char			*convert2(unsigned int num, int base);
char			*convert1(unsigned int num, int base);
char			*prec2(char *str, int mx);
int				ft_strlen2(int *d);
int				find_flag(int index, char *str, char c);
int				check_flags(int index, char *str);
char			*add_sign(char *str);
void			jump_flags(int *index, char *format);
char			*convert3(unsigned long long num, int base);
int				*crop2(int *str, int mx);
char			*convert4(unsigned long long num, int base);
char			*convert5(unsigned long long num, int base);
char			*conv_for_x(int *index, char *format, unsigned long long i);
char			*for_x_flag(int *index, char *format);
int				case_zero(int *index, char *format);
char			*ft_itoa3(uintmax_t nbr);
char			*ft_itoa2(unsigned long long nbr);
char			*convert6(int num, int base);
void			chestie(char *s, t_vars *z);
void			noflags_d_i(int *index, char *format, t_vars *z, int *i);
void			noflags_c(int *index, char *format, t_vars *z, char *c);
void			noflags_u(int *index, char *format, t_vars *z, unsigned int *i);
void			noflags_s(int *index, char *format, t_vars *z, char *s);
void			noflags_x(int *index, char *format, t_vars *z, int *i);
void			noflags_bigx(int *index, char *format, t_vars *z, int *i);
void			noflags_o(int *index, char *format, t_vars *z, int *i);
void			noflags_bigs(int *index, char *format, t_vars *z, int *s);
void			noflags_bigc(int *index, char *format, t_vars *z, wint_t c);
void			noflags_ll_d_i(int *g, char *format, t_vars *z, long long *i);
void			noflags_j_d(int *index, char *format, t_vars *z, intmax_t *i);
void			noflags_h_d_i(int *index, char *format, t_vars *z, short *i);
void			noflags_ll_x(int *g, char *f, t_vars *z, unsigned long long *i);
void			noflags_j_x(int *index, char *format, t_vars *z, uintmax_t *i);
void			noflags_h_x(int *ind, char *frmt, t_vars *z, unsigned short *i);
void			noflags_hh_x(int *ind, char *frmt, t_vars *z, unsigned char *i);
void			noflags_hh_d_i(int *ind, char *frmt, t_vars *z, signed char *i);
void			noflags_h_u(int *ind, char *frmt, t_vars *z, unsigned long *i);
void			noflags_j_u(int *index, char *format, t_vars *z, uintmax_t *i);
void			noflags_ll_u(int *g, char *f, t_vars *z, unsigned long long *i);
void			noflags_h_o(int *ind, char *frmt, t_vars *z, unsigned short *i);
void			noflags_j_o(int *index, char *format, t_vars *z, uintmax_t *i);
void			noflags_ll_o(int *g, char *f, t_vars *z, unsigned long long *i);
void			noflags_hh_o(int *ind, char *frmt, t_vars *z, unsigned char *i);
void			flags_d_i(int *index, char *format, t_vars *z, int *i);
void			flags_ll_d_i(int *index, char *format, t_vars *z, long long *i);
void			flags_j_d(int *index, char *format, t_vars *z, intmax_t *i);
void			flags_h_d_i(int *index, char *format, t_vars *z, short *i);
void			flags_hh_d_i(int *ind, char *format, t_vars *z, signed char *i);
void			flags_bigs(int *index, char *format, t_vars *z, int *s);
void			flags_x(int *index, char *format, t_vars *z, int *i);
void			flags_ll_x(int *ind, char *f, t_vars *z, unsigned long long *i);
void			flags_j_x(int *index, char *format, t_vars *z, uintmax_t *i);
void			flags_h_x(int *ind, char *frmt, t_vars *z, unsigned short *i);
void			flags_hh_x(int *ind, char *format, t_vars *z, unsigned char *i);
void			flags_bigx(int *index, char *format, t_vars *z, int *i);
void			flags_o(int *index, char *format, t_vars *z, int *i);
void			flags_c(int *index, char *format, t_vars *z, char *c);
void			flags_s(int *index, char *format, t_vars *z, char *s);
void			flags_u(int *index, char *format, t_vars *z, unsigned int *i);
void			flags_h_u(int *ind, char *format, t_vars *z, unsigned long *i);
void			flags_j_u(int *ind, char *format, t_vars *z, unsigned long *i);
void			flags_ll_u(int *in, char *f, t_vars *z, unsigned long long *i);
void			flags_h_o(int *ind, char *format, t_vars *z, unsigned short *i);
void			flags_j_o(int *ind, char *format, t_vars *z, unsigned long *i);
void			flags_ll_o(int *in, char *f, t_vars *z, unsigned long long *i);
void			flags_p(int *ind, char *frmt, t_vars *z, unsigned long long *i);
void			flags_hh_o(int *ind, char *frmt, t_vars *z, unsigned char *i);
void			chestie1(t_vars *z);
void			chestie2(int *index, char *format, t_vars *z, int *i);

#endif

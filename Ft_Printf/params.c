/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   params.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpitic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 16:09:22 by bpitic            #+#    #+#             */
/*   Updated: 2018/03/29 16:09:28 by bpitic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

void	first_param(int *index, char *format, t_vars *z)
{
	just_print(index, (char*)format, z);
	jump_flags(index, (char*)format);
	min_width(z, index, (char*)format);
	precision(z, index, (char*)format);
}

void	other_params1(int *index, char *format, t_vars *z, va_list arg)
{
	case_procent(index, z, (char*)format);
	case_c(z, index, (char*)format, arg);
	case_ll_d_i(index, z, (char*)format, arg);
	case_j_d(index, z, (char*)format, arg);
	case_h_d_i(index, z, (char*)format, arg);
	case_hh_d_i(index, z, (char*)format, arg);
	case_d_or_i(index, z, (char*)format, arg);
	case_s(index, z, (char*)format, arg);
	case_j_u(index, z, (char*)format, arg);
	case_h_u(index, z, (char*)format, arg);
	case_ll_u(index, z, (char*)format, arg);
	case_u(index, z, (char*)format, arg);
	case_ll_x(index, z, (char*)format, arg);
}

void	other_params2(int *index, char *format, t_vars *z, va_list arg)
{
	case_j_x(index, z, (char*)format, arg);
	case_h_x(index, z, (char*)format, arg);
	case_hh_x(index, z, (char*)format, arg);
	case_x(index, z, (char*)format, arg);
	case_bigx(index, z, (char*)format, arg);
	case_j_o(index, z, (char*)format, arg);
	case_hh_o(index, z, (char*)format, arg);
	case_h_o(index, z, (char*)format, arg);
	case_ll_o(index, z, (char*)format, arg);
	case_o(index, z, (char*)format, arg);
	case_bigs(index, z, (char*)format, arg);
	case_bigc(index, z, (char*)format, arg);
	case_p(index, z, (char*)format, arg);
}

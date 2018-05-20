/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpitic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 16:07:26 by bpitic            #+#    #+#             */
/*   Updated: 2018/03/29 19:15:54 by bpitic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

int		ft_printf(const char *restrict format, ...)
{
	int				index;
	va_list			arg;
	t_vars			*z;

	z = (t_vars*)malloc(sizeof(t_vars));
	va_start(arg, format);
	index = 0;
	z->ret = 0;
	while (format[index])
	{
		first_param(&index, (char*)format, z);
		other_params1(&index, (char*)format, z, arg);
		other_params2(&index, (char*)format, z, arg);
		increment(&index, (char*)format);
	}
	va_end(arg);
	return (z->ret);
}

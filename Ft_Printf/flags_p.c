/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpitic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 16:06:33 by bpitic            #+#    #+#             */
/*   Updated: 2018/03/29 16:06:39 by bpitic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

void	flags_p(int *ind, char *frmt, t_vars *z, unsigned long long *i)
{
	z->s = convert3(*i, 16);
	z->nr = z->mn - ft_strlen(z->s);
	if (find_flag(*ind, frmt, '0') && find_flag(*ind, frmt, '-') == 0)
		z->c = '0';
	else
		z->c = ' ';
	if (find_flag(*ind, frmt, '-'))
		ft_putstr(z->s);
	while (z->nr > 0)
	{
		ft_putchar(z->c);
		z->ret++;
		z->nr--;
	}
	if (z->c == '0')
		ft_putstr(z->s);
	z->ret = z->ret + ft_strlen(z->s);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpitic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 16:02:50 by bpitic            #+#    #+#             */
/*   Updated: 2018/03/29 16:02:58 by bpitic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

void	flags_c(int *index, char *format, t_vars *z, char *c)
{
	if (find_flag(*index - 1, format, '0')
			&& !find_flag(*index - 1, format, '-'))
		z->c = '0';
	else
		z->c = ' ';
	z->mn = z->mn - 1;
	z->ret++;
	if (find_flag(*index - 1, format, '-'))
		ft_putchar(*c);
	while (z->mn > 0)
	{
		ft_putchar(z->c);
		z->mn--;
		z->ret++;
	}
	if (!find_flag(*index - 1, format, '-'))
		ft_putchar(*c);
}

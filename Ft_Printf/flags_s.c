/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpitic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 16:06:43 by bpitic            #+#    #+#             */
/*   Updated: 2018/03/29 16:06:49 by bpitic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

void	flags_s(int *index, char *format, t_vars *z, char *s)
{
	z->nr = 0;
	if (find_flag(*index - 1, format, '-'))
	{
		if (ft_isdigit(format[*index - 1]))
		{
			if (prec1(*index - 1, format) == 1)
				if (z->mx < (int)ft_strlen(s))
					s = crop(s, z->mx);
			z->nr = z->mn - ft_strlen(s);
		}
		ft_putstr(s);
		z->ret = z->ret + ft_strlen(s);
		while (z->nr > 0)
		{
			ft_putchar(' ');
			z->ret++;
			z->nr--;
		}
	}
}

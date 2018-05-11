/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_bigs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpitic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 16:02:08 by bpitic            #+#    #+#             */
/*   Updated: 2018/03/29 16:02:20 by bpitic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

void	flags_bigs(int *index, char *format, t_vars *z, int *s)
{
	if (find_flag(*index - 1, format, '-'))
	{
		if (ft_isdigit(format[*index - 1]))
		{
			if (prec1(*index - 1, format) == 1)
				if (z->mx < (int)ft_strlen2(s))
					s = crop2(s, z->mx);
			z->nr = z->mn - ft_strlen2(s);
		}
		z->i = 0;
		z->ret = z->ret + ft_strlen2(s);
		while (s[z->i])
		{
			write(1, s + z->i, 1);
			z->ret++;
			z->i++;
		}
		while (z->nr > 0)
		{
			ft_putchar(' ');
			z->ret++;
			z->nr--;
		}
	}
}

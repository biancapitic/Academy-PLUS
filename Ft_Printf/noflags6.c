/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   noflags6.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpitic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 16:09:06 by bpitic            #+#    #+#             */
/*   Updated: 2018/03/29 16:09:12 by bpitic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

void	chestie1(t_vars *z)
{
	while (z->nr > 0)
	{
		ft_putchar(' ');
		z->ret++;
		z->nr--;
	}
}

void	chestie2(int *index, char *format, t_vars *z, int *i)
{
	if (prec1(*index - 1, format) == 1)
		if (z->mx > (int)ft_strlen(z->s))
			z->s = prec2(z->s, z->mx);
	z->nr = z->mn - ft_strlen(z->s);
	if (*i < 0)
		z->nr--;
	if (*i == 0)
		z->nr++;
	chestie1(z);
	if (*i < 0)
	{
		ft_putchar('-');
		z->ret++;
	}
}

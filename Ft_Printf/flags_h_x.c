/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_h_x.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpitic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 16:03:54 by bpitic            #+#    #+#             */
/*   Updated: 2018/03/29 16:04:01 by bpitic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

static	void	computez1(int *index, char *frmt, t_vars *z, unsigned short *i)
{
	if (find_flag(*index, frmt, '#') && *i != 0)
	{
		z->k = 2;
		z->nr = z->nr - 2;
		z->ret = z->ret + 2;
	}
	if (find_flag(*index, frmt, '-'))
	{
		if (z->k == 2 && *i != 0)
			ft_putstr(z->sp);
		if ((*i == 0 && case_zero(index, frmt)) || *i != 0)
		{
			ft_putstr(z->s);
			z->ret = z->ret + ft_strlen(z->s);
		}
	}
	if (z->k == 2 && z->c == '0')
		ft_putstr(z->sp);
}

static	void	computez2(int *index, char *frmt, t_vars *z, unsigned short *i)
{
	if (*i == 0 && (frmt[*index - 1] == '.' || (frmt[*index - 1] == '0'
					&& frmt[*index - 2] == '.')))
		z->nr++;
	while (z->nr > 0)
	{
		ft_putchar(z->c);
		z->nr--;
		z->ret++;
	}
	if (((z->c == ' ' && !find_flag(*index, frmt, '-')) || z->c == '0'))
	{
		if (z->c != '0' && z->k == 2 && *i != 0)
			ft_putstr(z->sp);
		if ((*i == 0 && case_zero(index, frmt)) || *i != 0)
		{
			z->ret = z->ret + ft_strlen(z->s);
			ft_putstr(z->s);
		}
	}
}

void			flags_h_x(int *index, char *frmt, t_vars *z, unsigned short *i)
{
	z->s = conv_for_x(index, frmt, *i);
	z->k = 0;
	z->nr = z->mn - ft_strlen(z->s);
	z->sp = for_x_flag(index, frmt);
	if (find_flag(*index, frmt, '0') && find_flag(*index, frmt, '-') == 0
			&& prec1(*index - 1, frmt) != 1 && ((*i == 0
					&& case_zero(index, frmt)) || *i != 0) &&
			frmt[*index - 1] != '.')
		z->c = '0';
	else
		z->c = ' ';
	if (prec1(*index - 1, frmt) == 1)
	{
		if (z->mx - (int)ft_strlen(z->s) > 0)
			z->nr = z->nr - (z->mx - (int)ft_strlen(z->s));
		if (z->mx > (int)ft_strlen(z->s))
			z->s = prec2(z->s, z->mx);
	}
	computez1(index, frmt, z, i);
	computez2(index, frmt, z, i);
}

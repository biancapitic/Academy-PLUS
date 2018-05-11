/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_ll_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpitic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 16:06:09 by bpitic            #+#    #+#             */
/*   Updated: 2018/03/29 16:06:16 by bpitic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

static	void	computez1(int *ind, char *f, t_vars *z, unsigned long long *i)
{
	if (prec1(*ind - 1, f) == 1)
	{
		if (z->mx - (int)ft_strlen(z->s) > 0)
			z->nr = z->nr - (z->mx - (int)ft_strlen(z->s));
		if (z->mx > (int)ft_strlen(z->s))
			z->s = prec2(z->s, z->mx);
	}
	if (find_flag(*ind, f, '#') && *i != 0)
	{
		z->k = 2;
		z->nr = z->nr - 2;
		z->ret = z->ret + 2;
	}
	if (find_flag(*ind, f, '-'))
	{
		if (z->k == 2 && *i != 0)
			ft_putstr(z->sp);
		if ((*i == 0 && case_zero(ind, f)) || *i != 0)
		{
			ft_putstr(z->s);
			z->ret = z->ret + ft_strlen(z->s);
		}
	}
}

static	void	computez2(int *ind, char *f, t_vars *z, unsigned long long *i)
{
	if (z->k == 2 && z->c == '0')
		ft_putstr(z->sp);
	if (*i == 0 && (f[*ind - 1] == '.' || (f[*ind - 1] == '0'
					&& f[*ind - 2] == '.')))
		z->nr++;
	while (z->nr > 0)
	{
		ft_putchar(z->c);
		z->nr--;
		z->ret++;
	}
	if (((z->c == ' ' && !find_flag(*ind, f, '-')) || z->c == '0'))
	{
		if (z->c != '0' && z->k == 2 && *i != 0)
			ft_putstr(z->sp);
		if ((*i == 0 && case_zero(ind, f)) || *i != 0)
		{
			z->ret = z->ret + ft_strlen(z->s);
			ft_putstr(z->s);
		}
	}
}

void			flags_ll_x(int *ind, char *f, t_vars *z, unsigned long long *i)
{
	z->s = conv_for_x(ind, f, *i);
	z->k = 0;
	z->nr = z->mn - ft_strlen(z->s);
	z->sp = for_x_flag(ind, f);
	if (find_flag(*ind, f, '0') && find_flag(*ind, f, '-') == 0
			&& prec1(*ind - 1, f) != 1 && ((*i == 0
					&& case_zero(ind, f)) || *i != 0) &&
			f[*ind - 1] != '.')
		z->c = '0';
	else
		z->c = ' ';
	computez1(ind, f, z, i);
	computez2(ind, f, z, i);
}

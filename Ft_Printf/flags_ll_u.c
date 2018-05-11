/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_ll_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpitic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 16:05:53 by bpitic            #+#    #+#             */
/*   Updated: 2018/03/29 16:06:03 by bpitic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

static	void	computez1(int *ind, char *f, t_vars *z, unsigned long long *i)
{
	if (prec1(*ind - 1, f) == 1)
	{
		if (z->s[0] == '-')
			z->nr = z->nr - (z->mx - (int)ft_strlen(z->s)) - 1;
		else if (z->mx >= (int)ft_strlen(z->s))
			z->nr = z->nr - (z->mx - (int)ft_strlen(z->s));
		if (z->mx > (int)ft_strlen(z->s))
			z->s = prec2(z->s, z->mx);
	}
	if (find_flag(*ind, f, '-') && ((*i == 0
					&& case_zero(ind, f)) || *i != 0))
	{
		ft_putstr(z->s);
		z->ret = z->ret + ft_strlen(z->s);
		while (z->nr > 0)
		{
			ft_putchar(z->c);
			z->ret++;
			z->nr--;
		}
	}
}

static	void	computez2(int *ind, char *f, t_vars *z, unsigned long long *i)
{
	if (z->c == '0')
	{
		z->k = 0;
		if (z->s[0] == '-' || z->s[0] == '+')
		{
			ft_putchar(z->s[0]);
			z->ret++;
			z->k = 1;
		}
	}
	if (*i == 0 && !case_zero(ind, f))
		z->nr++;
	while (z->nr > 0)
	{
		ft_putchar(z->c);
		z->ret++;
		z->nr--;
	}
	if (z->c == '0' && z->k == 1)
	{
		z->ret = z->ret + ft_strlen(z->s) - 1;
		ft_putstr(z->s + 1);
	}
}

void			flags_ll_u(int *ind, char *f, t_vars *z, unsigned long long *i)
{
	z->k = -1;
	z->s = ft_itoa2(*i);
	z->nr = z->mn - ft_strlen(z->s);
	if (find_flag(*ind, f, '0') && find_flag(*ind, f, '-') == 0
			&& prec1(*ind - 1, f) != 1 && ((*i == 0
					&& case_zero(ind, f)) || *i != 0)
			&& f[*ind - 1] != '.')
		z->c = '0';
	else
		z->c = ' ';
	computez1(ind, f, z, i);
	computez2(ind, f, z, i);
	if ((z->c == ' ' && !find_flag(*ind, f, '-')) || z->k == 0)
		if ((*i == 0 && case_zero(ind, f)) || *i != 0)
		{
			ft_putstr(z->s);
			z->ret = z->ret + ft_strlen(z->s);
		}
}

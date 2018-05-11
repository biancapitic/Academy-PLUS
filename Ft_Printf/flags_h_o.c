/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_h_o.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpitic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 16:03:30 by bpitic            #+#    #+#             */
/*   Updated: 2018/03/29 16:03:36 by bpitic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

static	void	computez1(int *index, char *frmt, t_vars *z, unsigned short *i)
{
	if (prec1(*index - 1, frmt) == 1)
	{
		if (z->s[0] == '-')
			z->nr = z->nr - (z->mx - (int)ft_strlen(z->s)) - 1;
		else if (z->mx >= (int)ft_strlen(z->s))
			z->nr = z->nr - (z->mx - (int)ft_strlen(z->s));
		if (z->mx > (int)ft_strlen(z->s) ||
				(z->s[0] == '-' && z->mx > (int)ft_strlen(z->s) - 1))
			z->s = prec2(z->s, z->mx);
	}
	if (find_flag(*index, frmt, '-') && ((*i == 0
					&& case_zero(index, frmt)) || *i != 0))
	{
		ft_putstr(z->s);
		z->ret = z->ret + ft_strlen(z->s);
	}
}

static	void	computez2(int *index, char *frmt, t_vars *z, unsigned short *i)
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
	if (*i == 0 && !case_zero(index, frmt))
		z->nr++;
	while (z->nr > 0)
	{
		ft_putchar(z->c);
		z->ret++;
		z->nr--;
	}
}

static	void	computez3(int *index, char *frmt, t_vars *z, unsigned short *i)
{
	if (z->c == '0' && z->k == 1)
	{
		z->ret = z->ret + ft_strlen(z->s) - 1;
		ft_putstr(z->s + 1);
	}
	else if (!case_zero(index, frmt) && *i == 0
			&& (z->s[0] == '+' || z->s[0] == '-'))
		ft_putchar(z->s[0]);
	if ((z->c == ' ' && !find_flag(*index, frmt, '-')) || z->k == 0)
		if ((*i == 0 && case_zero(index, frmt)) || *i != 0)
		{
			ft_putstr(z->s);
			z->ret = z->ret + ft_strlen(z->s);
		}
}

void			flags_h_o(int *index, char *frmt, t_vars *z, unsigned short *i)
{
	z->k = -1;
	z->s = convert1(*i, 8);
	z->nr = z->mn - ft_strlen(z->s);
	if (find_flag(*index, frmt, '0') && find_flag(*index, frmt, '-') == 0
			&& prec1(*index - 1, frmt) != 1 && ((*i == 0
					&& case_zero(index, frmt)) || *i != 0)
			&& frmt[*index - 1] != '.')
		z->c = '0';
	else
		z->c = ' ';
	computez1(index, frmt, z, i);
	computez2(index, frmt, z, i);
	computez3(index, frmt, z, i);
}

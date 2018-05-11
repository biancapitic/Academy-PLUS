/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_bigx.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpitic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 16:02:27 by bpitic            #+#    #+#             */
/*   Updated: 2018/03/29 16:02:41 by bpitic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

static	void	computez1(int *index, char *format, t_vars *z, int *i)
{
	if (prec1(*index - 1, format) == 1)
	{
		if (z->mx - (int)ft_strlen(z->s) > 0)
			z->nr = z->nr - (z->mx - (int)ft_strlen(z->s));
		if (z->mx > (int)ft_strlen(z->s))
			z->s = prec2(z->s, z->mx);
	}
	if (find_flag(*index, format, '#') && *i != 0)
	{
		z->k = 2;
		z->nr = z->nr - 2;
		z->ret = z->ret + 2;
	}
	if (find_flag(*index, format, '-'))
	{
		if (z->k == 2 && *i != 0)
			ft_putstr("0X");
		if ((*i == 0 && case_zero(index, format)) || *i != 0)
		{
			ft_putstr(z->s);
			z->ret = z->ret + ft_strlen(z->s);
		}
	}
}

static	void	computez2(int *index, char *format, t_vars *z, int *i)
{
	if (z->k == 2 && z->c == '0')
		ft_putstr("0X");
	if (*i == 0 && (format[*index - 1] == '.'
				|| (format[*index - 1] == '0' && format[*index - 2] == '.')))
		z->nr++;
	while (z->nr > 0)
	{
		ft_putchar(z->c);
		z->nr--;
		z->ret++;
	}
	if (((z->c == ' ' && !find_flag(*index, format, '-')) || z->c == '0'))
	{
		if (z->c != '0' && z->k == 2 && *i != 0)
			ft_putstr("0X");
		if ((*i == 0 && case_zero(index, format)) || *i != 0)
		{
			z->ret = z->ret + ft_strlen(z->s);
			ft_putstr(z->s);
		}
	}
}

void			flags_bigx(int *index, char *format, t_vars *z, int *i)
{
	z->s = convert5(*i, 16);
	z->k = 0;
	z->nr = z->mn - ft_strlen(z->s);
	if (find_flag(*index, format, '0') && find_flag(*index, format, '-') == 0
			&& prec1(*index - 1, format) != 1
			&& ((*i == 0 && case_zero(index, format)) || *i != 0)
			&& format[*index - 1] != '.')
		z->c = '0';
	else
		z->c = ' ';
	computez1(index, format, z, i);
	computez2(index, format, z, i);
}

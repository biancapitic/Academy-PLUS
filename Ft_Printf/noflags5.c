/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   noflags5.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpitic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 16:08:54 by bpitic            #+#    #+#             */
/*   Updated: 2018/03/29 16:09:00 by bpitic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

void	noflags_h_o(int *index, char *format, t_vars *z, unsigned short *i)
{
	z->nr = 0;
	z->s = convert1(*i, 8);
	if (ft_isdigit(format[*index - 1]) || ft_isdigit(format[*index - 2]))
	{
		if (prec1(*index - 1, format) == 1)
			if (z->mx > (int)ft_strlen(z->s))
				z->s = prec2(z->s, z->mx);
		z->nr = z->mn - ft_strlen(z->s);
		while (z->nr > 0)
		{
			ft_putchar(' ');
			z->ret++;
			z->nr--;
		}
	}
	ft_putstr(z->s);
	z->ret = z->ret + ft_strlen(z->s);
}

void	noflags_j_o(int *index, char *format, t_vars *z, uintmax_t *i)
{
	z->s = convert4(*i, 8);
	if (ft_isdigit(format[*index - 1]) || ft_isdigit(format[*index - 2]))
	{
		if (prec1(*index - 1, format) == 1)
			if (z->mx > (int)ft_strlen(z->s))
				z->s = prec2(z->s, z->mx);
		z->nr = z->mn - ft_strlen(z->s);
		while (z->nr > 0)
		{
			ft_putchar(' ');
			z->ret++;
			z->nr--;
		}
	}
	if ((*i == 0 && case_zero(index, format)) || *i != 0)
		ft_putstr(z->s);
	z->ret = z->ret + ft_strlen(z->s);
}

void	noflags_ll_o(int *index, char *format, t_vars *z, unsigned long long *i)
{
	z->s = convert4(*i, 8);
	if (ft_isdigit(format[*index - 1]) || ft_isdigit(format[*index - 2]))
	{
		if (prec1(*index - 1, format) == 1)
			if (z->mx > (int)ft_strlen(z->s))
				z->s = prec2(z->s, z->mx);
		z->nr = z->mn - ft_strlen(z->s);
		while (z->nr > 0)
		{
			ft_putchar(' ');
			z->ret++;
			z->nr--;
		}
	}
	if ((*i == 0 && case_zero(index, format)) || *i != 0)
	{
		ft_putstr(z->s);
		z->ret = z->ret + ft_strlen(z->s);
	}
}

void	noflags_hh_o(int *index, char *format, t_vars *z, unsigned char *i)
{
	if (format[*index + 2] == 'o')
		z->s = convert6(*i, 8);
	else
		z->s = ft_itoa2(*i);
	if (ft_isdigit(format[*index - 1]) || ft_isdigit(format[*index - 2]))
	{
		if (prec1(*index - 1, format) == 1)
			if (z->mx > (int)ft_strlen(z->s))
				z->s = prec2(z->s, z->mx);
		z->nr = z->mn - ft_strlen(z->s);
		while (z->nr > 0)
		{
			ft_putchar(' ');
			z->ret++;
			z->nr--;
		}
	}
	if ((*i == 0 && case_zero(index, format)) || *i != 0)
	{
		ft_putstr(z->s);
		z->ret = z->ret + ft_strlen(z->s);
	}
}

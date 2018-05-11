/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   noflags2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpitic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 16:08:22 by bpitic            #+#    #+#             */
/*   Updated: 2018/03/29 16:08:28 by bpitic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

void	noflags_bigx(int *index, char *format, t_vars *z, int *i)
{
	z->s = convert2(*i, 16);
	if (ft_isdigit(format[*index - 1]) ||
			(format[*index - 1] == '.' && ft_isdigit(format[*index - 2])))
	{
		if (prec1(*index - 1, format) == 1)
			if (z->mx > (int)ft_strlen(z->s))
				z->s = prec2(z->s, z->mx);
		z->nr = z->mn - ft_strlen(z->s);
		if (*i == 0 && (format[*index - 1] == '.'
					|| format[*index - 1] == '0'))
			z->nr++;
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

void	noflags_o(int *index, char *format, t_vars *z, int *i)
{
	z->s = convert1(*i, 8);
	if (ft_isdigit(format[*index - 1]) ||
			(format[*index - 1] == '.' && ft_isdigit(format[*index - 2])))
	{
		if (prec1(*index - 1, format) == 1)
			if (z->mx > (int)ft_strlen(z->s))
				z->s = prec2(z->s, z->mx);
		z->nr = z->mn - ft_strlen(z->s);
		if (*i == 0 && (format[*index - 1] == '.'
					|| format[*index - 1] == '0'))
			z->nr++;
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

void	noflags_bigs(int *index, char *format, t_vars *z, int *s)
{
	if (ft_isdigit(format[*index - 1]))
	{
		if (prec1(*index - 1, format) == 1)
			if (z->mx < (int)ft_strlen2(s))
				s = crop2(s, z->mx);
		z->nr = z->mn - ft_strlen2(s);
		while (z->nr > 0)
		{
			ft_putchar(' ');
			z->ret++;
			z->nr--;
		}
	}
	z->i = 0;
	while (z->i < ft_strlen2(s))
	{
		write(1, s + z->i, 1);
		z->ret++;
		z->i++;
	}
}

void	noflags_bigc(int *index, char *format, t_vars *z, wint_t c)
{
	if (prec1(*index - 1, format))
	{
		z->mn = z->mn - 1;
		while (z->mn > 0)
		{
			ft_putchar(' ');
			z->ret++;
			z->mn--;
		}
	}
	write(1, &c, 1);
	z->ret++;
}

void	noflags_ll_d_i(int *index, char *format, t_vars *z, long long *i)
{
	z->s = ft_itoa(*i);
	if (z->s[0] == '-')
		ft_strcpy(z->s, z->s + 1);
	if (ft_isdigit(format[*index - 1]) || ft_isdigit(format[*index - 2]))
	{
		if (prec1(*index - 1, format) == 1)
			if (z->mx > (int)ft_strlen(z->s))
				z->s = prec2(z->s, z->mx);
		z->nr = z->mn - ft_strlen(z->s);
		if (*i < 0)
			z->nr--;
		chestie1(z);
		if (*i < 0)
		{
			ft_putchar('-');
			z->ret++;
		}
	}
	else if (*i < 0)
	{
		ft_putchar('-');
		z->ret++;
	}
	ft_putstr(z->s);
	z->ret = z->ret + ft_strlen(z->s);
}

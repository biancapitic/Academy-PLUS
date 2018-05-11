/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   noflags.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpitic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 16:08:09 by bpitic            #+#    #+#             */
/*   Updated: 2018/03/29 16:08:16 by bpitic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

void	noflags_d_i(int *index, char *format, t_vars *z, int *i)
{
	z->s = ft_itoa(*i);
	if (z->s[0] == '-')
		ft_strcpy(z->s, z->s + 1);
	if (ft_isdigit(format[*index - 1]) || ft_isdigit(format[*index - 2]))
		chestie2(index, format, z, i);
	else if (*i < 0)
	{
		ft_putchar('-');
		z->ret++;
	}
	if (*i == 0)
	{
		if (format[*index - 1] != '.' && format[*index - 1] != '0')
			ft_putchar('0');
	}
	else
	{
		ft_putstr(z->s);
		z->ret = z->ret + ft_strlen(z->s);
	}
}

void	noflags_c(int *index, char *format, t_vars *z, char *c)
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
	ft_putchar(*c);
	z->ret++;
}

void	noflags_u(int *index, char *format, t_vars *z, unsigned int *i)
{
	z->s = ft_itoa2(*i);
	if (ft_isdigit(format[*index - 1]) ||
			(format[*index - 1] == '.' && ft_isdigit(format[*index - 2])))
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

void	noflags_s(int *index, char *format, t_vars *z, char *s)
{
	z->nr = 0;
	if (ft_isdigit(format[*index - 1]) || format[*index - 1] == '.')
	{
		if (prec1(*index - 1, format) == 1)
			if (z->mx < (int)ft_strlen(s))
			{
				if (format[*index - 1] == '.')
					z->mx = 0;
				s = crop(s, z->mx);
			}
		z->nr = z->mn - ft_strlen(s);
		while (z->nr > 0)
		{
			ft_putchar(' ');
			z->ret++;
			z->nr--;
		}
	}
	ft_putstr(s);
	z->ret = z->ret + ft_strlen(s);
}

void	noflags_x(int *index, char *format, t_vars *z, int *i)
{
	z->s = convert1(*i, 16);
	if (ft_isdigit(format[*index - 1])
			|| (format[*index - 1] == '.' && ft_isdigit(format[*index - 2])))
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

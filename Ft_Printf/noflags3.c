/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   noflags3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpitic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 16:08:32 by bpitic            #+#    #+#             */
/*   Updated: 2018/03/29 16:08:38 by bpitic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

void	noflags_j_d(int *index, char *format, t_vars *z, intmax_t *i)
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

void	noflags_h_d_i(int *index, char *format, t_vars *z, short *i)
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

void	noflags_ll_x(int *index, char *format, t_vars *z, unsigned long long *i)
{
	z->s = conv_for_x(index, format, *i);
	if (ft_isdigit(format[*index - 1]) ||
			(format[*index - 1] == '.' && ft_isdigit(format[*index - 2])))
	{
		if (prec1(*index - 1, format) == 1)
			if (z->mx > (int)ft_strlen(z->s))
				z->s = prec2(z->s, z->mx);
		z->nr = z->mn - ft_strlen(z->s);
		if (*i == 0 &&
				(format[*index - 1] == '.' || format[*index - 1] == '0'))
			z->nr++;
		while (z->nr-- > 0)
		{
			ft_putchar(' ');
			z->ret++;
		}
	}
	if ((*i == 0 && case_zero(index, format)) || *i != 0)
	{
		ft_putstr(z->s);
		z->ret = z->ret + ft_strlen(z->s);
	}
}

void	noflags_j_x(int *index, char *format, t_vars *z, uintmax_t *i)
{
	z->s = conv_for_x(index, format, *i);
	if (ft_isdigit(format[*index - 1]) ||
			(format[*index - 1] == '.' && ft_isdigit(format[*index - 2])))
	{
		if (prec1(*index - 1, format) == 1)
			if (z->mx > (int)ft_strlen(z->s))
				z->s = prec2(z->s, z->mx);
		z->nr = z->mn - ft_strlen(z->s);
		if (*i == 0 &&
				(format[*index - 1] == '.' || format[*index - 1] == '0'))
			z->nr++;
		while (z->nr-- > 0)
		{
			ft_putchar(' ');
			z->ret++;
		}
	}
	if ((*i == 0 && case_zero(index, format)) || *i != 0)
	{
		ft_putstr(z->s);
		z->ret = z->ret + ft_strlen(z->s);
	}
}

void	noflags_h_x(int *index, char *format, t_vars *z, unsigned short *i)
{
	z->s = conv_for_x(index, format, *i);
	if (ft_isdigit(format[*index - 1]) ||
			(format[*index - 1] == '.' && ft_isdigit(format[*index - 2])))
	{
		if (prec1(*index - 1, format) == 1)
			if (z->mx > (int)ft_strlen(z->s))
				z->s = prec2(z->s, z->mx);
		z->nr = z->mn - ft_strlen(z->s);
		if (*i == 0 &&
				(format[*index - 1] == '.' || format[*index - 1] == '0'))
			z->nr++;
		while (z->nr-- > 0)
		{
			ft_putchar(' ');
			z->ret++;
		}
	}
	if ((*i == 0 && case_zero(index, format)) || *i != 0)
	{
		ft_putstr(z->s);
		z->ret = z->ret + ft_strlen(z->s);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cases5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpitic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 16:01:33 by bpitic            #+#    #+#             */
/*   Updated: 2018/03/29 16:01:39 by bpitic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

void	case_hh_x(int *index, t_vars *z, char *format, va_list arg)
{
	int				i;
	unsigned char	c;

	if (format[*index] == 'h' && format[*index + 1] == 'h'
			&& (format[*index + 2] == 'x' || format[*index + 2] == 'X'))
	{
		i = va_arg(arg, int);
		c = (unsigned char)i;
		if (check_flags(*index - 1, format))
			flags_hh_x(index, format, z, &c);
		else
			noflags_hh_x(index, format, z, &c);
	}
}

void	case_hh_d_i(int *index, t_vars *z, char *format, va_list arg)
{
	int				i;
	signed char		c;

	if (format[*index] == 'h' && format[*index + 1] == 'h'
			&& (format[*index + 2] == 'd' || format[*index + 2] == 'i'))
	{
		i = va_arg(arg, int);
		c = (signed char)i;
		if (check_flags(*index - 1, format))
			flags_hh_d_i(index, format, z, &c);
		else
			noflags_hh_d_i(index, format, z, &c);
	}
}

void	case_procent(int *index, t_vars *z, char *format)
{
	if (format[*index] == '%')
	{
		if (find_flag(*index - 1, format, '-'))
		{
			z->nr = z->mn - 1;
			ft_putchar('%');
			z->ret++;
			while (--z->nr >= 0)
			{
				ft_putchar(' ');
				z->ret++;
			}
		}
		else
		{
			z->nr = z->mn;
			while (--z->nr > 0)
			{
				ft_putchar(' ');
				z->ret++;
			}
			ft_putchar('%');
			z->ret++;
		}
	}
}

void	case_h_u(int *index, t_vars *z, char *format, va_list arg)
{
	unsigned long				i;

	if (format[*index] == 'h' && (format[*index + 1] == 'u'
					|| format[*index + 1] == 'U'))
	{
		i = va_arg(arg, unsigned long);
		if (check_flags(*index - 1, format))
			flags_h_u(index, format, z, &i);
		else
			noflags_h_u(index, format, z, &i);
	}
}

void	case_j_u(int *index, t_vars *z, char *format, va_list arg)
{
	uintmax_t i;

	if (format[*index] == 'j' && (format[*index + 1] == 'U' ||
				format[*index + 1] == 'u'))
	{
		i = va_arg(arg, uintmax_t);
		if (check_flags(*index - 1, format))
			flags_j_u(index, format, z, &i);
		else
			noflags_j_u(index, format, z, &i);
	}
}

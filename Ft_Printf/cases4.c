/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cases4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpitic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 16:01:15 by bpitic            #+#    #+#             */
/*   Updated: 2018/03/29 16:01:23 by bpitic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

void	case_j_d(int *index, t_vars *z, char *format, va_list arg)
{
	intmax_t i;

	if (format[*index] == 'j' && (format[*index + 1] == 'd'
				|| format[*index + 1] == 'i' || format[*index + 1] == 'D'))
	{
		i = va_arg(arg, intmax_t);
		if (check_flags(*index - 1, format))
			flags_j_d(index, format, z, &i);
		else
			noflags_j_d(index, format, z, &i);
	}
}

void	case_h_d_i(int *index, t_vars *z, char *format, va_list arg)
{
	int		i;
	short	c;

	if (format[*index] == 'h' && (format[*index + 1] == 'd'
				|| format[*index + 1] == 'i'))
	{
		i = va_arg(arg, int);
		c = (short)i;
		if (check_flags(*index - 1, format))
			flags_h_d_i(index, format, z, &c);
		else
			noflags_h_d_i(index, format, z, &c);
	}
}

void	case_ll_x(int *index, t_vars *z, char *format, va_list arg)
{
	unsigned long long i;

	if ((format[*index] == 'l' && (format[*index + 1] == 'x'
					|| format[*index + 1] == 'X')) || (format[*index] == 'l'
					&& format[*index + 1] == 'l' && (format[*index + 2] == 'x'
						|| format[*index + 2] == 'X'))
			|| (format[*index] == 'z' && (format[*index + 1] == 'x'
					|| format[*index + 1] == 'X')))
	{
		i = va_arg(arg, unsigned long long);
		if (check_flags(*index - 1, format))
			flags_ll_x(index, format, z, &i);
		else
			noflags_ll_x(index, format, z, &i);
	}
}

void	case_j_x(int *index, t_vars *z, char *format, va_list arg)
{
	uintmax_t i;

	if (format[*index] == 'j' && (format[*index + 1] == 'x'
				|| format[*index + 1] == 'X'))
	{
		i = va_arg(arg, uintmax_t);
		if (check_flags(*index - 1, format))
			flags_j_x(index, format, z, &i);
		else
			noflags_j_x(index, format, z, &i);
	}
}

void	case_h_x(int *index, t_vars *z, char *format, va_list arg)
{
	unsigned short	c;
	int				i;

	if (format[*index] == 'h' && (format[*index + 1] == 'x'
				|| format[*index + 1] == 'X'))
	{
		i = va_arg(arg, int);
		c = (unsigned short)i;
		if (check_flags(*index - 1, format))
			flags_h_x(index, format, z, &c);
		else
			noflags_h_x(index, format, z, &c);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cases6.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpitic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 16:01:48 by bpitic            #+#    #+#             */
/*   Updated: 2018/03/29 16:01:56 by bpitic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

void	case_ll_u(int *index, t_vars *z, char *format, va_list arg)
{
	unsigned long long i;

	if ((format[*index] == 'l' && format[*index + 1] == 'l'
				&& (format[*index + 2] == 'U' ||
					format[*index + 2] == 'u')) ||
			((format[*index] == 'l' || format[*index] == 'z')
			&& (format[*index + 1] == 'U' || format[*index + 1] == 'u'))
			|| format[*index] == 'U' || (format[*index] == 'h'
				&& format[*index + 1] == 'h' && format[*index + 2] == 'U'))
	{
		i = va_arg(arg, unsigned long long);
		if (check_flags(*index - 1, format))
			flags_ll_u(index, format, z, &i);
		else
			noflags_ll_u(index, format, z, &i);
	}
}

void	case_ll_o(int *index, t_vars *z, char *format, va_list arg)
{
	unsigned long long i;

	if ((format[*index] == 'l' && format[*index + 1] == 'l'
				&& (format[*index + 2] == 'o' || format[*index + 2] == 'O')) ||
			((format[*index] == 'l' || format[*index] == 'z')
			&& (format[*index + 1] == 'o' || format[*index + 1] == 'O'))
			|| format[*index] == 'O' || (format[*index] == 'h'
				&& format[*index + 1] == 'h' && format[*index + 2] == 'O'))
	{
		i = va_arg(arg, unsigned long long);
		if (check_flags(*index - 1, format))
			flags_ll_o(index, format, z, &i);
		else
			noflags_ll_o(index, format, z, &i);
	}
}

void	case_h_o(int *index, t_vars *z, char *format, va_list arg)
{
	int				i;
	unsigned short	c;

	if (format[*index] == 'h' &&
			(format[*index + 1] == 'o' || format[*index + 1] == 'O'))
	{
		i = va_arg(arg, int);
		c = (unsigned short)i;
		if (check_flags(*index - 1, format))
			flags_h_o(index, format, z, &c);
		else
			noflags_h_o(index, format, z, &c);
	}
}

void	case_j_o(int *index, t_vars *z, char *format, va_list arg)
{
	uintmax_t i;

	if (format[*index] == 'j'
			&& (format[*index + 1] == 'o' || format[*index + 1] == 'O'))
	{
		i = va_arg(arg, uintmax_t);
		if (check_flags(*index - 1, format))
			flags_j_o(index, format, z, &i);
		else
			noflags_j_o(index, format, z, &i);
	}
}

void	case_hh_o(int *index, t_vars *z, char *format, va_list arg)
{
	unsigned char	c;
	int				i;

	if (format[*index] == 'h' && format[*index + 1] == 'h' &&
			(format[*index + 2] == 'o' || format[*index + 2] == 'u'))
	{
		i = va_arg(arg, int);
		c = (unsigned char)i;
		if (check_flags(*index - 1, format))
			flags_hh_o(index, format, z, &c);
		else
			noflags_hh_o(index, format, z, &c);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cases1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpitic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 16:00:00 by bpitic            #+#    #+#             */
/*   Updated: 2018/03/29 16:00:09 by bpitic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

void	case_c(t_vars *z, int *index, char *format, va_list arg)
{
	char c;

	if (format[*index] == 'c')
	{
		c = va_arg(arg, int);
		if (check_flags(*index - 1, format) && !find_flag(*index, format, ' '))
			flags_c(index, format, z, &c);
		else
			noflags_c(index, format, z, &c);
	}
}

void	case_d_or_i(int *index, t_vars *z, char *format, va_list arg)
{
	int i;

	if (format[*index] == 'd' || format[*index] == 'i')
	{
		i = va_arg(arg, int);
		if (check_flags(*index - 1, format))
			flags_d_i(index, format, z, &i);
		else
			noflags_d_i(index, format, z, &i);
	}
}

void	case_u(int *index, t_vars *z, char *format, va_list arg)
{
	unsigned int i;

	if (format[*index] == 'u')
	{
		i = va_arg(arg, unsigned int);
		if (check_flags(*index - 1, format))
			flags_u(index, format, z, &i);
		else
			noflags_u(index, format, z, &i);
	}
}

void	case_s(int *index, t_vars *z, char *format, va_list arg)
{
	char	*s;

	if (format[*index] == 's')
	{
		s = va_arg(arg, char*);
		if (!s)
		{
			ft_putstr("(null)");
			z->ret = z->ret + 6;
		}
		else if (check_flags(*index - 1, format))
			flags_s(index, format, z, s);
		else
			noflags_s(index, format, z, s);
	}
}

void	min_width(t_vars *z, int *index, char *format)
{
	z->mn = 0;
	if (ft_isdigit(format[*index]))
	{
		while (ft_isdigit(format[*index]))
		{
			z->mn = z->mn * 10 + (format[*index] - '0');
			(*index)++;
		}
	}
}

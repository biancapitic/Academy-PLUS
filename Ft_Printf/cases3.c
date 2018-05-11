/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cases3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpitic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 16:00:58 by bpitic            #+#    #+#             */
/*   Updated: 2018/03/29 16:01:05 by bpitic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

void	case_o(int *index, t_vars *z, char *format, va_list arg)
{
	int i;

	if (format[*index] == 'o')
	{
		i = va_arg(arg, int);
		if (check_flags(*index - 1, format))
			flags_o(index, format, z, &i);
		else
			noflags_o(index, format, z, &i);
	}
}

void	case_bigs(int *index, t_vars *z, char *format, va_list arg)
{
	wchar_t *s;

	if (format[*index] == 'S' ||
			(format[*index] == 'l' && format[*index + 1] == 's'))
	{
		s = va_arg(arg, wchar_t*);
		if (check_flags(*index - 1, format))
			flags_bigs(index, format, z, s);
		else
			noflags_bigs(index, format, z, s);
	}
}

void	case_bigc(int *index, t_vars *z, char *format, va_list arg)
{
	wchar_t chr;

	if (format[*index] == 'C')
	{
		chr = va_arg(arg, wchar_t);
		z->ret++;
		write(1, &chr, 1);
	}
}

void	case_p(int *index, t_vars *z, char *format, va_list arg)
{
	unsigned long long	value;
	char				*s;

	if (format[*index] == 'p'
			|| (format[*index] == 'l' && format[*index + 1] == 'p'))
	{
		value = (unsigned long long)va_arg(arg, void*);
		if (check_flags(*index - 1, format))
			flags_p(index, format, z, &value);
		else
		{
			s = convert3(value, 16);
			chestie(s, z);
			if ((value == 0 && case_zero(index, format)) || value != 0)
			{
				ft_putstr(s);
				z->ret += ft_strlen(s);
			}
			else
			{
				ft_putstr("0x");
				z->ret += 2;
			}
		}
	}
}

void	case_ll_d_i(int *index, t_vars *z, char *format, va_list arg)
{
	long long i;

	if ((format[*index] == 'l' && format[*index + 1] == 'l'
				&& (format[*index + 2] == 'd' || format[*index + 2] == 'i'
					|| format[*index + 2] == 'D')) ||
			(format[*index] == 'l' && (format[*index + 1] == 'd' ||
										format[*index + 1] == 'i'
										|| format[*index + 1] == 'D'))
			|| format[*index] == 'D' || (format[*index] == 'z'
				&& (format[*index + 1] == 'd' || format[*index + 1] == 'i'
					|| format[*index + 1] == 'D'))
			|| (format[*index] == 'h' && format[*index + 1] == 'h'
				&& format[*index + 2] == 'D')
			|| (format[*index] == 'h' && format[*index + 1] == 'D'))
	{
		i = va_arg(arg, long long);
		if (check_flags(*index - 1, format))
			flags_ll_d_i(index, format, z, &i);
		else
			noflags_ll_d_i(index, format, z, &i);
	}
}

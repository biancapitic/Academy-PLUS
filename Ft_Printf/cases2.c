/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cases2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpitic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 16:00:35 by bpitic            #+#    #+#             */
/*   Updated: 2018/03/29 16:00:45 by bpitic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

void	increment(int *index, char *format)
{
	char	str[16];
	int		i;

	i = 0;
	ft_strcpy(str, "sSpdDioOuUxXcC%");
	while (format[*index] == 'l' || format[*index] == 'h'
			|| format[*index] == 'j' || format[*index] == 'z')
		(*index)++;
	while (str[i])
	{
		if (format[*index] == str[i])
		{
			(*index)++;
			return ;
		}
		i++;
	}
}

void	just_print(int *index, char *format, t_vars *z)
{
	while (format[*index] != '%' && format[*index])
	{
		ft_putchar(format[*index]);
		z->ret++;
		(*index)++;
	}
	if (format[*index] == '%')
		(*index)++;
}

void	precision(t_vars *z, int *index, char *format)
{
	z->mx = 0;
	if (!(ft_isdigit(format[*index - 1])))
		z->mn = 0;
	if (format[*index] == '.')
	{
		(*index)++;
		while (ft_isdigit(format[*index]))
		{
			z->mx = z->mx * 10 + (format[*index] - '0');
			(*index)++;
		}
	}
}

void	case_x(int *index, t_vars *z, char *format, va_list arg)
{
	int i;

	if (format[*index] == 'x')
	{
		i = va_arg(arg, unsigned int);
		if (check_flags(*index - 1, format))
			flags_x(index, format, z, &i);
		else
			noflags_x(index, format, z, &i);
	}
}

void	case_bigx(int *index, t_vars *z, char *format, va_list arg)
{
	int i;

	if (format[*index] == 'X')
	{
		i = va_arg(arg, unsigned int);
		if (check_flags(*index - 1, format))
			flags_bigx(index, format, z, &i);
		else
			noflags_bigx(index, format, z, &i);
	}
}

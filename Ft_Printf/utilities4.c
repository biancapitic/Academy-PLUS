/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpitic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 16:10:11 by bpitic            #+#    #+#             */
/*   Updated: 2018/03/29 16:10:18 by bpitic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

char	*convert4(unsigned long long num, int base)
{
	static char representation[] = "0123456789abcdef";
	static char buffer[50];
	char		*ptr;

	ptr = &buffer[49];
	*ptr = '\0';
	if (num == 0)
		*--ptr = '0';
	else
	{
		while (num != 0)
		{
			*--ptr = representation[num % base];
			num /= base;
		}
	}
	return (ptr);
}

char	*convert5(unsigned long long num, int base)
{
	static char representation[] = "0123456789ABCDEF";
	static char buffer[50];
	char		*ptr;

	ptr = &buffer[49];
	*ptr = '\0';
	if (num == 0)
		*--ptr = '0';
	else
	{
		while (num != 0)
		{
			*--ptr = representation[num % base];
			num /= base;
		}
	}
	return (ptr);
}

char	*conv_for_x(int *index, char *format, unsigned long long i)
{
	char *s;

	if (format[*index + 1] == 'x' || format[*index + 2] == 'x')
		s = convert4(i, 16);
	else
		s = convert5(i, 16);
	return (s);
}

char	*for_x_flag(int *index, char *format)
{
	char *str;

	if (format[*index + 1] == 'x' || format[*index + 2] == 'x')
		str = "0x";
	else
		str = "0X";
	return (str);
}

int		case_zero(int *index, char *format)
{
	if ((format[*index - 1] == '0' && ft_isdigit(format[*index - 2]))
			|| (format[*index - 1] != '.' && format[*index - 1] != '0'))
		return (1);
	return (0);
}

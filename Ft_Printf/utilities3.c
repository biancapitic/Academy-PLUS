/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpitic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 16:10:01 by bpitic            #+#    #+#             */
/*   Updated: 2018/03/29 16:10:07 by bpitic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

int		check_flags(int index, char *str)
{
	while (str[index] != '%')
	{
		if ((str[index] > '0' && str[index] <= '9') || str[index] == '.'
				|| (str[index] == '0' && ((str[index - 1] > '0'
				&& str[index - 1] <= '9') || str[index - 1] == '.')))
			index--;
		else
			return (1);
	}
	return (0);
}

char	*add_sign(char *str)
{
	char	*s;
	int		i;

	i = 0;
	s = (char*)malloc(sizeof(char) * (ft_strlen(str) + 2));
	s[0] = '+';
	while (str[i])
	{
		s[i + 1] = str[i];
		i++;
	}
	s[i + 1] = '\0';
	return (s);
}

void	jump_flags(int *index, char *format)
{
	while (format[*index] == '#' || format[*index] == '0'
			|| format[*index] == '-' || format[*index] == '+'
			|| format[*index] == ' ')
		(*index)++;
}

char	*convert3(unsigned long long num, int base)
{
	static char representation[] = "0123456789abcdef";
	static char buffer[50];
	char		*ptr;

	ptr = &buffer[49];
	*ptr = '\0';
	if (num == 0)
		return ("0x0");
	while (num != 0)
	{
		*--ptr = representation[num % base];
		num /= base;
	}
	*--ptr = 'x';
	*--ptr = '0';
	return (ptr);
}

int		*crop2(int *str, int mx)
{
	int *s;
	int	i;

	i = 0;
	if (!(s = (int*)malloc(sizeof(int) * (mx + 1))))
		return (NULL);
	while (i < mx)
	{
		s[i] = str[i];
		i++;
	}
	s[i] = '\0';
	return (s);
}

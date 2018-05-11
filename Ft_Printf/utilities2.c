/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpitic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 16:09:49 by bpitic            #+#    #+#             */
/*   Updated: 2018/03/29 16:09:56 by bpitic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

char	*convert2(unsigned int num, int base)
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

char	*convert1(unsigned int num, int base)
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

char	*prec2(char *str, int mx)
{
	char	*s;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!(s = (char*)malloc(sizeof(char) * mx + 1)))
		return (NULL);
	if (str[0] == '-')
	{
		i = 1;
		j = 1;
		s[0] = '-';
		mx += 2;
	}
	while (i < mx - (int)ft_strlen(str))
		s[i++] = '0';
	while (j < (int)ft_strlen(str))
	{
		s[i] = str[j];
		j++;
		i++;
	}
	s[i] = '\0';
	return (s);
}

int		ft_strlen2(int *d)
{
	int i;

	i = 0;
	while (d[i] != '\0')
		i++;
	return (i);
}

int		find_flag(int index, char *str, char c)
{
	while (str[index] != '%')
	{
		if (str[index] == c && c == '0' && ft_isdigit(str[index - 1]))
			index--;
		if (str[index] == c)
			return (1);
		index--;
	}
	return (0);
}

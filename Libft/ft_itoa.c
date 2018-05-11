/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpitic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 17:03:31 by bpitic            #+#    #+#             */
/*   Updated: 2017/12/14 19:02:21 by bpitic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		ft_nrcif(int nr)
{
	int c;

	if (nr == 0)
		return (1);
	c = 0;
	if (nr < 0)
	{
		c++;
		nr = nr * (-1);
	}
	while (nr != 0)
	{
		c++;
		nr = nr / 10;
	}
	return (c);
}

static	void	ft_rev(char *s, int i, int nr)
{
	if (nr > 9)
	{
		ft_rev(s, --i, nr / 10);
		i++;
	}
	s[i] = (nr % 10) + '0';
}

char			*ft_itoa(int n)
{
	char	*s;
	int		c;

	if (n == -2147483648)
	{
		s = (char *)malloc(sizeof(char) * 11 + 1);
		s[0] = '-';
		ft_rev(s, 5, 21474);
		ft_rev(s, 10, 83648);
		s[12] = '\0';
		return (s);
	}
	c = ft_nrcif(n);
	s = (char *)malloc(sizeof(char) * c + 1);
	if (!s)
		return (NULL);
	if (n < 0)
	{
		s[0] = '-';
		n = n * (-1);
	}
	c--;
	ft_rev(s, c, n);
	s[c + 1] = '\0';
	return (s);
}

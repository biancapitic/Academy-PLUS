/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpitic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 13:09:11 by bpitic            #+#    #+#             */
/*   Updated: 2017/12/14 19:12:17 by bpitic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strequ(char const *s1, char const *s2)
{
	char	*ps1;
	char	*ps2;
	int		i;

	if (!s1 || !s2)
		return (0);
	ps1 = (char*)s1;
	ps2 = (char*)s2;
	i = 0;
	while (ps1[i] != '\0' && ps2[i] != '\0')
	{
		if (ps1[i] != ps2[i])
			return (0);
		i++;
	}
	if (ps1[i] != ps2[i])
		return (0);
	return (1);
}

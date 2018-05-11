/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpitic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 13:20:20 by bpitic            #+#    #+#             */
/*   Updated: 2017/12/14 18:29:31 by bpitic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	char	*ps1;
	char	*ps2;
	size_t	i;

	if (!s1 || !s2)
		return (0);
	if (s1[0] == '\0' && s1[0] == s2[0])
		return (1);
	if (n == 0)
		return (1);
	i = 0;
	ps1 = (char *)s1;
	ps2 = (char *)s2;
	while (ps1[i] == ps2[i] && i < n && ps1[i] != '\0' && ps2[i] != '\0')
		i++;
	if (ps1[i - 1] == ps2[i - 1])
		if ((ps1[i] == ps2[i] && ps1[i] == '\0') || i == n)
			return (1);
	return (0);
}

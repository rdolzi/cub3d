/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbiondo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 12:23:38 by fbiondo           #+#    #+#             */
/*   Updated: 2023/01/23 13:43:38 by fbiondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t					i;
	const unsigned char		*sp1;
	const unsigned char		*sp2;

	i = 0;
	sp1 = (const unsigned char *)s1;
	sp2 = (const unsigned char *)s2;
	while (i < n)
	{
		if (sp1[i] == sp2[i])
			i++;
		else
			return (sp1[i] - sp2[i]);
	}
	return (0);
}

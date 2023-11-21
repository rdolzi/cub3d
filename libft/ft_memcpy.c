/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbiondo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 10:05:25 by fbiondo           #+#    #+#             */
/*   Updated: 2023/01/25 13:00:14 by fbiondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*s;
	unsigned char	*b;
	size_t			i;

	if (!dst && !src)
		return (0);
	i = 0;
	s = (unsigned char *)src;
	b = (unsigned char *)dst;
	while (i < n)
	{	
		b[i] = s[i];
		i++;
	}
	return (dst);
}

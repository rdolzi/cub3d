/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbiondo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 20:38:48 by fbiondo           #+#    #+#             */
/*   Updated: 2023/01/23 17:01:07 by fbiondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	size_t				i;
	unsigned char		b;
	const unsigned char	*d;

	i = 0;
	b = (unsigned char)c;
	d = (const unsigned char *)str;
	while (i < n)
	{
		if (d[i] == b)
			return ((void *)(&str[i]));
		i++;
	}
	return (NULL);
}

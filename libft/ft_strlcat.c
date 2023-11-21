/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbiondo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 14:42:45 by fbiondo           #+#    #+#             */
/*   Updated: 2023/01/23 17:31:55 by fbiondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dsize;
	size_t	ssize;
	size_t	i;

	if ((!dst || !src) && !size)
		return (0);
	if (ft_strlen(dst) >= size)
		return (ft_strlen(src) + size);
	dsize = ft_strlen(dst);
	ssize = ft_strlen(src);
	i = 0;
	while (src[i] && dsize + i < size - 1)
	{
		dst[dsize + i] = src[i];
		i++;
	}
	dst[dsize + i] = '\0';
	return (dsize + ssize);
}

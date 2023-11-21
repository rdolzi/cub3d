/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbiondo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 13:47:41 by fbiondo           #+#    #+#             */
/*   Updated: 2023/01/25 12:25:26 by fbiondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;

	if (!(*needle))
		return ((char *)haystack);
	i = 0;
	while (i < len && (char)haystack[i])
	{
		if (!(ft_strncmp((char *)haystack + i, (char *)needle,
					ft_strlen(needle))))
		{
			if (ft_strlen(needle) + i > len)
				return (NULL);
			return ((char *)haystack + i);
		}
		i++;
	}
	return (NULL);
}

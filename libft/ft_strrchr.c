/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbiondo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 17:47:48 by fbiondo           #+#    #+#             */
/*   Updated: 2023/01/23 16:59:49 by fbiondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	slen;

	slen = ft_strlen(s);
	if (c == 0)
		return ((char *)(s + slen));
	while (slen >= 0)
	{
		if (s[slen] == c)
			return ((char *)(s + slen));
		slen--;
	}
	return (NULL);
}

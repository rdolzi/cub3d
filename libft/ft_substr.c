/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flaviobiondo <flaviobiondo@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 10:50:26 by fbiondo           #+#    #+#             */
/*   Updated: 2023/10/17 00:37:00 by flaviobiond      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	sub = (char *)malloc(sizeof(*s) * len + 1);
	if (!sub)
		return (NULL);
	while (s[i] != 0)
	{
		if (i >= start && j < len)
		{
			sub[j] = s[i];
				j++;
		}
		i++;
	}
	sub[j] = 0;
	return (sub);
}	

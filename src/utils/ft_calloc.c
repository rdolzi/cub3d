/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flaviobiondo <flaviobiondo@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 01:26:12 by rdolzi            #+#    #+#             */
/*   Updated: 2024/05/25 15:17:23 by flaviobiond      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cube.h"

void	ft_bzero(void *ptr, int i)
{
	unsigned char	*str;

	str = (unsigned char *)ptr;
	while (i != 0)
	{
		*str = '\0';
		str++;
		i--;
	}
}

void	*ft_calloc(int count, int size)
{
	void	*r;

	r = malloc(count * size);
	if (!r)
		return (NULL);
	ft_bzero(r, size * count);
	return (r);
}

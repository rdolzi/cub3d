/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flaviobiondo <flaviobiondo@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 02:22:19 by flaviobiond       #+#    #+#             */
/*   Updated: 2023/10/09 03:22:00 by flaviobiond      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "get_next_line.h"

void	ft_bzero(void *s, size_t n)
{
	int		i;
	char	*temp;

	i = 0;
	temp = s;
	while (n)
	{
		temp[i] = 0;
		i++;
		n--;
	}
}
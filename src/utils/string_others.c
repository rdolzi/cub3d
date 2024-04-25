/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_others.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdolzi <rdolzi@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 01:44:17 by rdolzi            #+#    #+#             */
/*   Updated: 2024/04/26 01:45:01 by rdolzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cube.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	j;
	int	segn;
	int	check;

	check = 0;
	i = 0;
	j = 0;
	segn = 1;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i++] == '-')
			segn = -1;
		check++;
	}
	if (check > 1)
		return (j);
	while (str[i] >= '0' && str[i] <= '9')
	{
		j = j * 10 + (str[i] - '0');
		i++;
	}
	return (j * segn);
}

int ft_isalpha(int c)
{
    return ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'));
}

int ft_isdigit(int c)
{
    return (c >= '0' && c <= '9');
}

int ft_isspace(int c)
{
    if (c == ' ' || c == '\n' || c == '\t' || c == '\v' || c == '\f' ||
        c == '\r')
        return (1);
    return (0);
}

void ft_printstr_fd(char *str, int fd)
{
    int k;

    k = 0;
    if (!str)
        return;
    while (str[k])
    {
        write(fd, &str[k], 1);
        k++;
    }
}

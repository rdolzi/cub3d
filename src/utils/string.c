/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdolzi <rdolzi@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 10:46:07 by rdolzi            #+#    #+#             */
/*   Updated: 2024/03/09 18:50:29 by rdolzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cube.h"

// void ft_printchar(char c, int fd)
// {
//     write(fd, &c, 1);
// }

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
        // ft_printchar(str[k], fd);
        k++;
    }
}

// torna 0 se uguali, 1 se diversi
// aggiunta modifica: se una delle due stringhe è piu corta della size n
// ritorna 1 e non 0
int ft_strncmp(const char *s1, const char *s2, size_t n)
{
    size_t i;
    unsigned char *us1;
    unsigned char *us2;

    i = 0;
    us1 = (unsigned char *)s1;
    us2 = (unsigned char *)s2;
    while ((us1[i] != '\0' || us2[i] != '\0') && i < n)
    {
        if (us1[i] == us2[i])
            i++;
        else
            return (us1[i] - us2[i]);
    }
    return (0);
}

char *ft_strchr(char *s, char ch)
{
    int slen;
    int i;

    i = 0;
    slen = ft_strlen(s);
    while (i <= slen)
    {
        if (s[i] == ch)
            return ((char *)&s[i]);
        i++;
    }
    return (NULL);
}

char	*ft_strdup(char *s1)
{
	char	*s2;
	int		len;
	int		i;

	i = 0;
	len = ft_strlen(s1);
	s2 = (char *)malloc((len + 1) * sizeof(char));
	if (!s2)
		return (NULL);
	while (i < len)
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdolzi <rdolzi@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 20:13:58 by rdolzi            #+#    #+#             */
/*   Updated: 2024/04/18 20:26:57 by rdolzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cube.h"

char	*ft_substr(char *s, int start, size_t len)
{
	char	*substr;
	size_t		j;

	if (!s)
		return (NULL);
	j = 0;
	if (len > ft_strlen(s))
		len = ft_strlen(s);
	if ((size_t) start >= ft_strlen(s))
		return (ft_strdup(""));
	substr = (char *)malloc((len + 1) * sizeof(char));
	if (!substr)
		return (NULL);
	while (j < len)
	{
		substr[j] = s[start];
		start++;
		j++;
	}
	substr[j] = '\0';
	return (substr);
}

size_t	get_word(const char *s, char c)
{
	size_t	ret;

	ret = 0;
	while (*s)
	{
		if (*s != c)
		{
			ret++;
			while (*s && *s != c)
				s++;
		}
		else
			s++;
	}
	return (ret);
}

void	*free_all(char **s)
{
	size_t	i;

	i = 0;
	while (s[i])
    {
        free(s[i]);
        i++;
    }	
	free(s);
	return (NULL);
}

char	**end_str(char **str, int i)
{
	str[i] = 0;
	return (str);
}

char	**ft_split(char *s, char c)
{
	char	**ret;
	int		i;
	int		len;

	if (!s)
		return (NULL);
	i = 0;
	ret = malloc(sizeof(char *) * (get_word(s, c) + 1));
	if (!ret)
		return (NULL);
	while (*s)
	{
		if (*s != c)
		{
			len = 0;
			while (*s && *s != c && ++len)
				++s;
			ret[i++] = ft_substr(s - len, 0, (size_t) len);
			if (!ret[i - 1])
				return (free_all(ret));
		}
		else
			s++;
	}
	return (end_str(ret, i));
}

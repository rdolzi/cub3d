/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdolzi <rdolzi@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 16:56:47 by flaviobiond       #+#    #+#             */
/*   Updated: 2024/05/25 16:04:01 by rdolzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cube.h"

void	check_double_p(t_game *game, int x, int y, int *counter)
{
	if (ft_strchr("NSWE", game->map[y][x]))
	{
		game->player.dir = game->map[y][x];
		game->player.position.x = (double)x + 0.5;
		game->player.position.y = (double)y + 0.5;
		game->map[y][x] = '0';
		(*counter)++;
	}
	if (*counter > 1)
		clean_exit(game, throw_exception(MAP_EXCEPTION,
				ERR_PLAYER_DUPLICATE, NULL));
}

//E TRASFORMA gli spazi in K
//checka la presenza dei soli caratterri "1 0 N S W E 32 \n" nella mappa
void	parse_space(t_game *game)
{
	int	y;
	int	x;
	int	c;

	c = 0;
	y = 0;
	if (check_wall(game))
		clean_exit(game, throw_exception(MAP_EXCEPTION, ERR_MAP_WALLS, NULL));
	while (y < game->map_len)
	{
		x = 0;
		while (x < (int) ft_strlen(game->map[y]))
		{
			if (ft_strchr("10NSWED", game->map[y][x]))
				check_double_p(game, x, y, &c);
			else if (game->map[y][x] >= 9 && game->map[y][x] <= 13)
				game->map[y][x] = '1';
			else if (game->map[y][x] == ' ')
				game->map[y][x] = '1';
			else if (!ft_strchr("10NSWED \n", game->map[y][x]))
				clean_exit(game, throw_exception(MAP_EXCEPTION,
						ERR_INVALID_CHAR, NULL));
			x++;
		}
		y++;
	}
	if (c != 1)
		clean_exit(game, throw_exception(MAP_EXCEPTION,
				ERR_PLAYER_DUPLICATE, NULL));
}

int	count_tabs(char *str)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == '\t')
			count += 4;
		else
			count++;
		i++;
	}
	return (count);
}

char	*replace_tabs(char *str, int count)
{
	char	*result;
	int		j;
	int		i;

	result = (char *)malloc(count + 1);
	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] == '\t')
		{
			result[j++] = ' ';
			result[j++] = ' ';
			result[j++] = ' ';
			result[j++] = ' ';
		}
		else
			result[j++] = str[i];
		i++;
	}
	result[j] = '\0';
	free(str);
	return (result);
}

char	*replace_tab_with_spaces(char *str)
{
	int		count;

	count = count_tabs(str);
	str = replace_tabs(str, count);
	return (str);
}

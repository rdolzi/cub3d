/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdolzi <rdolzi@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 16:01:51 by rdolzi            #+#    #+#             */
/*   Updated: 2024/05/25 16:03:46 by rdolzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cube.h"

//controlla se i valori che non sono 1
// siano contornati da spazi
void	check_frame(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (y < game->map_len)
	{
		x = 0;
		while (x < (int) ft_strlen(game->map[y]))
		{
			if (ft_strchr("0NSWED", game->map[y][x]))
			{
				if (game->map[y - 1][x] == ' ' || game->map[y + 1][x] == ' '
					|| game->map[y + 1][x + 1] == ' ' || game->map[y - 1][x
					- 1] == ' ' || game->map[y + 1][x - 1] == ' '
					|| game->map[y - 1][x + 1] == ' ')
					clean_exit(game, throw_exception(MAP_EXCEPTION,
							ERR_MAP_WALLS, NULL));
				if (game->map[y - 1][x] == '\0' || game->map[y + 1][x] == '\0'
					|| game->map[y + 1][x + 1] == '\0' || game->map[y - 1][x
					- 1] == '\0' || game->map[y + 1][x - 1] == '\0'
					|| game->map[y - 1][x + 1] == '\0')
					clean_exit(game, throw_exception(MAP_EXCEPTION,
							ERR_MAP_WALLS, NULL));
				if (game->map[y - 1][x] == '\n' || game->map[y + 1][x] == '\n'
					|| game->map[y + 1][x + 1] == '\n' || game->map[y - 1][x
					- 1] == '\n' || game->map[y + 1][x - 1] == '\n'
					|| game->map[y - 1][x + 1] == '\n')
					clean_exit(game, throw_exception(MAP_EXCEPTION,
							ERR_MAP_WALLS, NULL));
			}
			x++;
		}
		y++;
	}
}

int	check_wall(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->map_len)
	{
		if (game->map[i][0] != 32 && game->map[i][0] != '1'
			&& !(game->map[i][0] >= 9 && game->map[i][0] <= 13))
			return (-1);
		i++;
	}
	i = 0;
	while (i < (int)ft_strlen(game->map[0]))
	{
		if (game->map[0][i] != 32 && game->map[0][i] != '1'
			&& !(game->map[0][i] >= 9 && game->map[0][i] <= 13))
			return (-1);
		i++;
	}
	return (0);
}

void	convert_tab_space(t_game *game)
{
	int	y;

	y = 0;
	while (game->map[y])
	{
		game->map[y] = replace_tab_with_spaces(game->map[y]);
		y++;
	}
}

int	parse_map(t_game *game)
{
	convert_tab_space(game);
	if (check_wall(game))
		clean_exit(game, throw_exception(MAP_EXCEPTION, ERR_MAP_WALLS, NULL));
	check_frame(game);
	parse_space(game);
	return (0);
}

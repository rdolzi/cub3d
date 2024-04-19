/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_player.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdolzi <rdolzi@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 03:37:39 by rdolzi            #+#    #+#             */
/*   Updated: 2024/04/19 05:20:16 by rdolzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cube.h"

void init_direction_e_o(t_game *game)
{
    t_player *player;

    player = &game->player;
    if (player->dir == 'E')
	{
		player->direction.x = 1;
		player->direction.y = 0;
		player->cam_plane.x = 0;
		player->cam_plane.y = 0.66;
	}
    else if (player->dir == 'W')
	{
		player->direction.x = -1;
		player->direction.y = 0;
		player->cam_plane.x = 0;
		player->cam_plane.y = -0.66;
	}
}

void parse_player(t_game *game)
{
    t_player *player;

    player = &game->player;
    if (player->dir == 'S')
	{
		player->direction.x = 0;
		player->direction.y = 1;
		player->cam_plane.x = -0.66;
		player->cam_plane.y = 0;
	}
	else if (player->dir == 'N')
	{
		player->direction.x = 0;
		player->direction.y = -1;
		player->cam_plane.x = 0.66;
		player->cam_plane.y = 0;
	}
    init_direction_e_o(game);
}

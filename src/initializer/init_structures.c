/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structures.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdolzi <rdolzi@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 23:41:09 by rdolzi            #+#    #+#             */
/*   Updated: 2024/03/15 01:03:36 by rdolzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cube.h"

// refactor init, con una func per ogni singola structure

void init_internal_structures(t_game *game)
{
    int i;

    i = 0;
    // NSWE
    while (i < 4)
    {
        game->walls[i].path = NULL;
        game->walls[i].img = NULL;
        game->walls[i].addr = NULL;
        game->walls[i].bpp = 0;
        game->walls[i].line_length = 0;
        game->walls[i].endian = 0;
        i++;
    }
    // FLOOR - CEALING
    i = 0;
    while (i < 2)
    {
        game->type[i].path = NULL;
        game->type[i].hex = 0;
        i++;
    }
}

void init_game(t_game *game)
{
    // init default values
    game->mlx = NULL;
    game->mlx_win = NULL;
    game->win_height = WIN_HEIGHT;
    game->win_width = WIN_WIDTH;
    game->map = NULL;
    game->old_time = 0;
    game->fps = 0;
    game->argc = 0;
    game->argv = NULL;
    game->path = NULL;
    game->raw_file = NULL;
    game->n_lines_file = 0;
    game->map_transferred = 0;
    game->texture_pixels = NULL; //?
    game->textures = NULL;       //?
    init_internal_structures(game);
    // init_ray
    // init_player
    // game->player.dir_x = 0;
    // game->player.dir_x = 0;
    // game->player.move_x = 0;
    // game->player.move_y = 0;
    // game->player.pos_x = 0;
    // game->player.pos_y = 0;
    game->player.position.x = 0;
    game->player.position.y = 0;
    
    game->player.direction.x = 0;
    game->player.direction.y = 0;
    
    game->player.cam_plane.x = 0;
    game->player.cam_plane.y = 0;
    
    game->player.move.x = 0;
    game->player.move.y = 0;
    // game->player.rotate = 0;
}

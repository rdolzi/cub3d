/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structures.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdolzi <rdolzi@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 23:41:09 by rdolzi            #+#    #+#             */
/*   Updated: 2024/03/07 01:05:04 by rdolzi           ###   ########.fr       */
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
    game->argc = 0;
    game->argv = NULL;
    game->path = NULL;
    game->raw_file = NULL;
    game->n_lines_file = 0;
    game->texture_pixels = NULL; //?
    game->textures = NULL;       //?
    init_internal_structures(game);
    // init_ray
    // init_player
}
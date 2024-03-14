/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdolzi <rdolzi@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 00:12:41 by rdolzi            #+#    #+#             */
/*   Updated: 2024/03/14 00:25:30 by rdolzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cube.h"

void set_mlx(t_game *game)
{
    game->mlx = mlx_init();
    if (!game->mlx)
        clean_exit(game, throw_exception(SYSTEM_EXCEPTION, ERR_MLX, NULL));
    game->mlx_win = mlx_new_window(game->mlx, WIN_WIDTH, WIN_HEIGHT, "cub3D");
    if (!game->mlx_win)
        clean_exit(game, throw_exception(SYSTEM_EXCEPTION, ERR_MLX, NULL));
}

// 3)PARSE INFORMATION FILE FROM STRUCTURES ->wip
//      3.1)parse cardinals
//      3.2)parse_colors()
//          set colors
//          check color validity
//      3.3)parse map
//          3.3.A)set 1 if is_space
//          3.3.B)check map validity
//          3.3.C)check map is last
//          3.3.D)check map_elements()
//          3.3.E)check walls
//          3.3.F)check elements
//          3.3.G)check player
//          3.3.H)init player
//      3.4)parse texture
//          3.4.A)check file
//          3.4.B)check rgb
//          3.4.C)convert rgb
//          3.4.D)check texture validity
void parse_game(t_game *game)
{
    (void)game;
}

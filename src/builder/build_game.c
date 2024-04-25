/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdolzi <rdolzi@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 00:12:41 by rdolzi            #+#    #+#             */
/*   Updated: 2024/04/26 01:35:22 by rdolzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cube.h"

// print the commands needed to play the game
void display_menu()
{
    write(1,"menu..\n",7);
}

    // MLX CONFIGURATION
    // init mlx && win
void set_mlx(t_game *game)
{
    printf("entra in setmlx\n");
    game->mlx = mlx_init();
    if (!game->mlx)
        clean_exit(game, throw_exception(SYSTEM_EXCEPTION, ERR_MLX, NULL));
    game->mlx_win = mlx_new_window(game->mlx, WIN_WIDTH, WIN_HEIGHT, "cub3D");
    if (!game->mlx_win)
        clean_exit(game, throw_exception(SYSTEM_EXCEPTION, ERR_MLX, NULL));
     printf("esce in setmlx\n");
}

// 3)PARSE INFORMATION FROM STRUCTURES
void parse_game(t_game *game)
{
    parse_cardinal(game); // ->done
    parse_color(game); // ->done
    parse_map(game); // ->done
    parse_player(game);
}

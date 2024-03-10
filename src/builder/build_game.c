/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdolzi <rdolzi@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 00:12:41 by rdolzi            #+#    #+#             */
/*   Updated: 2024/03/10 22:08:40 by rdolzi           ###   ########.fr       */
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

void build_game(t_game *game)
{
    // 0)INIT STRUCTURES TO DEFAULT VALUES
    init_game(game);
    
    // 1)CHECK ARGC && .CUB EXTENSION
    check_input(game, CUB);

    // 2.A)initial_parse file cub
    //      2.A.1)read line numbers
    //      2.A.2) alloc **matr && read file      ->done
    // 2.B)transfer information from file to structures ->done
    //      2.B.1)transfer cardinals
    //      2.B.2)transfer color
    //      2.B.3)transfer map
    transfer_info_file(game);

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
    //parse_game(game);

    // 4) MLX CONFIGURATION  ->done
    //      4.1)init mlx && win
    set_mlx(game);
    //      4.2)mlx hooks config
    key_bind(game);
}

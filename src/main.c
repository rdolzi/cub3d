/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdolzi <rdolzi@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 19:50:28 by rdolzi            #+#    #+#             */
/*   Updated: 2024/04/26 01:53:07 by rdolzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube.h"

//valgrind --leak-check=full --track-origins=yes ./cub3d assets/maps/1.cub 

//todo
//menu
// grandezza window diversa per mac e linux

void build_game(t_game *game)
{
    if (game->argc != 2)
        clean_exit(game, throw_exception(ERR_ARGC, NULL, NULL));
    init_game(game);
    check_input(game, CUB, game->argv[1]);
    set_mlx(game);
    transfer_info_file(game);
    parse_game(game);
    key_bind(game);
}

void start_game(t_game *game)
{
    display_menu();
    render_screen(game);
}

void run_game(t_game *game)
{
    mlx_loop_hook(game->mlx, render, game);
    mlx_loop(game->mlx);
}

int main(int argc, char **argv)
{
    t_game game;
    
    game.argc = argc;
    game.argv = argv;
    build_game(&game);
    start_game(&game);
    run_game(&game);
}

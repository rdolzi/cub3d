/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdolzi <rdolzi@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 19:50:28 by rdolzi            #+#    #+#             */
/*   Updated: 2024/03/07 01:17:35 by rdolzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube.h"

int main(int argc, char **argv)
{
    t_game game;
    
    game.argc = argc;
    game.argv = argv;
    build_game(&game);
    start_game(&game);
        // display_menu();
        // display first frame
    run_game(&game);
        //mlx_loop_hook(game.mlx, render, &game);
    mlx_loop(game.mlx);

}

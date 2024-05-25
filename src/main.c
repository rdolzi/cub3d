/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flaviobiondo <flaviobiondo@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 19:50:28 by rdolzi            #+#    #+#             */
/*   Updated: 2024/05/25 15:12:16 by flaviobiond      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube.h"

//valgrind --leak-check=full --track-origins=yes ./cub3d assets/maps/1.cub 

//TODO:
// descrizione menu
// grandezza window diversa per mac e linux
// versione intra senza file .txt, gitignore
// aggiungere mappe, xpm 

void	build_game(t_game *game)
{
	if (game->argc != 2)
	{
		ft_printstr_fd("Error\nargc != 2", 2);
		exit(1);
	}
	init_game(game);
	check_input(game, CUB, game->argv[1]);
	set_mlx(game);
	transfer_info_file(game);
	parse_game(game);
	key_bind(game);
}

void	start_game(t_game *game)
{
	display_menu();
	render_screen(game);
}

void	run_game(t_game *game)
{
	mlx_loop_hook(game->mlx, render, game);
	mlx_loop(game->mlx);
}

int	main(int argc, char **argv)
{
	t_game	game;

	game.argc = argc;
	game.argv = argv;
	build_game(&game);
	start_game(&game);
	run_game(&game);
}

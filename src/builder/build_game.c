/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdolzi <rdolzi@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 00:12:41 by rdolzi            #+#    #+#             */
/*   Updated: 2024/05/25 23:30:56 by rdolzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cube.h"

// MLX CONFIGURATION
// init mlx && win
void	set_mlx(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		clean_exit(game, throw_exception(SYSTEM_EXCEPTION, ERR_MLX, NULL));
	game->mlx_win = mlx_new_window(game->mlx, WIN_WIDTH, WIN_HEIGHT, "cub3D");
	if (!game->mlx_win)
		clean_exit(game, throw_exception(SYSTEM_EXCEPTION, ERR_MLX, NULL));
}

// 3)PARSE INFORMATION FROM STRUCTURES
void	parse_game(t_game *game)
{
	parse_cardinal(game);
	parse_color(game);
	parse_map(game);
	parse_player(game);
}

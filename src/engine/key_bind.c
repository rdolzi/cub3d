/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_bind.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdolzi <rdolzi@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 01:03:17 by rdolzi            #+#    #+#             */
/*   Updated: 2024/04/26 00:59:51 by rdolzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cube.h"

int quit(t_game *game)
{
    ft_printstr_fd("Player left the game!\n", 1);
    clean_exit(game, 0);
    return (0);
}

int key_press(int keycode, t_game *game)
{
    if (keycode == S)
       game->player.move.y = 1;
    if (keycode == D)
        game->player.move.x = 1;
    if (keycode == W)
        game->player.move.y = -1;
    if (keycode == A)
        game->player.move.x = -1;
    if (keycode == LEFT)
        game->player.rotate = -1;
    if (keycode == RIGHT)
        game->player.rotate = 1;
    else if (keycode == ESC)
        quit(game);
    return (0);
}

int key_release(int keycode, t_game *game)
{
    if (keycode == S)
        game->player.move.y = 0;
    if (keycode == D)
        game->player.move.x = 0;
    if (keycode == W)
        game->player.move.y = 0;
    if (keycode == A)
        game->player.move.x = 0;
    if (keycode == LEFT)
        game->player.rotate = 0;
    if (keycode == RIGHT)
        game->player.rotate = 0;
    return (0);
}

void key_bind(t_game *game)
{
    mlx_hook(game->mlx_win, 17, 0, quit, game);
    mlx_hook(game->mlx_win, 2, 1L << 0, key_press, game);
    mlx_hook(game->mlx_win, 3, 1L << 1, key_release, game);
    // mouse rotation è bonus
}
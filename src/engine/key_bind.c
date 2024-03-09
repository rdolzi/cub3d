/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_bind.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdolzi <rdolzi@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 01:03:17 by rdolzi            #+#    #+#             */
/*   Updated: 2024/03/09 18:46:22 by rdolzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cube.h"

void key_bind(t_game *game)
{
    (void) game; 
    // da definire in engine
    // mlx_hook(game->mlx_win, 17, 0, close_window, game);
    // mlx_hook(game->mlx_win, 2, 1L << 0, key_hook_press, (void *)game);
    // mlx_hook(game->mlx_win, 3, 1L << 1, key_hook_release, (void *)game);
    // mouse rotation è bonus
}
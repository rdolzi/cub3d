/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdolzi <rdolzi@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 23:33:31 by rdolzi            #+#    #+#             */
/*   Updated: 2024/03/06 23:37:29 by rdolzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cube.h"

void raycasting()
{
    // while win height
    // init ray info
    // set dda (per dir_x & dir_y< 0)
    // perform dda
    // implement the DDA algorithm:
    //(the loop will increment 1 square until we hit a wall)
}

void render_frame(t_game *game)
{
    // create image
    // init image (nuova, nessun img precedente è usata)
    // while win_height
    // while win_height
    // set_frame (cealing or floor or image)
    // put image
    // destroy image
}

// mlx_loop_hook's function
void render(t_game *game)
{
    // fa il free + calloc di texture_pixels
    reset_texture_pixels(game);
    // resetta valori di default del ray
    reset_ray(&game->ray);
    raycasting(&game->player, game);
    render_frame(game);
}
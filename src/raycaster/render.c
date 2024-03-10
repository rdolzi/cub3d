/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdolzi <rdolzi@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 23:33:31 by rdolzi            #+#    #+#             */
/*   Updated: 2024/03/11 00:55:22 by rdolzi           ###   ########.fr       */
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
    (void)game;
    // create image
    // init image (nuova, nessun img precedente è usata)
    // while win_height
    // while win_height
    // set_frame (cealing or floor or image)
    // put image
    // destroy image
}

void check_move(t_game *game, int y, int x)
{
    int new_x;
    int new_y;

    new_x = game->player.pos_x + x;
    new_y = game->player.pos_y + y;
    if (game->map[new_y][new_x] == '0')
        move_player(game, new_y, new_x);
    if (game->map[new_y][new_x] == '1')
        return;
}

int has_moved(t_game *game)
{
    // so long logic
    // has moved if: key_pressed + can_actually_move
    t_player *p;
    int has_moved;

    has_moved = 0;
    p = &game->player;
    if (p->move_x != 0 || p->move_y !=0)
        has_moved = check_move(game, p->move_x, p->move_y); //or move_player
    if (p->rotate !=0)
        has_moved = rotate_player();
    return (has_moved);
}

// mlx_loop_hook's function
void render(t_game *game)
{
    // 0)FA IL FREE + CALLOC DI TEXTURE_PIXELS
    // 1) RESET
    //      1.1)reset_texture_pixels(game);
    //      1.2)resetta valori di default del ray
    //      1.3)reset_ray(&game->ray);
    // 2)raycasting
    // 3)update_fps(game);
    // 4)render_frame(game);
    if (has_moved(game)) // -> so long logic
    {
        reset_render(game);
        raycasting(game); //define movespeed
        update_fps(game);
        render_frame(game);
    } 
    return (0);
}
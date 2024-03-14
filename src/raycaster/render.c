/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdolzi <rdolzi@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 23:33:31 by rdolzi            #+#    #+#             */
/*   Updated: 2024/03/14 00:57:55 by rdolzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cube.h"

// while win height
// init ray info
// set dda (per dir_x & dir_y< 0)
// perform dda
// implement the DDA algorithm:
//(the loop will increment 1 square until we hit a wall)
void raycasting(t_game *game)
{
    int pixel;

    pixel = 0;
    while (pixel < game->win_width)
    {
        //init_raycasting_info(pixel, &ray, player);
        build_ray(game, pixel);
        build_texture(game);
        set_step_and_side_dist(game);
        perform_dda(game);
        calculate_wall_distance(game);
        update_texture(game, pixel);
        pixel++;
    }
}

// create image
// init image (nuova, nessun img precedente è usata)
// while win_height
// while win_height
// set_frame (cealing or floor or image)
// put image
// destroy image
void print_frame(t_game *game)
{
    t_img image;
    int w;
    int h;

    // image.img = NULL;
    alloc_img(game, &image);
    h = 0;
    while (h < game->win_height)
    {
        w = 0;
        while (w < game->win_width)
        {
            if (game->texture_pixels[h][w] > 0)
                set_pixel(image, w, h, game->texture_pixels[h][w]);
            else if (h < game->win_height / 2)
                set_pixel(image, w, h, game->type[CEALING].hex);
            else if (h < game->win_height - 1)
                set_pixel(image, w, h, game->type[FLOOR].hex);
            w++;
        }
        h++;
    }
    mlx_put_image_to_window(game->mlx, game->mlx, image.img, 0, 0);
    mlx_destroy_image(game->mlx, image.img);
}

// 0)FA IL FREE + CALLOC DI TEXTURE
// 1) RESET
//      1.1)reset_texture_pixels(game);
//      1.2)resetta valori di default del ray
//      1.3)reset_ray(&game->ray);
// 2)raycasting
// 3)update_fps(game);
// 4)print_frame(game);
void render_image(t_game *game)
{
    reset_render(game);
    raycasting(game); // define movespeed
    update_fps(game); // calculate and print fps in image's frame
    print_frame(game);
}

// mlx_loop_hook's function
// will render a new image only if player has moved
void render(t_game *game)
{
    if (has_moved(game)) // -> so long logic
        render_image(game);
    return (0);
}

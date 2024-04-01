/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_screen.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdolzi <rdolzi@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 16:10:27 by rdolzi            #+#    #+#             */
/*   Updated: 2024/03/17 16:58:17 by rdolzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cube.h"

void set_pixel(t_img *image, int w, int h, int texture)
{
    int	idx;

	idx = h * (image->line_length / 4) + w;
	image->addr[idx] = texture;
}


void alloc_img(t_game *game, t_img *image)
{
    init_image(image);
    image->img = mlx_new_image(game->mlx, game->win_width, game->win_height);
	if (image->img == NULL)
		clean_exit(game, throw_exception(SYSTEM_EXCEPTION, ERR_MLX, NULL));
	image->addr = (int *)mlx_get_data_addr(image->img, &image->bpp,
			&image->line_length, &image->endian);
}

/*
It iterates over each pixel in the game window starting from
the top-left corner and moving row by row (h for height and w for width).
For each pixel:
-it checks the corresponding value in the game->pixels array.
    -If the value is greater than 0, it means there's a color
    associated with that pixel, so it sets the color of the 
    pixel in the image structure using the set_pixel function.
    
    -If the value in game->pixels is == 0, it means that no color
    has been assigned to that pixel. In this case, it checks
    if the current pixel is in the upper half of the screen (h < game->win_height / 2).
        -If it is, it sets the color of the pixel to the ceiling color (game->type[CEALING].hex).
        -Otherwise, if the pixel is in the lower half of the screen, so
        it sets the color of the pixel to the floor color 
        (game->type[FLOOR].hex)
*/


void print_screen(t_game *game)
{
    t_img image;
    int w;
    int h;

    alloc_img(game, &image);
    h = 0;
    while (h < game->win_height)
    {
        w = 0;
        while (w < game->win_width)
        {
            if (game->pixels[h][w] > 0)
                set_pixel(&image, w, h, game->pixels[h][w]);
            else if (h < game->win_height / 2)
                set_pixel(&image, w, h, game->type[CEALING].hex);
            else
                set_pixel(&image, w, h, game->type[FLOOR].hex);
            w++;
        }
        h++;
    }
    mlx_put_image_to_window(game->mlx, game->mlx_win, image.img, 0, 0);
    mlx_destroy_image(game->mlx, image.img);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cardinal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdolzi <rdolzi@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 14:51:47 by rdolzi            #+#    #+#             */
/*   Updated: 2024/04/16 02:05:10 by rdolzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../include/cube.h"

// Handling of img is done using ROW-MAJOR ORDER: a tecnique that flatten
// a 2-dimensional representation (a grid) into a 1-dimensional array.
// This is a common technique when dealing with images stored in memory.
// for more information read description.txt file

//todo: destroy walls


void	xpm_to_img(t_game *game, int cardinal)
{
    t_img *img;

	// printf("entra in xpm_to_img\n");
    img = &game->walls[cardinal];
	check_input(game, XPM, game->walls[cardinal].path);
	// printf("pre mlx_xpm_file_to_image,img->path:%s|len:%d \n", img->path, (int)ft_strlen(img->path));
	// printf("pre mlx_xpm_file_to_image,game->mlx:%p \n", game->mlx);
	img->img = mlx_xpm_file_to_image(game->mlx, img->path,
			&img->width, &img->height); //?
	// printf("POST mlx_xpm_file_to_image,img->img:%p \n", img->img);
	if (img->img == NULL)
		clean_exit(game, throw_exception(SYSTEM_EXCEPTION, ERR_MLX, NULL));
	img->addr = (int *)mlx_get_data_addr(img->img, &img->bpp,
			&img->line_length, &img->endian);
	// printf("esce da xpm_to_img\n");
}

int	*parse_xpm(t_game *game, int cardinal)
{
	int		x;
	int		y;
    int		*row_major;
	
	printf(">>parse_xpm\n");
	xpm_to_img(game, cardinal);
	row_major = ft_calloc(1,
			sizeof(*row_major) * TEXTURE_SIZE * TEXTURE_SIZE);
	if (!row_major)
		 clean_exit(game, throw_exception(SYSTEM_EXCEPTION, ERR_MALLOC, NULL));
	y = 0;
	while (y < TEXTURE_SIZE)
	{
		x = 0;
		while (x < TEXTURE_SIZE)
		{
			row_major[y * TEXTURE_SIZE + x]
				= game->walls[cardinal].addr[y * TEXTURE_SIZE + x];
			x++;
		}
		y++;
	}
	return (row_major);
}


// each game->textures array use row-major order to store and access img
// throws exception if xpm path is not found
void parse_cardinal(t_game *game)
{
    enum e_cardinal cardinal;
    
	printf("entra in parse_cardinal\n");
    cardinal = NORTH;
    game->textures = ft_calloc(5, sizeof * game->textures);
    if (!game->textures)
		clean_exit(game, throw_exception(SYSTEM_EXCEPTION, ERR_MALLOC, NULL));
    while (cardinal <= WEST) {
        if (game->walls[cardinal].path == NULL)
            clean_exit(game, throw_exception(MAP_EXCEPTION, ERR_MAP_CARDINAL, NULL));
       game->textures[cardinal] = parse_xpm(game, (int)cardinal);
        cardinal++;
    }
	printf("esce in parse_cardinal\n");
}

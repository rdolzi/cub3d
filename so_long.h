/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdolzi <rdolzi@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 18:16:07 by vpalacio          #+#    #+#             */
/*   Updated: 2023/10/16 01:29:35 by rdolzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./mlx/mlx.h"

# define W 13
# define A 0
# define ESC 53
# define S 1
# define D 2

typedef struct s_image
{
	void *img;
	int *data;
	int bpp;
	int size_l;
	int endian;
} t_image;

typedef struct s_player
{
	float px;  // pos x
	float py;  // pos y
	float pdx; // pos in  deg x ?
	float pdy; // pos in  deg y ?
	float pa;  // angle ?
} t_player;

typedef struct s_game
{
	t_image			bg;
	void			*mlx;
	void			*mlx_win;
	t_image			*map_img;
	t_image			*sqr_img;
	int				x;
	int				y;
	t_player		player;
}					t_game;

#endif
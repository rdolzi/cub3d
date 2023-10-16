/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdolzi <rdolzi@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 18:15:36 by vpalacio          #+#    #+#             */
/*   Updated: 2023/10/16 01:25:52 by rdolzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "so_long.h"
#include <stdlib.h>
#include <unistd.h>

// int	fai_cose(int keycode, t_game *ciao)
// {
// 	if (keycode == S)
// 	{
// 		ciao->y +=50;
// 		mlx_put_image_to_window(ciao->mlx, ciao->mlx_window, ciao->image, ciao->x, ciao->y);
// 	}
// 	if (keycode == D)
// 	{
// 		ciao->x +=50;
// 		mlx_put_image_to_window(ciao->mlx, ciao->mlx_window, ciao->image, ciao->x, ciao->y);
// 	}
// 	if (keycode == W)
// 	{
// 		ciao->y -=50;
// 		mlx_put_image_to_window(ciao->mlx, ciao->mlx_window, ciao->image, ciao->x, ciao->y);
// 	}
// 	if (keycode == A)
// 	{
// 		ciao->x -=50;
// 		mlx_put_image_to_window(ciao->mlx, ciao->mlx_window, ciao->image, ciao->x, ciao->y);
// 	}
// 	else if (keycode == ESC)
// 		exit(write(1, "Player left the game!", 21) * 0);
// 	return (0);
// }

// int	exit_x(void)
// {
// 	write(1, "Player exited the game!", 23);
// 	exit (0);
// } 

// int	main(void)
// {
// 	t_game	pippo;
// 	void	*sakura;
// 	void	*baby;
// 	void	*byebye;
// 	int		i;
// 	int		j;

// 	pippo.x = 100;
// 	pippo.y = 100;
// 	pippo.mlx = mlx_init();
// 	pippo.mlx_window = mlx_new_window(pippo.mlx, 1200, 1000, "so_long");
// 	pippo.image = mlx_xpm_file_to_image(pippo.mlx, "images/player.xpm", &i, &j);
// 	mlx_put_image_to_window(pippo.mlx, pippo.mlx_window, pippo.image, 30, 30);
// 	mlx_put_image_to_window(pippo.mlx, pippo.mlx_window, pippo.image, 100, 104);
// 	sakura = mlx_xpm_file_to_image(pippo.mlx, "images/sakura.xpm", &i, &j);
// 	mlx_put_image_to_window(pippo.mlx, pippo.mlx_window, sakura, 200, 100);
// 	baby = mlx_xpm_file_to_image(pippo.mlx, "images/baby.xpm", &i, &j);
// 	mlx_put_image_to_window(pippo.mlx, pippo.mlx_window, baby, 300, 500);
// 	byebye = mlx_xpm_file_to_image(pippo.mlx, "images/byebye.xpm", &i, &j);
// 	mlx_put_image_to_window(pippo.mlx, pippo.mlx_window, byebye, 500, 400);
// 	mlx_key_hook(pippo.mlx_window, fai_cose, &pippo);
// 	mlx_hook(pippo.mlx_window, 17, 0, exit_x, &pippo);
// 	mlx_pixel_put(pippo.mlx, pippo.mlx_window, 5, 5, 0x00FF0000);
// 	mlx_loop(pippo.mlx);
// }

// int main(void)
// {
// 	t_game pippo;
// 	int i;
// 	int j;

// 	pippo.x = 100;
// 	pippo.y = 100;
// 	pippo.mlx = mlx_init();
// 	pippo.mlx_window = mlx_new_window(pippo.mlx, 1200, 1000, "so_long");
// 	pippo.image = mlx_xpm_file_to_image(pippo.mlx, "images/player.xpm", &i, &j);
// 	mlx_put_image_to_window(pippo.mlx, pippo.mlx_window, pippo.image, 30, 30);
// 	// mlx_put_image_to_window(pippo.mlx, pippo.mlx_window, pippo.image, 100, 104);
// 	// mlx_key_hook(pippo.mlx_window, fai_cose, &pippo);
// 	// mlx_hook(pippo.mlx_window, 17, 0, exit_x, &pippo);
// 	mlx_pixel_put(pippo.mlx, pippo.mlx_window, 5, 5, 0x00FF0000);
// 	mlx_pixel_put(pippo.mlx, pippo.mlx_window, 5, 6, 0x00FF0000);
// 	mlx_pixel_put(pippo.mlx, pippo.mlx_window, 5, 7, 0x00FF0000);
// 	mlx_loop(pippo.mlx);
// }
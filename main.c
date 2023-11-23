/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdolzi <rdolzi@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 13:59:53 by flaviobiond       #+#    #+#             */
/*   Updated: 2023/11/23 19:09:34 by rdolzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"



void init_mlx(t_cub3d *cub3d)
{
     cub3d->mlx =  mlx_init();
    cub3d->mlx_win = mlx_new_window(cub3d->mlx, 500, 500, "CUB3D" );
    cub3d->minimap.img.img = mlx_new_image(cub3d->mlx, cub3d->env.x * 11,
			cub3d->env.y * 11);
    cub3d->minimap.img.addr = mlx_get_data_addr(cub3d->minimap.img.img,
			&cub3d->minimap.img.bits_per_pixel, &cub3d->minimap.img.line_length,
			&cub3d->minimap.img.endian);
    mlx_loop(cub3d->mlx);
}
void ft_parser(t_data *game, int ac, char *av)
{
     ft_check_input(game, ac, av);
     parser_cub(game, av);
     check_map(game);
}
void	ft_free_mat(char **mat)
{

	if (!(*mat))
		return ;
	while ((*mat))
		free((*mat));
	free(*mat);
	*mat = NULL;
}

int main(int ac, char **av)
{
    t_data game;
    t_cub3d cub3d;
  
    ft_bzero(&game, sizeof(t_data));
    ft_parser(&game,ac,av[1]);
   
    // ft_check_input(&game, ac, av[1]);
    // parser_cub(&game, av[1]);
    //   long_len_x(&game);
    //       printf("%zu\n", game.x);
    // ft_print_mat(game.map_x);
    // ft_free_mat(game.map_x);
    init_mlx(&cub3d);
}

// parser
// vedi i tab  v
// vedi se non ci sono piu personaggi nella mappa
// se la mappa giocabile

// s
// | KEY           | Action        |
// | ------------- |:-------------:|
// | `ESC`         | exit game     |
// | `A`           | move left     |
// | `D`           | move right    |
// | `W`           | move forward  |
// | `S`           | move backward |
// | `→`           | turn right    |
// | `←`           | turn left     |
// | `M`           | hide/display map|
// | `O`           | open/close door|
// | `P`           | open/close secret door|
// | `option`      | change weapon |
// | `F10`         | sound on/off |
//code
// | `1`            | wall          |
// | `0`            | floor         |
// | `2`            | sprite #1     |
// | `3`            | sprite #2     |
// | `N`/`E`/`W`/`S`| player initial position + orientation|
// | `A`            | ammo          |
//*
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdolzi <rdolzi@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 04:08:56 by rdolzi            #+#    #+#             */
/*   Updated: 2024/04/26 04:10:37 by rdolzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cube.h"

int	mouse_control(int x,int y, t_game *game)
{
	int half_width;
	(void)y;
	// printf("x:%d ", x);
	// printf("y:%d", y);
	
	half_width = (int )WIN_WIDTH / 2;
	if (x > half_width - 60 && x < half_width + 60)
	{
		// printf("rimane fermo\n");
		game->player.rotate = 0;
	}
	else if (x < half_width - 40)
	{
		// printf("gira a sinistra\n");
		game->player.rotate = -0.45; 
	}
	else
	{
		// printf("gira a destra\n");
		game->player.rotate = 0.45; 
	}
	return (0);
}
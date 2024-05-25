/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdolzi <rdolzi@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 04:08:56 by rdolzi            #+#    #+#             */
/*   Updated: 2024/05/25 15:39:13 by rdolzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cube.h"

int	mouse_control(int x, int y, t_game *game)
{
	int	half_width;

	(void)y;
	half_width = (int )WIN_WIDTH / 2;
	if (x > half_width - 60 && x < half_width + 60)
	{
		game->player.rotate = 0;
	}
	else if (x < half_width - 40)
	{
		game->player.rotate = -0.45;
	}
	else
	{
		game->player.rotate = 0.45;
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdolzi <rdolzi@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 23:21:32 by rdolzi            #+#    #+#             */
/*   Updated: 2024/05/25 18:34:45 by rdolzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cube.h"

/**
 * @brief Rotates the player's view left or right.
 *
 * This function rotates the player's view left or
 * right based on the given rotation speed, adjusting
 * the direction of the player's vision.
 *
 * @param game Pointer to the game data structure
 *             containing player information.
 * @return 1 always indicating the rotation is successful.
 */
int	rotate_player_view(t_game *game)
{
	t_player	*p;
	double		tmp;
	double		rotation;

	p = &game->player;
	rotation = 0.055 * game->player.rotate;
	tmp = p->direction.x;
	p->direction.x = p->direction.x * cos(rotation)
		- p->direction.y * sin(rotation);
	p->direction.y = tmp * sin(rotation) + p->direction.y * cos(rotation);
	tmp = p->cam_plane.x;
	p->cam_plane.x = p->cam_plane.x * cos(rotation)
		- p->cam_plane.y * sin(rotation);
	p->cam_plane.y = tmp * sin(rotation) + p->cam_plane.y * cos(rotation);
	return (1);
}

int	is_valid(t_game *game, int x, int y)
{
	double	safe_net;

	safe_net = 0.25;
	if (x < safe_net || x >= WIN_WIDTH - 1 - safe_net)
		return (0);
	if (y < safe_net || y >= WIN_HEIGHT
		- 1 * safe_net)
		return (0);
	if (game->map[(int)y][(int)x] == '1')
		return (0);
	return (1);
}

int	move_player(t_game *game, int x, int y)
{
	double		new_x;
	double		new_y;
	t_player	*p;

	p = &game->player;
	if (p->move.x == 1 || p->move.x == -1)
	{
		new_x = p->position.x + (p->direction.y * x) * 0.15;
		new_y = p->position.y + (p->direction.x * y) * 0.15;
	}
	else
	{
		new_x = p->position.x + (p->direction.x * x) * 0.15;
		new_y = p->position.y + (p->direction.y * y) * 0.15;
	}
	if (is_valid(game, new_x, new_y))
	{
		game->player.position.x = new_x;
		game->player.position.y = new_y;
		return (1);
	}
	return (0);
}

int	has_moved(t_game *game)
{
	t_player	*p;
	int			has_moved;

	has_moved = 0;
	p = &game->player;
	if (p->move.x == -1)
		has_moved = move_player(game, 1, -1);
	else if (p->move.x == 1)
		has_moved = move_player(game, -1, 1);
	else if (p->move.y == -1)
		has_moved = move_player(game, 1, 1);
	else if (p->move.y == 1)
		has_moved = move_player(game, -1, -1);
	if (p->rotate != 0)
		has_moved = rotate_player_view(game);
	return (has_moved);
}

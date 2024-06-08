/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_algorithm.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdolzi <rdolzi@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 00:17:31 by rdolzi            #+#    #+#             */
/*   Updated: 2024/06/08 11:55:39 by rdolzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cube.h"

/**
 * @brief Initializes data required 
 * for the raycasting algorithm.
 *
 * This function initializes data such as camera position,
 *  ray direction, and map coordinates necessary for the
 * raycasting algorithm to generate a 3D perspective view
 * of the scene.
 * NDC: maps the screen coordinates to normalized device
 * coordinates (NDC) in the range [-1, 1]. This is a common
 * transformation used in computer graphics to map screen space
 * to a coordinate system where -1 represents the left edge of
 * the screen and 1 represents the right edge.
 *
 * @param column The horizontal position of the current
 *               column being processed.
 * @param game Pointer to the game structure containing
 *             player and ray information.
 */
void	initialize_raycasting_data(t_game *game, int column)
{
	t_ray		*ray;
	t_player	*player;

	init_ray(game);
	ray = &game->ray;
	player = &game->player;
	ray->ndc = 2 * column / (double) WIN_WIDTH - 1;
	ray->direction.x = player->direction.x + player->cam_plane.x * ray->ndc;
	ray->direction.y = player->direction.y + player->cam_plane.y * ray->ndc;
	ray->player_pos.x = (int)player->position.x;
	ray->player_pos.y = (int)player->position.y;
	ray->delta_distance.x = fabs(1 / ray->direction.x);
	ray->delta_distance.y = fabs(1 / ray->direction.y);
}

/**
 * @brief Calculates the height of the wall lines to
 *        be drawn on the screen.
 *
 * This function calculates the height of the wall
 * lines to be drawn on the screen based on the distance
 * to the walls in the scene, ensuring accurate
 * representation of the game environment during rendering.
 *
 * @param game Pointer to the game data structure containing
 *             rendering information.
 */
// Calculate line height based on preparation wall distance
// Calculate draw start position
// Adjust draw start if it's outside the screen boundaries
// Calculate draw end position
// Adjust draw end if it's outside the screen boundaries
// set wall_x
void	compute_wall_line_height(t_game *game)
{
	t_ray		*ray;
	t_player	*player;

	ray = &game->ray;
	player = &game->player;
	if (ray->side == EAST || ray->side == WEST)
		ray->wall_dist = ray->side_distance.x - ray->delta_distance.x;
	else
		ray->wall_dist = ray->side_distance.y - ray->delta_distance.y;
	ray->line_height = WIN_HEIGHT / ray->wall_dist;
	ray->draw_start = -ray->line_height / 2 + WIN_HEIGHT / 2;
	if (ray->draw_start <= 0)
		ray->draw_start = 0;
	ray->draw_end = ray->line_height / 2 + WIN_HEIGHT / 2;
	if (ray->draw_end >= WIN_HEIGHT)
		ray->draw_end = WIN_HEIGHT - 1;
	if (ray->side == WEST || ray->side == EAST)
		ray->wall_x = player->position.y + ray->wall_dist * ray->direction.y;
	else
		ray->wall_x = player->position.x + ray->wall_dist * ray->direction.x;
	ray->wall_x -= floor(ray->wall_x);
}

void	set_pix(t_game *game, t_ray	*ray)
{
	game->pix_step = 1.0 * TEXTURE_SIZE / ray->line_height;
	game->pix_pos = (ray->draw_start - WIN_HEIGHT / 2
			+ ray->line_height / 2) * game->pix_step;
}

void	update_pixels(t_game *game, int column)
{
	t_ray	*ray;
	int		x;
	int		y;
	int		y1;
	int		color;

	ray = &game->ray;
	x = (int)(ray->wall_x * TEXTURE_SIZE);
	if (((ray->side == EAST || ray->side == WEST) && ray->direction.x < 0)
		|| ((ray->side == SOUTH || ray->side == NORTH) && ray->direction.y > 0))
		x = TEXTURE_SIZE - x - 1;
	set_pix(game, ray);
	y = ray->draw_start;
	while (y < ray->draw_end)
	{
		y1 = (int)game->pix_pos & (TEXTURE_SIZE - 1);
		game->pix_pos += game->pix_step;
		color = game->textures[ray->side][TEXTURE_SIZE * y1 + x];
		if (ray->side == NORTH || ray->side == EAST)
			color = (color >> 1) & 8355711;
		if (color > 0)
			game->pixels[y][column] = color;
		y++;
	}
}

/**
 * @brief Orchestrates the rendering process for the
 *        entire scene.
 *
 * This function orchestrates the rendering process for
 * the entire scene, including casting rays, performing
 * intersection tests, and calculating line heights for walls.
 *
 * @param game Pointer to the game data structure containing
 *             rendering information.
 */
void	raycasting(t_game *game)
{
	int	column;

	column = 0;
	while (column < game->win_width)
	{
		initialize_raycasting_data(game, column);
		set_step_and_side_distance(game);
		perform_digital_differential_analysis(game);
		compute_wall_line_height(game);
		update_pixels(game, column);
		column++;
	}
}

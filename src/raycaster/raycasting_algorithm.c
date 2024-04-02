/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_algorithm.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdolzi <rdolzi@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 00:17:31 by rdolzi            #+#    #+#             */
/*   Updated: 2024/04/02 01:37:22 by rdolzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cube.h"

/**
 * @brief Initializes data required for the raycasting algorithm.
 *
 * This function initializes data such as camera position, ray direction, and map coordinates necessary for the raycasting algorithm to generate a 3D perspective view of the scene.
 * NDC: maps the screen coordinates to normalized device coordinates (NDC) in the range [-1, 1]. This is a common transformation used in computer graphics to map screen space to a coordinate system where -1 represents the left edge of the screen and 1 represents the right edge.
 *
 * @param column The horizontal position of the current column being processed.
 * @param game Pointer to the game structure containing player and ray information.
 */
void initialize_raycasting_data(t_game *game, int column)
{
    t_ray *ray;
    t_player *player;

    init_ray(game);
    ray = &game->ray;
    player = &game->player;

	ray->ndc = 2 * column / (double)WIN_WIDTH - 1;
	ray->direction.x = player->direction.x + player->cam_plane.x * ray->ndc;
	ray->direction.y = player->direction.y + player->cam_plane.y * ray->ndc;
	ray->player_pos.x = (int)player->position.x;
	ray->player_pos.y = (int)player->position.y;
	ray->delta_distance.x = fabs(1 / ray->direction.x);
	ray->delta_distance.y = fabs(1 / ray->direction.y);
}

/**
 * @brief Calculates the height of the wall lines to be drawn on the screen.
 *
 * This function calculates the height of the wall lines to be drawn 
 * on the screen based on the distance to the walls in the scene, ensuring
 *  accurate representation of the game environment during rendering.
 *
 * @param game Pointer to the game data structure containing rendering information.
 */
void compute_wall_line_height(t_game *game)
{
    t_ray *ray;
    t_player *player;

    ray = &game->ray;
    player = &game->player;
    if (ray->side == EAST || ray->side == WEST)
        ray->wall_dist = ray->side_distance.x - ray->delta_distance.x;
    else
        ray->wall_dist = ray->side_distance.y - ray->delta_distance.y;
        
    // Calculate line height based on preparation wall distance
    ray->line_height = WIN_HEIGHT / ray->wall_dist;
    
    // Calculate draw start position
    ray->draw_start = -ray->line_height / 2 + WIN_HEIGHT / 2;
    
    // Adjust draw start if it's outside the screen boundaries
    if (ray->draw_start <= 0)
        ray->draw_start = 0;
    
    // Calculate draw end position
    ray->draw_end = ray->line_height / 2 + WIN_HEIGHT / 2;
    
    // Adjust draw end if it's outside the screen boundaries
    if (ray->draw_end >= WIN_HEIGHT)
        ray->draw_end = WIN_HEIGHT - 1;

    // set wall_x
    if (ray->side == WEST || ray->side == EAST)
		ray->wall_x = player->position.y + ray->wall_dist * ray->direction.y;
	else
		ray->wall_x = player->position.x + ray->wall_dist * ray->direction.x;
	ray->wall_x -= floor(ray->wall_x);
}

void update_pixels(t_game *game, int column)
{
    t_ray *ray;
    int         x;
    int			y;
    int         y1;
    int			color;
    
    ray = &game->ray;
    // parse_texture(game); viene fatto durante la fase di build
	x = (int)(ray->wall_x * TEXTURE_SIZE);
	if (((ray->side == EAST || ray->side == WEST) && ray->direction.x < 0)
		|| ((ray->side == SOUTH || ray->side == NORTH) && ray->direction.y > 0))
		x = TEXTURE_SIZE - x - 1;
	ray->s = 1.0 * TEXTURE_SIZE / ray->line_height;
	ray->pos = (ray->draw_start - WIN_HEIGHT / 2
			+ ray->line_height / 2) * ray->s;
	y = ray->draw_start;
	while (y < ray->draw_end)
	{
		y1 = (int)ray->pos & (TEXTURE_SIZE - 1);
		ray->pos += ray->s;
		color = game->textures[ray->side][TEXTURE_SIZE * y1 + x];
		if (ray->side == NORTH || ray->side == EAST)
			color = (color >> 1) & 8355711;
		if (color > 0)
			game->pixels[y][x] = color;
		y++;
	}
}

/**
 * @brief Orchestrates the rendering process for the entire scene.
 *
 * This function orchestrates the rendering process for the entire scene, including casting rays, performing intersection tests, and calculating
 * line heights for walls.
 *
 * @param game Pointer to the game data structure containing rendering information.
 */
void raycasting(t_game *game)
{
    int column;

    column = 0;
    while (column < game->win_width)
    {
        initialize_raycasting_data(game, column); // -> done
        set_step_and_side_distance(game); // -> done
        perform_digital_differential_analysis(game); // -> done
        compute_wall_line_height(game); // -> done
        update_pixels(game, column);
        column++;
    }
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_algorithm.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdolzi <rdolzi@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 00:17:31 by rdolzi            #+#    #+#             */
/*   Updated: 2024/03/17 04:06:30 by rdolzi           ###   ########.fr       */
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
    (void)game;
}

void update_pixels(t_game *game, int column)
{
    (void) game;
    (void) column;
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
        compute_wall_line_height(game);
        update_pixels(game, column);
        column++;
    }
}

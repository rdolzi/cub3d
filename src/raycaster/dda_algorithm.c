/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_algorithm.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdolzi <rdolzi@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 03:50:26 by rdolzi            #+#    #+#             */
/*   Updated: 2024/04/21 01:19:07 by rdolzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cube.h"

// initial set up dda
void set_step_and_side_distance(t_game *game)
{
    t_ray *ray;
    t_player *player;

    ray = &game->ray;
    player = &game->player;
    if (ray->direction.x < 0)
	{
		ray->step.x = -1;
		ray->side_distance.x = (player->position.x - ray->player_pos.x) * ray->delta_distance.x;
	}
	else
	{
		ray->step.x = 1;
		ray->side_distance.x = (ray->player_pos.x + 1.0 - player->position.x) * ray->delta_distance.x;
	}
	if (ray->direction.y < 0)
	{
		ray->step.y = -1;
		ray->side_distance.y = (player->position.y - ray->player_pos.y) * ray->delta_distance.y;
	}
	else
	{
		ray->step.y = 1;
		ray->side_distance.y = (ray->player_pos.y + 1.0 - player->position.y) * ray->delta_distance.y;
	}
    printf(">>>>IN set_step_and_side_distance\n");
    // print_ray_stats(game);
    // print_player_stats(game); 
}

void update_ray_position_to_next_wall(t_game *game)
{
    t_ray *ray;

    ray = &game->ray;
    if (ray->side_distance.x < ray->side_distance.y)
    {
        ray->side_distance.x += ray->delta_distance.x;
        ray->player_pos.x += ray->step.x;
        if (ray->step.x == -1)
            ray->side = EAST;
        else
            ray->side = WEST;
    }
    else
    {
        ray->side_distance.y += ray->delta_distance.y;
        ray->player_pos.y += ray->step.y;
        if (ray->step.y == -1)
            ray->side = SOUTH;
        else
            ray->side = NORTH;
    }
}

/**
 * @brief Performs the Digital Differential Analyzer algorithm.
 *
 * This function performs the Digital Differential Analyzer algorithm
 * as part of the raycasting process, incrementally tracing rays 
 * and detecting intersections with objects to generate a realistic 
 * 3D perspective view.
 *
 * Boundary Conditions:
 * The if condition checks if the ray has crossed the boundaries of the map.
 * The values 0.25 and 1.25 are used as buffer margins to ensure the
 * ray doesn't fall exactly on the boundary lines, which could lead to
 * inaccuracies or errors.
 * @param game Pointer to the game data structure containing raycasting and player information.
 */
void perform_digital_differential_analysis(t_game *game)
{
    int hit;
    t_ray *ray;

    hit = 0;
    ray = &game->ray;
    while (hit == 0)
	{
        printf("HIT == 0\n");
		update_ray_position_to_next_wall(game);
		 // Adding buffer margins to handle map boundaries
        if (ray->player_pos.x < 0.25 || ray->player_pos.y < 0.25
            || ray->player_pos.x >= game->win_height - 1.25
            || ray->player_pos.y >= game->win_height - 1.25)
            hit = 1;
        else if (game->map[(int)ray->player_pos.y][(int)ray->player_pos.x] == '1')
            hit = 1;
	}
    printf(">>>>DOPO perform_digital_differential_analysis\n");
    // print_ray_stats(game);
    // print_player_stats(game);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_algorithm.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdolzi <rdolzi@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 00:17:31 by rdolzi            #+#    #+#             */
/*   Updated: 2024/04/21 01:19:16 by rdolzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cube.h"

void print_ray_stats(t_game *game)
{
    t_ray *ray;

    ray = &game->ray;

    printf("\n\n");
    printf("--------- ray stats ---------\n");
    printf("ray->direction.x:%f\n", ray->direction.x);
    printf("ray->direction.y:%f\n", ray->direction.y);
    printf("ray->player_pos.x:%f\n", ray->player_pos.x);
    printf("ray->player_pos.y:%f\n", ray->player_pos.y);
    printf("ray->delta_distance.x:%f\n", ray->delta_distance.x);
    printf("ray->delta_distance.y:%f\n", ray->delta_distance.y);
    printf("ray->step.x:%f\n", ray->step.x);
    printf("ray->step.y:%f\n", ray->step.y);
    printf("ray->side_distance.x:%f\n", ray->side_distance.x);
    printf("ray->side_distance.y:%f\n", ray->side_distance.y);
    printf("ray->ndc:%f\n", ray->ndc);
    printf("ray->side:%d\n", ray->side);
    printf("ray->wall_dist:%d\n", ray->wall_dist);
    printf("ray->wall_x:%d\n", ray->wall_x);
    printf("ray->line_height:%d\n", ray->line_height);
    printf("ray->draw_start:%d\n", ray->draw_start);
    printf("ray->draw_end:%d\n", ray->draw_end);
    printf("ray->s:%f\n", ray->s);
    printf("ray->pos:%f\n", ray->pos);
    printf("------------------------------\n");
}

void print_player_stats(t_game *game)
{
    t_player *plr;

    plr = &game->player;

    printf("\n\n");
    printf("-------- player stats --------\n");
    printf("plr->dir:%c\n", plr->dir);
    printf("plr->position.x:%f\n", plr->position.x);
    printf("plr->position.y:%f\n", plr->position.y);
    printf("plr->direction.x:%f\n", plr->direction.x);
    printf("plr->direction.y:%f\n", plr->direction.y);
    printf("plr->cam_plane.x:%f\n", plr->cam_plane.x);
    printf("plr->cam_plane.y:%f\n", plr->cam_plane.y);
    printf("plr->move.x:%f\n", plr->move.x);
    printf("plr->move.y:%f\n", plr->move.y);
    printf("plr->rotate:%d\n", plr->rotate);
    printf("------------------------------\n");
}

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

    printf("in initialize_raycasting_data\n");
    init_ray(game);
    ray = &game->ray;
    player = &game->player;

	ray->ndc = 2 * column / (double) WIN_WIDTH - 1;
    printf(">>:>:>:ray->ndc:%f\n", ray->ndc);
	ray->direction.x = player->direction.x + player->cam_plane.x * ray->ndc;
	ray->direction.y = player->direction.y + player->cam_plane.y * ray->ndc;
	ray->player_pos.x = (int)player->position.x;
	ray->player_pos.y = (int)player->position.y;
	ray->delta_distance.x = fabs(1 / ray->direction.x);
	ray->delta_distance.y = fabs(1 / ray->direction.y);

    // print_ray_stats(game);
    // print_player_stats(game); 
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
    // if (ray->wall_dist > 0) // float exc. perche wall_dist è 0
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

    printf(">>>>DOPO compute_wall_line_height\n");
    // print_ray_stats(game);
    // print_player_stats(game);
    
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
	game->pix_step = 1.0 * TEXTURE_SIZE / ray->line_height;
	game->pix_pos = (ray->draw_start - WIN_HEIGHT / 2
			+ ray->line_height / 2) * game->pix_step;
	y = ray->draw_start;
    printf("qui\n");
	while (y < ray->draw_end)
	{
		y1 = (int)game->pix_pos & (TEXTURE_SIZE - 1);
		game->pix_pos += game->pix_step;
		color = game->textures[ray->side][TEXTURE_SIZE * y1 + x];
		if (ray->side == NORTH || ray->side == EAST)
			color = (color >> 1) & 8355711;
		if (color > 0)
        {
            // printf("\n-- game->pixels[%d][%d] --\n", y, x);
            game->pixels[y][column] = color;
        }
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
    printf("game->win_width:%d\n", game->win_width);
    while (column < game->win_width)
    {
        printf(">>>>>>COLONNA:%d\n", column);
        initialize_raycasting_data(game, column); // -> done
        printf("in set_step_and_side_distance\n");
        set_step_and_side_distance(game); // -> done
        printf("in perform_digital_differential_analysis\n");
        perform_digital_differential_analysis(game); // -> done
        printf("in compute_wall_line_height\n");
        compute_wall_line_height(game); // -> done
        printf("in update_pixels\n");
        update_pixels(game, column);
        column++;
    }
    printf("esce da raycasting\n");
}

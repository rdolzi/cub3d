/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdolzi <rdolzi@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 23:21:32 by rdolzi            #+#    #+#             */
/*   Updated: 2024/04/21 01:07:50 by rdolzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cube.h"

int move_player(t_game *game, int new_y, int new_x)
{
    (void) game;
    (void) new_x;
    (void) new_y;
    return 1;
}

//  the function is responsible for rotating the player's view 
/**
 * @brief Rotates the player's view left or right.
 *
 * This function rotates the player's view left or right based on the given 
 * rotation speed, adjusting the direction of the player's vision.
 *
 * @param game Pointer to the game data structure containing player information.
 * @param rotspeed The rotation speed for the player's view.
 * @return 1 always indicating the rotation is successful.
 */
int rotate_player_view(t_game *game)
{
    (void)game;
    
    return 1;
}

int is_valid(int x, int y)
{
    double safe_net;

    safe_net = 0.25;
    if (x < safe_net || x >= WIN_WIDTH - 1 - safe_net)
		return (0);
	if (y < safe_net || y >= WIN_HEIGHT  - 1 * safe_net)
		return (0);
    return (1);
}

int check_movement(t_game *game, int y, int x)
{
    int new_x;
    int new_y;
    int res;

    res = 0;
    new_x = (int) game->player.position.x + x * 0.01;
    new_y = (int) game->player.position.y + y * 0.01;
    if (is_valid(new_x,  new_y) && 
        game->map[new_y][new_x] == '0')
    {
        game->player.position.x = new_x;
        game->player.position.y = new_y;
        res = 1;
    }
    return (res);
}

int has_moved(t_game *game)
{
    // so long logic
    // player has moved if: 
    //      > key_pressed + he_can_actually_move(no walls in front of him)
    t_player *p;
    int has_moved;

    has_moved = 0;
    p = &game->player;
    if (p->move.x != 0 || p->move.y != 0)
        has_moved = check_movement(game, p->direction.x, p->direction.y);
    if (p->rotate != 0)
        has_moved = rotate_player_view(game); //TODO
    return (has_moved);
}

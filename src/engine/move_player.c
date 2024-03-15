/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdolzi <rdolzi@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 23:21:32 by rdolzi            #+#    #+#             */
/*   Updated: 2024/03/15 01:00:34 by rdolzi           ###   ########.fr       */
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

int rotate_player(t_game *game)
{
    (void)game;
    return 1;
}

int check_movement(t_game *game, int y, int x)
{
    int new_x;
    int new_y;
    int res;

    res = 0;
    new_x = game->player.position.x + x;
    new_y = game->player.position.y + y;
    if (game->map[new_y][new_x] == '0')
        res = move_player(game, new_y, new_x);
    // if (game->map[new_y][new_x] == '1')
    //     return (0);
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
        has_moved = check_movement(game, p->move.x, p->move.y);
    if (p->rotate != 0)
        has_moved = rotate_player(game);
    return (has_moved);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdolzi <rdolzi@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 02:11:15 by rdolzi            #+#    #+#             */
/*   Updated: 2024/04/16 02:38:16 by rdolzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cube.h"

//parse_colors
//  check rgb
//  convert rgb
//  check color validity
void parse_color(t_game *game)
{
    (void) game;
    printf("\nin parse_color\n");
    printf("game->type[FLOOR].path:%s| len:%d\n", game->type[FLOOR].path, (int)ft_strlen(game->type[FLOOR].path));
}



/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdolzi <rdolzi@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 02:11:15 by rdolzi            #+#    #+#             */
/*   Updated: 2024/04/16 03:58:36 by rdolzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cube.h"

void convert_in_hexadecimal(t_game *game, int color)
{
    int *rgb;
    // fa lo split del path, controlla che siano 3 int(atoi) e li setta in array
    rgb = get_rgb(game, color);
    // controlla che siano rgb validi ovvero da 0 a 255
    if (is_valid_rgb(rgb))
        convert_rgb_to_hex(game, color, rgb); // converte rgb in hexadecimal
    else
        clean_exit(game, throw_exception(MAP_EXCEPTION, ERR_MAP_COLOR, NULL));
}

//parse_colors
//  check rgb
//  convert rgb
//  check color validity
void parse_color(t_game *game)
{
    enum e_color color;
    
	printf("entra in parse_color\n");
    color = FLOOR;
    while (color <= FLOOR) {
        if (game->type[color].path == NULL)
            clean_exit(game, throw_exception(MAP_EXCEPTION, ERR_MAP_COLOR, NULL));
        printf("game->type[color].path:%s| len:%d\n", game->type[color].path, (int)ft_strlen(game->type[color].path));
        convert_in_hexadecimal(game, (int)color);
        color++;
    }
	printf("esce in parse_color\n");
}



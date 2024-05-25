/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_in_hexadecimal.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdolzi <rdolzi@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 18:29:32 by rdolzi            #+#    #+#             */
/*   Updated: 2024/05/25 18:29:53 by rdolzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cube.h"

void	convert_rgb_to_hex(t_game *game, int color, int *rgb)
{
	int				r;
	int				g;
	int				b;

	r = rgb[0];
	g = rgb[1];
	b = rgb[2];
	game->type[color].hex = ((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff);
}

// fa lo split del path:
//  - controlla che siano 3 int(atoi)
//  - li setta in array
// controlla che siano rgb validi ovvero da 0 a 255
// converte rgb in hexadecimal
void	convert_in_hexadecimal(t_game *game, int color)
{
	int	*rgb;

	rgb = get_rgb(game, color);
	if (is_valid_rgb(game, rgb))
		convert_rgb_to_hex(game, color, rgb);
	else
		clean_exit(game, throw_exception(MAP_EXCEPTION, ERR_MAP_COLOR, NULL));
	free(rgb);
}

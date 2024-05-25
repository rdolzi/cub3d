/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdolzi <rdolzi@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 02:11:15 by rdolzi            #+#    #+#             */
/*   Updated: 2024/05/25 18:30:22 by rdolzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cube.h"

int	is_valid_rgb(t_game *game, int *rgb)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		if (rgb[i] < 0 || rgb[i] > 255)
			clean_exit(game, throw_exception(MAP_EXCEPTION,
					ERR_MAP_COLOR, NULL));
		i++;
	}
	return (1);
}

int	is_number(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	*char_matrix_to_int(t_game *game, char **mat)
{
	int	i;
	int	*rgb;

	i = 0;
	rgb = ft_calloc(3, sizeof(int));
	if (!rgb)
		clean_exit(game, throw_exception(SYSTEM_EXCEPTION, ERR_MALLOC, NULL));
	while (mat[i])
	{
		if (is_number(mat[i]) == 0)
			clean_exit(game, throw_exception(MAP_EXCEPTION,
					ERR_MAP_COLOR, NULL));
		rgb[i] = ft_atoi(mat[i]);
		i++;
	}
	free_matrix((void **)mat);
	return (rgb);
}

// fa lo split del path
// controlla che siano 3 elementi
// poi li inserisce in array trasformando
// elementi in int con atoi
int	*get_rgb(t_game *game, int color)
{
	int		i;
	char	**mat;

	i = 0;
	mat = ft_split(game->type[color].path, ',');
	while (mat[i])
		i++;
	if (i != 3)
	{
		free_matrix((void **)mat);
		clean_exit(game, throw_exception(MAP_EXCEPTION, ERR_MAP_COLOR, NULL));
	}
	return (char_matrix_to_int(game, mat));
}

void	parse_color(t_game *game)
{
	enum e_color	color;

	color = FLOOR;
	while (color <= CEALING)
	{
		if (game->type[color].path == NULL)
			clean_exit(game, throw_exception(MAP_EXCEPTION,
					ERR_MAP_COLOR, NULL));
		convert_in_hexadecimal(game, (int)color);
		color++;
	}
}

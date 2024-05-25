/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transfer_info_file.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flaviobiondo <flaviobiondo@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 23:58:31 by rdolzi            #+#    #+#             */
/*   Updated: 2024/05/25 15:39:26 by flaviobiond      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cube.h"

// prende una stringa in input
// ritorna e alloca una nuova stringa senza
// eventuali spazi(inizio e fine)
char	*remove_spaces(char *str)
{
	int		i;
	char	*new_str;

	i = 0;
	new_str = NULL;
	while (ft_isspace(str[i]) != 0)
	{
		str++;
		i++;
	}
	i = 0;
	while (ft_isspace(str[i]) == 0)
		i++;
	new_str = (char *)ft_calloc(i + 1, 1);
	i = 0;
	while (ft_isspace(str[i]) == 0)
	{
		new_str[i] = str[i];
		i++;
	}
	return (new_str);
}

// la funzione setta solo la str delle informazioni
// RGB senza fare il parse delle informazioni stesse.
// il puntatore sta sulla prima lettera del cardinal.
void	insert_color(t_game *game, int type_c, char *str)
{
	str++;
	game->type[type_c].path = remove_spaces(str);
}

// esempio texture NORTH WALL
// NO ./path_to_the_north_texture
// la funzione setta solo il path dell .xpm senza fare
// il parse delle informazioni
// il puntatore sta sulla prima lettera del cardinal.
// primi 2 str++ saltano il riferimento al cardinal
void	insert_cardinal(t_game *game, int cardinal, char *str)
{
	str++;
	str++;
	game->walls[cardinal].path = remove_spaces(str);
}

void	insert_map(t_game *game, int idx)
{
	int	i;

	i = 0;
	game->map_transferred = 1;
	game->map = (char **)ft_calloc(game->n_lines_file - idx + 1,
			sizeof(char *));
	printf("game->n_lines_file - idx:%d\n", game->n_lines_file - idx + 1);
	if (game->map == NULL)
		clean_exit(game, throw_exception(SYSTEM_EXCEPTION, ERR_MALLOC, NULL));
	while (idx < game->n_lines_file)
	{
		game->map[i] = strdup(game->raw_file[idx]);
		i++;
		idx++;
	}
	game->map_len = i;
}

void	transfer_line(t_game *game, int idx)
{
	int		i;
	char	*str;

	i = 0;
	str = game->raw_file[idx];
	while (str[i] && ft_isspace(str[i]))
		i++;
	if (i == (int) ft_strlen(str))
		return ;
	if (!ft_strncmp("NO", &str[i], 2))
		insert_cardinal(game, NORTH, &str[i]);
	else if (!ft_strncmp("EA", &str[i], 2))
		insert_cardinal(game, EAST, &str[i]);
	else if (!ft_strncmp("SO", &str[i], 2))
		insert_cardinal(game, SOUTH, &str[i]);
	else if (!ft_strncmp("WE", &str[i], 2))
		insert_cardinal(game, WEST, &str[i]);
	else if (!ft_strncmp("F", &str[i], 1))
		insert_color(game, FLOOR, &str[i]);
	else if (!ft_strncmp("C", &str[i], 1))
		insert_color(game, CEALING, &str[i]);
	else if (ft_strchr("10", str[i]) || (ft_strchr("NSWE", str[i])
			&& str[i + 1] && ft_strchr("10 \n\t\v\r\f", str[i + 1])))
		insert_map(game, idx);
	else
		clean_exit(game, throw_exception(SYSTEM_EXCEPTION,
				ERR_ELEMENT_NOT_FOUND, NULL));
}

// initial_parse file cub
//      2.A.1)read line numbers
//      2.A.2) alloc **matr && read file
// 2.B)transfer information from file to structures
//      2.B.1)transfer cardinals
//      2.B.2)transfer color
//      2.B.3)transfer map
void	transfer_info_file(t_game *game)
{
	int	i;

	i = 0;
	game->path = game->argv[1];
	count_file_lines(game);
	read_file(game);
	while (i < game->n_lines_file && game->map_transferred != 1)
	{
		transfer_line(game, i);
		i++;
	}
}

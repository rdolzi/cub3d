/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transfer_info_file.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flaviobiondo <flaviobiondo@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 23:58:31 by rdolzi            #+#    #+#             */
/*   Updated: 2024/05/25 16:01:11 by flaviobiond      ###   ########.fr       */
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

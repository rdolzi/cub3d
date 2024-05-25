/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transfer_info_file2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flaviobiondo <flaviobiondo@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 16:01:14 by flaviobiond       #+#    #+#             */
/*   Updated: 2024/05/25 16:04:48 by flaviobiond      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cube.h"

void	transfer_line2(t_game *game, int idx, char *str, int i)
{
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
	transfer_line2(game, idx, str, i);
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

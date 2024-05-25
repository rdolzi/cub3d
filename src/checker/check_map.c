/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdolzi <rdolzi@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 16:56:47 by flaviobiond       #+#    #+#             */
/*   Updated: 2024/05/25 15:03:33 by rdolzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cube.h"

//controlla se i valori che non sono 1
// siano contornati da spazi
void	check_frame(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (y < game->map_len)
	{
		x = 0;
		while (x < (int) ft_strlen(game->map[y]))
		{
			if (ft_strchr("0NSWED", game->map[y][x]))
			{
				if (game->map[y - 1][x] == ' ' || game->map[y + 1][x] == ' '
					|| game->map[y + 1][x + 1] == ' ' || game->map[y - 1][x
					- 1] == ' ' || game->map[y + 1][x - 1] == ' '
					|| game->map[y - 1][x + 1] == ' ')
					clean_exit(game, throw_exception(MAP_EXCEPTION, ERR_MAP_WALLS, NULL));
                if (game->map[y - 1][x] == '\0' || game->map[y + 1][x] == '\0'
					|| game->map[y + 1][x + 1] == '\0' || game->map[y - 1][x
					- 1] == '\0' || game->map[y + 1][x - 1] == '\0'
					|| game->map[y - 1][x + 1] == '\0')
				clean_exit(game, throw_exception(MAP_EXCEPTION, ERR_MAP_WALLS, NULL));
				 if (game->map[y - 1][x] == '\n' || game->map[y + 1][x] == '\n'
					|| game->map[y + 1][x + 1] == '\n' || game->map[y - 1][x
					- 1] == '\n' || game->map[y + 1][x - 1] == '\n'
					|| game->map[y - 1][x + 1] == '\n')
					clean_exit(game, throw_exception(MAP_EXCEPTION, ERR_MAP_WALLS, NULL));
                
			}
            x++;
		}
        y++;
	}
}

int check_wall(t_game *game)
{
	int i;
	
	i = 0;
	while(i < game->map_len)
	{
		if(game->map[i][0] != 32 && game->map[i][0] != '1' && !(game->map[i][0] >= 9 && game->map[i][0] <= 13))
		return(-1);
		i++;
	}
	i = 0;
	while(i < (int)ft_strlen(game->map[0]))
	{
		if(game->map[0][i] != 32 && game->map[0][i] != '1' && !(game->map[0][i] >= 9 && game->map[0][i] <= 13))
		return(-1);
		i++;
	}
	return(0);
}

void check_double_p (t_game *game, int x,int y ,int *counter)
{
	if (ft_strchr("NSWE", game->map[y][x]))	
	 {
		game->player.dir = game->map[y][x];
		game->player.position.x = (double)x + 0.5;
		game->player.position.y = (double)y + 0.5;
		game->map[y][x] = '0';
		(*counter)++;
	}
	if(*counter > 1)
		clean_exit(game, throw_exception(MAP_EXCEPTION, ERR_PLAYER_DUPLICATE, NULL));
}


//E TRASFORMA gli spazi in K
//checka la presenza dei soli caratterri "1 0 N S W E 32 \n" nella mappa
void	parse_space(t_game *game)
{
	int	y;
	int	x;
	int c;

	c = 0;
	y = 0;
	if(check_wall(game))
		clean_exit(game, throw_exception(MAP_EXCEPTION, ERR_MAP_WALLS, NULL));
	while (y < game->map_len)
	{
		x = 0;
		while (x < (int) ft_strlen(game->map[y]))
		{
			if (ft_strchr("10NSWED", game->map[y][x]) )
				check_double_p(game, x, y, &c);
			else if(game->map[y][x] >= 9 && game->map[y][x] <= 13)
				game->map[y][x] = '1';
			else if(game->map[y][x] == ' ')
				game->map[y][x] = '1';
			else if(!ft_strchr("10NSWED \n", game->map[y][x]))
					clean_exit(game, throw_exception(MAP_EXCEPTION, ERR_INVALID_CHAR, NULL));
			x++;
		}
		y++;
	}
	if(c != 1)
		clean_exit(game, throw_exception(MAP_EXCEPTION, ERR_PLAYER_DUPLICATE, NULL));
}

int	count_tabs(char *str)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == '\t')
			count += 4;
		else
			count++;
		i++;
	}
	return (count);
}

char	*replace_tabs(char *str, int count)
{
	char	*result;
	int		j;
	int		i;

	result = (char *)malloc(count + 1);
	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] == '\t')
		{
			result[j++] = ' ';
			result[j++] = ' ';
			result[j++] = ' ';
			result[j++] = ' ';
		}
		else
			result[j++] = str[i];
		i++;
	}
	result[j] = '\0';
	free(str);
	return (result);
}

char	*replace_tab_with_spaces(char *str)
{
	int		count;

	count = count_tabs(str);
	str = replace_tabs(str, count);
	return (str);
}

void convert_tab_space(t_game *game)
{
	int y;

	y = 0;
	while(game->map[y])
	{
		game->map[y] = replace_tab_with_spaces(game->map[y]);
		y++;
	}
}

int parse_map(t_game *game)
{
	convert_tab_space(game);
	if(check_wall(game))
		clean_exit(game, throw_exception(MAP_EXCEPTION, ERR_MAP_WALLS, NULL));
	check_frame(game);
	parse_space(game);   
	return 0;
}

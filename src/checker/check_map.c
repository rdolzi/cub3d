/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdolzi <rdolzi@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 16:56:47 by flaviobiond       #+#    #+#             */
/*   Updated: 2024/04/18 19:08:09 by rdolzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cube.h"

//controlla se i valori che non sono 1 sono contornati da spazi
void	check_frame(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
            printf("game->map[y][x]: %c\n", game->map[y][x]);
			if (ft_strchr("0NSWED", game->map[y][x]))
			{
                printf("quando entra game->map[y][x]: %c\n", game->map[y][x]);
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
    printf("esce da check_frame\n");
}

int check_wall(t_game *game)
{
	int i;
	
	i = -1;
	while(game->map[++i])
	{
	if(game->map[i][0] != 32 && game->map[i][0] != '1' && !(game->map[i][0] >= 9 && game->map[i][0] <= 13))
		return(-1);
	}
	return(0);
}

void check_doble_p (t_game *game, int x,int y ,int *counter)
{

	if (ft_strchr("NSWE", game->map[y][x]) )	
	 {
		game->player.dir = game->map[y][x];
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
	y = -1;
	if(check_wall(game))
		clean_exit(game, throw_exception(MAP_EXCEPTION, ERR_MAP_WALLS, NULL));
	while (game->map[++y])
	{
		x = -1;
		while (game->map[y][++x])
		{
			if (ft_strchr("10NSWED", game->map[y][x]) )
			{
				check_doble_p(game, x, y, &c);
				continue ;
				// printf("\nmap%c\n", game->map_x[y][x]);
			}
			if(game->map[y][x] >= 9 && game->map[y][x] <= 13)
			{
				game->map[y][x] = 'K';
				// printf("\nmap/n%c\n", game->map_x[y][x]);
			}
			if(game->map[y][x] == ' ')
			{
				game->map[y][x] = 'K';
				// printf("\nma p%c\n", game->map_x[y][x]);
			}
			if(!ft_strchr("10NSWEDK \n", game->map[y][x]))
					clean_exit(game, throw_exception(MAP_EXCEPTION, ERR_INVALID_CHAR, NULL));
		}
		printf("\nmap%s\n", game->map[y]);
	}
}

void convert_tab_space(t_game *game)
{
	int x;
	int y;

	y = -1;
    printf("entra\n");
	while(game->map[++y])
	{
		x = -1;
		while(game->map[y][++x])
		{
			if(game->map[y][x] == 9)
			{
				game->map[y][x] = ' ';
				game->map[y][++x] = ' ';
				game->map[y][++x] = ' ';
				game->map[y][++x] = ' ';
			}
		}
	}

    printf("esce\n");
}

int parse_map(t_game *game)
{
    printf("entra su parse_map\n");   
	convert_tab_space(game);
	check_frame(game);
	parse_space(game);
    printf("esce su parse_map\n");   
	return 0;
}

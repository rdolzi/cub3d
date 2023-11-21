/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flaviobiondo <flaviobiondo@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 18:41:51 by flaviobiond       #+#    #+#             */
/*   Updated: 2023/10/22 22:00:52 by flaviobiond      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

//controlla se i valori che non sono 1 sono contornati da spazi
void	check_fraime(t_data *game)
{
	int	y;
	int	x;

	y = -1;
	while (game->map_x[++y])
	{
		x = -1;
		while (game->map_x[y][++x])
		{
			if (ft_strchr("0NSWED", game->map_x[y][x]))
			{
				if (game->map_x[y - 1][x] == ' ' || game->map_x[y + 1][x] == ' '
					|| game->map_x[y + 1][x + 1] == ' ' || game->map_x[y - 1][x
					- 1] == ' ' || game->map_x[y + 1][x - 1] == ' '
					|| game->map_x[y - 1][x + 1] == ' ')
					exit(write(2, "Error: 0NSWED\n", 15));
			}
		}
	}
}

int check_wall(t_data *game)
{
	int i;
	
	i = -1;
	while(game->map_x[++i])
	{
	if(game->map_x[i][0] != 32 && game->map_x[i][0] != '1' && !(game->map_x[i][0] >= 9 && game->map_x[i][0] <= 13))
		return(-1);
	}
	return(0);
}

void check_doble_p (t_data *game, int x,int y ,int *counter)
{
	
	if(game->map_x[y][x] == 'N')	
	{
	(*counter)++;
	}
		if(game->map_x[y][x] == 'W')	
	{
		(*counter)++;
	}
		if(game->map_x[y][x] == 'E')	
	{
		(*counter)++;
	}
		if(game->map_x[y][x] == 'S')	
	{
		(*counter)++;
	}
	if(*counter > 1)
		exit(write(2, "Error:troppi personag\n", 22));
}

//E TRASFORMA gli spazi in K
//checka la presenza dei soli caratterri "1 0 N S W E 32 \n" nella mappa
void	check(t_data *game)
{
	int	y;
	int	x;
	int c;

	c = 0;
	y = -1;
	if(check_wall(game))
		exit(write(2, "Error:invalid caratter\n", 22));
	while (game->map_x[++y])
	{
		x = -1;
		while (game->map_x[y][++x])
		{
			if (ft_strchr("10NSWED", game->map_x[y][x]) )
			{
				check_doble_p(game, x, y, &c);
				continue ;
				// printf("\nmap%c\n", game->map_x[y][x]);
			}
			if(game->map_x[y][x] >= 9 && game->map_x[y][x] <= 13)
			{
				game->map_x[y][x] = 'K';
				// printf("\nmap/n%c\n", game->map_x[y][x]);
			}
			if(game->map_x[y][x] == ' ')
			{
				game->map_x[y][x] = 'K';
				// printf("\nma p%c\n", game->map_x[y][x]);
			}
			if(!ft_strchr("10NSWEDK \n", game->map_x[y][x]))
					exit(write(2, "Error:invalid caratter\n", 22));
		}
		printf("\nmap%s\n", game->map_x[y]);
	}
}

void convert_tab_space(t_data *game)
{
	int x;
	int y;

	y = -1;
	while(game->map_x[++y])
	{
		x = -1;
		while(game->map_x[y][++x])
		{
			if(game->map_x[y][x] == 9)
			{
				game->map_x[y][x] = ' ';
				game->map_x[y][++x] = ' ';
				game->map_x[y][++x] = ' ';
				game->map_x[y][++x] = ' ';
			}
		}
	}
}

int check_map(t_data *game)
{
	convert_tab_space(game);
	check_fraime(game);
	check(game);
	return 0;
}

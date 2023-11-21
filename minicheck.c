/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minicheck.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flaviobiondo <flaviobiondo@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 17:09:04 by flaviobiond       #+#    #+#             */
/*   Updated: 2023/10/19 17:51:01 by flaviobiond      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_check(t_data *game)
{
	if (game->map_x == NULL)
		exit(write(2, "Error: Invalid checkmap\n", 25));
	if (game->value.ea == NULL)
		exit(write(2, "Error: Invalid check_ea\n", 25));
	if (game->value.no == NULL)
		exit(write(2, "Error: Invalid check_no\n", 25));
	if (game->value.we == NULL)
		exit(write(2, "Error: Invalid check_we\n", 25));
	if (game->value.so == NULL)
		exit(write(2, "Error: Invalid check_so\n", 25));
}

// conta le ,
int	check_virg(char *substr)
{
	int	i;
	int	virg;

	virg = 0;
	i = -1;
	while (substr[++i])
	{
		if (substr[i] == 44)
			virg++;
	}
	return (virg);
}

void	ft_print_mat(char **mat)
{
	int	y;
	int	x;

	y = 0;
	while (mat[y])
	{
		x = 0;
		while (mat[y][x])
		{
			write(1, &mat[y][x], 1);
			x++;
		}
		y++;
		write(1, "\n", 1);
	}
}

void initfc(t_data *game)
{
    game->value.c.b = -1;
    game->value.c.r = -1;
    game->value.c.g = -1;
    game->value.f.b = -1;
    game->value.f.r = -1;
    game->value.f.g = -1;
    
}

void	ft_check_input(t_data *game, int ac, char *av)
{
	int	len;

	if (ac != 2)
		exit(write(2, "Error: Invalid input\n", 21));
	len = ft_strlen(av);
	if (!(av[len - 1] == 'b' && av[len - 2] == 'u' && av[len - 3]
			== 'c' && av[len - 4] == '.'))
		exit(write(2, "Error: Map isnt in .cub format\n", 24));
	initfc(game);
}

//5
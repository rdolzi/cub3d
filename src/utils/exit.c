/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdolzi <rdolzi@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 23:43:38 by rdolzi            #+#    #+#             */
/*   Updated: 2024/05/25 15:04:28 by rdolzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cube.h"

void	free_matrix(void **matrix)
{
	int	i;

	i = 0;
	while (matrix[i])
    {
        free(matrix[i]);
        i++;
    }	
    if(matrix)
    {
	    free(matrix);
        matrix = NULL;
    }
    return ;
}


// compone un messaggio di errore
// a partire dalle stringe input e stampa su fd 2.
// msg non puoi essere NULL, specific e sub_specific sono opzionali.
int throw_exception(char *msg, char *specific, char *sub_specific)
{
    ft_printstr_fd("Error\n", 2);
    ft_printstr_fd(msg, 2);
    if (specific != NULL)
        ft_printstr_fd(specific, 2);
    if (sub_specific != NULL)
        ft_printstr_fd(sub_specific, 2);
    ft_printstr_fd("\n", 2);
    return (EXIT_FAILURE);
}

void free_color_and_walls(t_game *game)
{
   if(game->type[0].path)
        free(game->type[0].path);
     if(game->type[1].path)
        free(game->type[1].path);
    if(game->walls[0].path)
        free(game->walls[0].path);
    if(game->walls[1].path)
        free(game->walls[1].path);
    if(game->walls[2].path)
        free(game->walls[2].path);
    if(game->walls[3].path)
        free(game->walls[3].path);
    
}

void clean_exit(t_game *game, int exit_status)
{
    if(game->map)
    free_matrix((void **)game->map);
    if(game->raw_file)
    free_matrix((void **)game->raw_file);
    if(game->pixels)
    free_matrix((void **)game->pixels);
    if(game->textures)
    free_matrix((void **)game->textures);
    free_color_and_walls(game);
    if (game->mlx && game->mlx_win)
    {
        mlx_destroy_window(game->mlx, game->mlx_win);
        free(game->mlx);
    }
    exit(exit_status);
}

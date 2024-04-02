/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdolzi <rdolzi@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 23:47:57 by rdolzi            #+#    #+#             */
/*   Updated: 2024/04/02 14:46:09 by rdolzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cube.h"

void check_input(t_game *game, char *format)
{
    int i;
    char *file;
    
    i = 0;
    file = game->argv[1];
    if (game->argc != 2)
        clean_exit(game, throw_exception(ERR_ARGC, NULL, NULL));
    if (format == CUB) // STRNCMP?
    {
        i = ft_strlen(file);
        if (!(file[i - 1] == 'b' && file[i - 2] == 'u' && file[i - 3] == 'c' && file[i - 4] == '.'))
            clean_exit(game, throw_exception(FILE_EXCEPTION, ERR_FILE_FORMAT, CUB));
    }
    else if (format == XPM)
    {
        i = ft_strlen(file);
        if (!(file[i - 1] == 'm' && file[i - 2] == 'p' && file[i - 3] == 'x' && file[i - 4] == '.'))
            clean_exit(game, throw_exception(FILE_EXCEPTION, ERR_FILE_FORMAT, XPM));
    }
}
// calloc?
void read_file(t_game *game)
{
    int fd;
    int i;
    char *str;

    i = 0;
    game->raw_file = (char **)malloc(sizeof(char *) * (game->n_lines_file));
    if (game->raw_file == NULL)
        clean_exit(game, throw_exception(SYSTEM_EXCEPTION, ERR_MALLOC, NULL));
    fd = open(game->path, O_RDONLY);
    if (fd == -1)
        clean_exit(game, throw_exception(SYSTEM_EXCEPTION, ERR_OPEN_FILE, NULL));
    str = get_next_line(fd);
    while (str)
    {
        game->raw_file[i] = str;
        str = get_next_line(fd);
        i++;
    }
    close(fd);
}

void count_file_lines(t_game *game)
{
    int fd;
    char *str;

    fd = open(game->path, O_RDONLY);
    str = get_next_line(fd);
    if (!str)
        return;
    game->n_lines_file++;
    while (str)
    {
        free(str);
        str = get_next_line(fd);
        if (!str)
            break;
        game->n_lines_file++;
    }
    close(fd);
    free(str);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdolzi <rdolzi@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 23:47:57 by rdolzi            #+#    #+#             */
/*   Updated: 2024/04/26 04:06:15 by rdolzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cube.h"

// CHECK ARGC && .CUB EXTENSION
void check_input(t_game *game, char *format, char *path)
{
    int i;
    
    i = (int)ft_strlen(path);
    if (!strcmp(format,CUB)) // STRNCMP?
    {
        if (!(path[i - 1] == 'b' && path[i - 2] == 'u' && path[i - 3] == 'c' && path[i - 4] == '.'))
            clean_exit(game, throw_exception(FILE_EXCEPTION, ERR_FILE_FORMAT, CUB));
    }
    else if (!strcmp(format,XPM))
    {
        if (!(path[i - 1] == 'm' && path[i - 2] == 'p' && path[i - 3] == 'x' && path[i - 4] == '.'))
            clean_exit(game, throw_exception(FILE_EXCEPTION, ERR_FILE_FORMAT, XPM));
    }
}

void read_file(t_game *game)
{
    int fd;
    int i;
    char *str;

    i = 0;
    game->raw_file = (char **)ft_calloc(sizeof(char *) , (game->n_lines_file + 1));
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

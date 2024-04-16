/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdolzi <rdolzi@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 23:47:57 by rdolzi            #+#    #+#             */
/*   Updated: 2024/04/16 02:00:57 by rdolzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cube.h"

void check_input(t_game *game, char *format, char *path)
{
    int i;
    
    i = (int)ft_strlen(path);
    printf("path:%s\n", path);
    if (!strcmp(format,CUB)) // STRNCMP?
    {
        printf("ENTRA IN CUB\n");
        if (!(path[i - 1] == 'b' && path[i - 2] == 'u' && path[i - 3] == 'c' && path[i - 4] == '.'))
            clean_exit(game, throw_exception(FILE_EXCEPTION, ERR_FILE_FORMAT, CUB));
    }
    else if (!strcmp(format,XPM))
    { // game->walls[1].path[i - 1]
        printf("ENTRA IN XPM\n");
        // printf("path[i - 1]:%c\n", path[i - 1]);
        // printf("path[i - 2]:%c\n", path[i - 2]);
        // printf("path[i - 3]:%c\n", path[i - 3]);
        // printf("path[i - 4]:%c\n", path[i - 4]);
        if (!(path[i - 1] == 'm' && path[i - 2] == 'p' && path[i - 3] == 'x' && path[i - 4] == '.'))
            clean_exit(game, throw_exception(FILE_EXCEPTION, ERR_FILE_FORMAT, XPM));
        printf("ESCE IN XPM\n");
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

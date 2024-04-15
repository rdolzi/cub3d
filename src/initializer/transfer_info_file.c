/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transfer_info_file.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdolzi <rdolzi@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 23:58:31 by rdolzi            #+#    #+#             */
/*   Updated: 2024/04/15 23:28:08 by rdolzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cube.h"

// void init_info_file(t_game *game, char *file)
// {
//     // set file path
//     game->path = file;
//     // count and set file lines
//     count_file_lines(game); // count_lines?
//     // read and set file
//     read_file(game);
// }

// F 220,100,0 (possono essere presenti spazi vicino le virgole)
// la funzione setta solo la str delle informazioni RGB senza fare il parse delle informazioni stesse.
// il puntatore sta sulla prima lettera del cardinal.
void insert_color(t_game *game, int type_c, char *str)
{
    int i;

    i = 0;
    str++;
    while (ft_isspace(str[i]))
        i++;
    game->type[type_c].path = ft_strdup(str);
}

// typedef struct s_img
// {
//     char *path;
//     void *img;
//     void *addr;
//     int bpp;
//     int line_length;
//     int endian;
// } t_img;
// esempio texture NORTH WALL
// NO ./path_to_the_north_texture
// la funzione setta solo il path dell .xpm senza fare il parse delle informazioni
// il puntatore sta sulla prima lettera del cardinal.
void insert_cardinal(t_game *game, int cardinal, char *str)
{
    int i;

    i = 0;
    str++;
    str++;
    while (ft_isspace(str[i]))
        i++;
    game->walls[cardinal].path = ft_strdup(str);
}

void insert_map(t_game *game, int idx)
{
    int i;
    // char *str;

    i = 0;
    game->map_transferred = 1;
    game->map = (char **)malloc(sizeof(char *) * (game->n_lines_file - idx));
    if (game->map == NULL)
        clean_exit(game, throw_exception(SYSTEM_EXCEPTION, ERR_MALLOC, NULL));
    while (idx < game->n_lines_file)
    {
        printf("inserting %d line: %s", i, game->raw_file[idx]);
        game->map[i] = ft_strdup(game->raw_file[idx]);
        i++;
        idx++;
    }
    printf("\n");
}

void transfer_line(t_game *game, int idx)
{
    int i;
    char *str;

    i = 0;
    str = game->raw_file[idx];
    printf("game->raw_file[idx:%d]:%s\n", idx, game->raw_file[idx]);
    while (str[i] && ft_isspace(str[i]))
        i++;
    printf("str[i:%d]:%s\n", i, &str[i]);
    printf("strlen:%d\n", (int)ft_strlen(str));
    if (i == (int) ft_strlen(str)) // or len -1 ?
        return ;
    if (!ft_strncmp("NO", &str[i], 2))
    {
        printf("entra (!ft_strncmp(NO, &str[i], 2))\n");
        insert_cardinal(game, NORTH, &str[i]);
    }
    else if (!ft_strncmp("EA", &str[i], 2))
        insert_cardinal(game, EAST, &str[i]);
    else if (!ft_strncmp("SO", &str[i], 2))
        insert_cardinal(game, SOUTH, &str[i]);
    else if (!ft_strncmp("WE", &str[i], 2))
        insert_cardinal(game, WEST, &str[i]);
    else if (!ft_strncmp("F", &str[i], 1))
    {
        printf("entra (!ft_strncmp(F, &str[i], 2))\n");
        insert_color(game, FLOOR, &str[i]);
    }
    else if (!ft_strncmp("C", &str[i], 1))
        insert_color(game, CEALING, &str[i]);
    else if (ft_strchr("10", str[i]) || (ft_strchr("NSWE", str[i]) 
        && str[i + 1] && ft_strchr("10 \n\t\v\r\f", str[i + 1])))
        {
            printf("entra in insert_map, riga: %d\n",i);
            insert_map(game, idx);
        }
    else
        clean_exit(game, throw_exception(SYSTEM_EXCEPTION, ERR_ELEMENT_NOT_FOUND, NULL));
}

// transfer informations from raw_file to game's structure
// without validation
// void transfer_info(t_game *game)
// {
//     int i;

//     i = 0;
//     while (i < game->n_lines_file)
//     {
//         transfer_line(game, i);
//         i++;
//     }
// }

void transfer_info_file(t_game *game)
{
    int i;

    i = 0;
    // set file path
    game->path = game->argv[1];
    // count and set file lines
    count_file_lines(game); // count_lines?
    // read and set file
    read_file(game);
    // transfer_info(game);
    while (i < game->n_lines_file && game->map_transferred != 1)
    {
        printf("transfer %d line \n", i);
        transfer_line(game, i);
        i++;
    }
}

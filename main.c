/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdolzi <rdolzi@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 19:50:28 by rdolzi            #+#    #+#             */
/*   Updated: 2024/03/06 11:43:01 by rdolzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cube.h"

// ------------ START UTILS ------------

// exception();
// clean_exit();
   
// lancia eccezione, componendola e printandola.
int throw_exception(char *msg, char *specific, char *sub_specific)
{
    char *str_builder;

    ft_printstr_fd("Error\n", 2);
    ft_printstr_fd(msg, 2);
    if (specific)
        ft_printstr_fd(specific, 2);
    if (sub_specific)
        ft_printstr_fd(sub_specific, 2);
    ft_printstr_fd("\n", 2);
    return (EXIT_FAILURE);
}

// exit status SUCCESS -> msg == NULL
// exit status ERROR -> msg != NULL
void clean_exit(t_game *game, int exit_status)
{
    // mlx + win + loop_end
    //free_data(matrix)
        //free_texture
         //free_texture_pixels
          //free_texture_info
          //free_map
    exit(exit_status);
}

void init_game(t_game *game)
{
    // init default values
    game->mlx = NULL;
    game->win = NULL;
    game->win_height = WIN_HEIGHT;
    game->win_width = WIN_WIDTH;
    game->map = NULL;
    game->path = NULL;
    game->raw_file = NULL;
    game->n_lines_file = 0;
    game->texture_pixels = NULL; //?
    game->textures = NULL;       //?
    // init_walls(game);
    game->walls->path = NULL;
    game->walls->img = NULL;
    game->walls->addr = NULL;
    game->walls->line_length = 0;
    game->walls->endian = 0;

    // init_ray(game);
    // init_player(game);
    // init_cardinals(game);
}

void check_file(t_game *game, char *file, char *format)
{
    int i;
    
    if (format == CUB)
    {
        i = ft_strlen(file);
        if (!(file[i - 1] == 'b' && file[i - 2] == 'u' && file[i - 3] == 'c' && file[i - 4] == '.'))
            clean_exit(game, throw_exception(FILE_EXCEPTION, ERR_FILE_FORMAT, CUB));
    }
    else if (format == XPM)
    {
        
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
    game
}

void transfer_line(t_game *game, int idx)
{
    int     i;
    char    *str;
    
    i = 0;
    str = game->raw_file[idx];
    while (ft_isspace(str[i]))
        i++;
    if (!ft_strncmp("NO", &str[i], 2))
        insert_cardinal(game, NORTH, &str[i]);
    else if (!ft_strncmp("EA", &str[i], 2))
        insert_cardinal(game, EAST, &str[i]);
    else if (!ft_strncmp("SO", &str[i], 2))
        insert_cardinal(game, SOUTH, &str[i]);
    else if (!ft_strncmp("WE", &str[i], 2))
        insert_cardinal(game, WEST, &str[i]);
    else if (!ft_strncmp("F", &str[i], 2))
        insert_color(game, FLOOR, &str[i]);
    else if (!ft_strncmp("C", &str[i], 2))
        insert_color(game, CEALING, &str[i]);
    else if (ft_strchr("10", str[i]) || (ft_strchr("NSWE", str[i]) && str[i + 1] != NULL && ft_strchr("10 \n\t\v\r\f", str[i + 1])))
        insert_map(game, i);
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

void parse_file(t_game *game, char *file)
{
    int i;

    i = 0;
    // set file path
    game->path = file;
    // count and set file lines
    count_file_lines(game); // count_lines?
    // read and set file
    read_file(game);
    // transfer_info(game);
    while (i < game->n_lines_file)
    {
        transfer_line(game, i);
        i++;
    }
}

int check_and_parse(t_game *game, char *file)
{
    // 1)check .cub extension && is not a dir
    check_file(game, file, CUB);
    // 2)initial_parse file cub
    parse_file(game, file);
    // init_info_file(game, file); ->done
    //      2.1)read line numbers
    //      2.2) alloc **matr && read file      ->done
    // 3)transfer information from file to structures ->wip
    //      3.1)transfer cardinals
    //      3.2)transfer color
    //      3.3)transfer map
    // 4)parse information file from structures ->todo
    //      4.1)parse cardinals
    //      4.2)parse_colors()
    //          set colors
    //          check color validity
    //      4.3)parse map
    //          4.3.A)set 1 on space/tab
    //          4.3.B)check map validity
    //          4.3.C)check map is last
    //          4.3.D)check map_elements()
    //          4.3.E)check walls
    //          4.3.F)check elements
    //          4.3.G)check player
    //          4.3.H)init player
    //      4.4)parse texture
    //          4.4.A)check file
    //          4.4.B)check rgb
    //          4.4.C)convert rgb
    //          4.4.D)check texture validity
}

// ------------ END   UTILS ------------
void build_game(t_game *game, char *file)
{
    init_game(game);
    // parser
    if (check_and_parse(game, file))
        // error
        init_mlx(game);
    // init mlx && win
    init_textures(game);
    key_bind(game);
}

void key_bind(t_game *game)
{
    mlx_hook(game->mlx_win, 17, 0, close_window, game);
    mlx_hook(game->mlx_win, 2, 1L << 0, key_hook_press, (void *)game);
    mlx_hook(game->mlx_win, 3, 1L << 1, key_hook_release, (void *)game);
   // mouse rotation è bonus
}

void raycasting()
{
    // while win height
        // init ray info
        // set dda (per dir_x & dir_y< 0)
        // perform dda
            // implement the DDA algorithm:
                //(the loop will increment 1 square until we hit a wall)
}

void render_frame(t_game *game)
{
    // create image
    // init image (nuova, nessun img precedente è usata)
    // while win_height
        // while win_height
            // set_frame (cealing or floor or image)
    // put image
    // destroy image
}

void render(t_game *game)
{
    // fa il free + calloc di texture_pixels
    reset_texture_pixels(game);
    // resetta valori di default del ray
    reset_ray(&game->ray);
    raycasting(&game->player, game);
    render_frame(game);
}

int main(int argc, char **argv)
{
    t_game game;
    
    // check argc
        // args != 2 -> exit
    if (argc != 2)
    {
        write(2, "Error\nargc != 2", 1);
        return (1);
    }
    build_game(&game, argv[1]);
    start_game(&game);
        //
        //display_menu();
    run_game(&game);
        mlx_loop_hook(game.mlx, render, &game);
        mlx_loop(game.mlx);

}

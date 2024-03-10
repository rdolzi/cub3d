/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdolzi <rdolzi@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 19:52:12 by rdolzi            #+#    #+#             */
/*   Updated: 2024/03/10 22:43:39 by rdolzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_H
# define CUBE_H

#include <stdio.h>
#include <fcntl.h>
#include <stdbool.h>

#include "./error.h"
#include "./get_next_line.h"
#define WIN_HEIGHT 480
#define WIN_WIDTH 640

#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1

#if defined(__APPLE__)
#define ESC 53
#define W 13
#define A 0
#define S 1
#define D 2
#define UP 126
#define DOWN 125
#define LEFT 123
#define RIGHT 124
#elif defined(__linux__) || defined(__gnu_linux__)
#define ESC 65307
#define W 119
#define A 97
#define S 115
#define D 100
#define UP 65362
#define DOWN 65364
#define LEFT 65361
#define RIGHT 65363
#endif

enum e_cardinal
{
    NORTH = 0,
    EAST = 1,
    SOUTH = 2,
    WEST = 3
};

enum e_color
{
    FLOOR = 0,
    CEALING = 1
};

typedef struct s_img
{
    char *path;
    void *img;
    void *addr;
    int bpp;
    int line_length;
    int endian;
} t_img;

// typedef struct s_img
// {
//     char *texture_path;
//     void *img;
//     void *addr;
//     int bpp;
//     int line_length;
//     int endian;
//     int width;
//     int height;
// } t_img;

typedef struct s_ray
{
    int placeholder;
} t_ray;

// t_img textures contains info after mlx_new_img + mlx_xpm_to_img
// typedef struct s_cardinal
// {
//     t_img textures[4];
//     char *north_texture_path;
//     char *south_texture_path;
//     char *east_texture_path;
//     char *west_texture_path;
// } t_cardinal;



typedef struct s_player
{
    double  pos_x;
    double  pos_y;
    double  dir_x;
    double  dir_y;
    // key press
    int     move_x;
    int     move_y;
    int     rotate;
} t_player;


typedef struct s_color
{
    char *path;
    unsigned int hex;
    
} t_color;

typedef struct s_game
{
    int     argc;
    char    **argv;
    void    *mlx;
    void    *mlx_win;
    int     win_height;
    int     win_width;
    char    **map;
    long    old_time;
    int     fps;
    // ---
    char     **raw_file;
    int     n_lines_file;
    int     map_transferred;
    char    *path;
    // ---
    int     **texture_pixels;
    int     **textures;
    t_ray ray;
    t_player player;
    // NSWE
    t_img   walls[4];
    // FLOOR - CEALING
    t_color type[2];
} t_game;


//UTILS
void    ft_printstr_fd(char *str, int fd);
int     ft_isalpha(int c);
int     ft_isdigit(int c);
int     ft_isspace(int c);
int     ft_strncmp(const char *s1, const char *s2, size_t n);
char    *ft_strchr(char *s, char ch);
char	*ft_strdup(char *s1);


//INITIALIZER
//--init_structures.c
void init_game(t_game *game);
//--transfer_info_file.c
void transfer_info_file(t_game *game);

//RAYCASTER
//--render.c
void render(t_game *game);

//UTILS
//--exit.c
void clean_exit(t_game *game, int exit_status);
int throw_exception(char *msg, char *specific, char *sub_specific);

//CHECKER
//--file.c
void count_file_lines(t_game *game);
void read_file(t_game *game);
void check_input(t_game *game, char *format);

//BUILDER
//--build_game.c
void build_game(t_game *game);

//ENGINE
//--key_bind.c
void key_bind(t_game *game);
#endif

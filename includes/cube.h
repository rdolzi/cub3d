/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdolzi <rdolzi@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 19:52:12 by rdolzi            #+#    #+#             */
/*   Updated: 2024/03/06 11:34:54 by rdolzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_H
# define CUBE_H

#include <stdio.h>
#include <fcntl.h>
#include <stdbool.h>

#include "./error.h"
#include "../get_next_line/get_next_line.h"
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
    int placeholder;
} t_player;


typedef struct s_color
{
    char *path;
    unsigned int hex;
    
} t_color;

typedef struct s_game
{
    void    *mlx;
    void    *win;
    int     win_height;
    int     win_width;
    char    **map;
    // ---
    char     **raw_file;
    int     n_lines_file;
    char    *path;
    // ---
    int     **texture_pixels;
    int     **textures;
    t_ray ray;
    t_player player;
    t_img   walls[4];
    t_color type[2];
    // t_cardinal cardinal;
} t_game;


//UTILS
void    ft_printstr_fd(char *str, int fd);
int     ft_isalpha(int c);
int     ft_isdigit(int c);
int     ft_isspace(int c);
int     ft_strncmp(const char *s1, const char *s2, size_t n);
char    *ft_strchr(char *s, char ch);
char	*ft_strdup(char *s1);

#endif

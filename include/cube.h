/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flaviobiondo <flaviobiondo@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 19:52:12 by rdolzi            #+#    #+#             */
/*   Updated: 2024/05/25 16:13:17 by flaviobiond      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef CUBE_H
# define CUBE_H

# include <math.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdbool.h>
# include <string.h>
# include "./error.h"
# include "./get_next_line.h"
# define WIN_HEIGHT 960
# define WIN_WIDTH 1280
# define TEXTURE_SIZE 64

# define EXIT_SUCCESS 0
# define EXIT_FAILURE 1
# define DEBUG 1

# if defined(__APPLE__)
#  include "../mlx_mac/mlx.h"
#  define ESC 53
#  define W 13
#  define A 0
#  define S 1
#  define D 2
#  define UP 126
#  define DOWN 125
#  define LEFT 123
#  define RIGHT 124
# elif defined(__linux__) || defined(__gnu_linux__)
#  include "../mlx_linux/mlx.h"
#  define ESC 65307
#  define W 119
#  define A 97
#  define S 115
#  define D 100
#  define UP 65362
#  define DOWN 65364
#  define LEFT 65361
#  define RIGHT 65363
# endif

enum e_cardinal
{
	NORTH = 0,
	SOUTH = 1,
	EAST = 2,
	WEST = 3
};

enum e_color
{
	FLOOR = 0,
	CEALING = 1
};

typedef struct s_coordinate
{
	double	x;
	double	y;
}	t_coordinate;

typedef struct s_img
{
	char	*path;
	void	*img;
	int		*addr;
	int		bpp;
	int		line_length;
	int		endian;
	int		width;
	int		height;
}	t_img;

typedef struct s_ray
{
	t_coordinate	direction;
	t_coordinate	player_pos;
	t_coordinate	step;
	t_coordinate	side_distance;
	t_coordinate	delta_distance;
	int				cardinal;
	double			ndc;
	int				side;
	double			wall_dist;
	int				wall_x;
	int				line_height;
	int				draw_start;
	int				draw_end;
	double			s;
	double			pos;
}	t_ray;

typedef struct s_player
{
	char			dir;
	double			rotate;
	t_coordinate	position;
	t_coordinate	direction;
	t_coordinate	cam_plane;
	t_coordinate	move;

}	t_player;

typedef struct s_color
{
	char			*path;
	unsigned long	hex;
}	t_color;

typedef struct s_game
{
	int			argc;
	char		**argv;
	void		*mlx;
	void		*mlx_win;
	int			win_height;
	int			win_width;
	char		**map;
	int			map_len;
	long		old_time;
	int			fps;
	char		**raw_file;
	int			n_lines_file;
	int			map_transferred;
	char		*path;
	double		pix_step;
	double		pix_pos;
	int			**pixels;
	int			**textures;
	t_ray		ray;
	t_player	player;
	t_img		walls[4];
	t_color		type[2];
}	t_game;

//UTILS
void	ft_printstr_fd(char *str, int fd);
int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isspace(int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strchr(char *s, char ch);
char	*ft_strdup(char *s1);

//INITIALIZER
//--init_structures.c
void	init_game(t_game *game);
void	init_image(t_img *image);
void	init_ray(t_game *game);
//--transfer_info_file.c
void	transfer_info_file(t_game *game);

//RAYCASTER
//--render.c
int		render(t_game *game);
void	render_screen(t_game *game);
//--print_frame.c
void	print_screen(t_game *game);
//--raycasting_algorithm.c
void	raycasting(t_game *game);
//--dda_algorithm.c
void	set_step_and_side_distance(t_game *game);
void	perform_digital_differential_analysis(t_game *game);

//UTILS
//--exit.c
void	free_matrix(void **matrix);
void	clean_exit(t_game *game, int exit_status);
int		throw_exception(char *msg, char *specific, char *sub_specific);
//--ft_calloc.c
void	*ft_calloc(int count, int size);
int		ft_atoi(const char *str);
char	**ft_split(char *s, char c);

//CHECKER
//--file.c
void	count_file_lines(t_game *game);
void	read_file(t_game *game);
void	check_input(t_game *game, char *format, char *path);
int		parse_map(t_game *game);

//BUILDER
//--build_game.c
void	set_mlx(t_game *game);
void	parse_game(t_game *game);
void	display_menu(void);
//--parse_cardinal.c
void	parse_cardinal(t_game *game);
//--parse_color.c
void	parse_color(t_game *game);
//--parse_player.c
void	parse_player(t_game *game);

//ENGINE
//--key_bind.c
void	key_bind(t_game *game);
int		has_moved(t_game *game);
int		mouse_control(int x, int y, t_game *game);
#endif

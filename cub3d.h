/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdolzi <rdolzi@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 14:00:25 by flaviobiond       #+#    #+#             */
/*   Updated: 2023/11/21 17:55:22 by rdolzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "mlx/mlx.h"
# include "mlx_linux/mlx.h"
# include <stdint.h>
# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"
# include "getnextline/get_next_line.h"
# include <fcntl.h>
# include <math.h>
# include <sys/time.h>
# include <time.h>

#	define INVISI_CHAR "\t\v\r\f "

// img_ptr: Puntatore alla struttura di dati che rappresenta l'immagine.
// bits_per_pixel: Numero di bit utilizzati per rappresentare ogni pixel nell'immagine.
// size_line: Dimensione di una singola riga dell'immagine in byte.
// endian: Indica se l'architettura del sistema è little-endian o big-endian.
typedef struct s_img {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_img;

typedef struct s_vector
{
	double	x;
	double	y;
}	t_vector;


typedef struct				s_rgb
{
	int						r;
	int						g;
	int						b;
}							t_rgb;

typedef struct s_value
{
	char			*no;
	char			*we;
	char			*so;
	char			*ea;
    struct				s_rgb f;
    struct				s_rgb c;
    
}					t_value;

typedef struct s_minimap
{
	t_img		img;
	int			x;
	int			y;
	int			width;
	int			height;
	t_vector	begin_ray;
	t_vector	end_ray;
}	t_minimap;


typedef struct s_data
{
	int 			len_map;
	size_t			x;
	int				y;
    char **map_x;
	struct s_value	value;
	char	**map;
}					t_data;

typedef struct s_cub3d
{
	void			*mlx;
	void			*mlx_win;
	t_minimap		minimap;
	struct s_data	env;
}					t_cub3d;

void ft_print_mat(char **mat);
//parser
void parser_cub(t_data *game, char *map_cub);
int check_map(t_data *game);



//check_parser
void ft_check_input(t_data *game, int ac, char *av);
int	check_virg(char *substr);
void	ft_check(t_data *game);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flaviobiondo <flaviobiondo@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 15:54:20 by flaviobiond       #+#    #+#             */
/*   Updated: 2024/05/25 16:00:26 by flaviobiond      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

# define _FLOOR "Floor"
# define _CEILING "Ceiling"
# define _DOOR "Door"

# define ERR_ARGC "argc != 2"
// -FILE EXCEPTION
# define FILE_EXCEPTION "File Exception: "
// --SPECIFICS
# define ERR_FILE_FORMAT "File Format Error: "
# define CUB "Insert .cub file"
# define XPM "Insert .xpm file"
# define ERR_ELEMENT_NOT_FOUND "Element not valid."

// -MAP EXCEPTION
# define MAP_EXCEPTION "Map Exception: "
// --SPECIFICS
# define ERR_MAP_NOT_FOUND "Map not found. Insert the map into the file"
# define ERR_MAP_WALLS "Map is not surrounded by walls"
# define ERR_MAP_CARDINAL "Wall image not found. Insert all xpm paths required."
# define ERR_MAP_COLOR "Color not found. Insert all colors rgb required."
# define ERR_MAP_POSITION "Map is not the last element in file"
# define ERR_PLAYER_NOT_FOUND "Player not found. Insert N, S, E or W map"
# define ERR_PLAYER_DUPLICATE "Too much players found.Insert one N, S, E or W"
# define ERR_INVALID_CHAR "Invalid character in map."
// messaggio unico per err_format(per eventuali spazi?) and err_range
# define ERR_INVALID_RGB "Invalid RGB. Insert R,G,B colors in range [0,255]"

// -SYSTEM EXCEPTION
# define SYSTEM_EXCEPTION "System Exception: "
// --SPECIFICS
# define ERR_MALLOC "Malloc Error"
# define ERR_OPEN_FILE "Open File Error"
// messaggio unico per mlx e mlx_win
# define ERR_MLX "Error during MLX library initialization"

// extra
# define RGB_DEFINITION "DEFINITION: RGB (red, green and blue)"
// ---
#endif
#ifndef ERROR_H
#define ERROR_H

#define _FLOOR "Floor"
#define _CEILING "Ceiling"
#define _DOOR "Door"

#define ERR_ARGC "argc != 2"
// -FILE EXCEPTION
#define FILE_EXCEPTION "File Exception: "
// --SPECIFICS
#define ERR_FILE_FORMAT "File Format Error: "
#define CUB "Insert .cub file"
#define XPM "Insert .xpm file"
#define ERR_ELEMENT_NOT_FOUND "Element not valid."

// -MAP EXCEPTION
#define MAP_EXCEPTION "Map Exception: "
// --SPECIFICS
#define ERR_MAP_NOT_FOUND "Map not found. Insert the map into the file"
#define ERR_MAP_WALLS "Map is not surrounded by walls"
#define ERR_MAP_POSITION "Map is not the last element in file"
#define ERR_PLAYER_NOT_FOUND "Player not found. Insert N, S, E or W into the map"
// messaggio unico per err_format(per eventuali spazi?) and err_range
#define ERR_INVALID_RGB "Invalid RGB. Insert R,G,B colors in range [0,255]: format example \"0,255,60\""

// -SYSTEM EXCEPTION
#define SYSTEM_EXCEPTION "System Exception: "
// --SPECIFICS
#define ERR_MALLOC "Malloc Error"
#define ERR_OPEN_FILE "Open File Error"
// messaggio unico per mlx e mlx_win
#define ERR_MLX "Error during MLX library initialization"

// extra
#define RGB_DEFINITION "DEFINITION: RGB (red, green and blue) refers to a system representing the colors used on a digital display screen. Red, green and blue can be combined in various proportions to obtain any color in the visible spectrum.\nThe RGB model uses 8 bits each for red, green and blue colors. Each color also has values ranging from 0 to 255. This translates into millions of colors -- 16,777,216 possible colors to be precise."
// ---
#endif
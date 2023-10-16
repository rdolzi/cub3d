/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdolzi <rdolzi@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 22:18:32 by rdolzi            #+#    #+#             */
/*   Updated: 2023/10/16 02:59:48 by rdolzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "so_long.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <math.h>

#define mapX 8  // map width
#define mapY 8  // map height
#define mapS 64 // map cube size
#define W_WIDTH 1024
#define W_HEIGHT 512
#define PADDING 10

int map[]=           //the map array. Edit to change level but keep the outer walls
{
 1,1,1,1,1,1,1,1,
 1,0,1,0,0,0,0,1,
 1,0,1,0,0,0,0,1,
 1,0,1,0,0,0,0,1,
 1,0,0,0,0,0,0,1,
 1,0,0,0,0,1,0,1,
 1,0,0,0,0,0,0,1,
 1,1,1,1,1,1,1,1,	
};

// ------------------------ PLAYER ------------------------
// // def?
// float px;  // pos x
// float py;  // pos y
// float pdx; // pos in  deg x ?
// float pdy; // pos in  deg y ?
// float pa;  //player angle ?

float degToRad(int a)
{
    return (a * M_PI / 180.0);
}
int FixAng(int a)
{
    if(a>359)
        a-=360;
    if(a<0)
        a+=360;
    return (a);
}


// ----------- 1 -----------
// INFO: glutInit(&argc, argv);
// https://www.opengl.org/resources/libraries/glut/spec3/node10.html
// WHAT:  glutInit is used to initialize the GLUT library. glutInit will initialize the GLUT library and negotiate a session with the window system.

// INPUT: A pointer to the program's unmodified argc/argv variable from main.
//  Upon return, the value pointed to by argc/argv will be updated

// OUTPUT: During this process, glutInit may cause the termination of the GLUT program with an error message to the user if GLUT cannot be properly initialized.

// GLUT VS OPENGL
// GLUT (GL Utilities Toolkit) is a library that provides a simplified way of setting up and using OpenGL.
// OpenGL is a graphics API.GLUT is a library that makes using OpenGL a little easier.

// ----------- 2 -----------
// glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
// The initial display mode is used when creating top-level windows, subwindows, and overlays to determine the OpenGL display mode for the to-be-created window or overlay.
// >GLUT_RGB:
//    - An alias for GLUT_RGBA.  select an RGBA mode window. This is the default if neither GLUT_RGBA nor GLUT_INDEX are specified.
//  >GLUT_DOUBLE
//     -  to select a double buffered window.

// ----------- 3 -----------
//  glutInitWindowSize(1024, 510);
// void glutInitWindowSize(int width, int height);
//  set the initial window position and size respectively.
// Windows created by glutCreateWindow will be requested to be created with the current initial window position and size.

// ----------- 4 -----------
// glutCreateWindow("YouTube-3DSage");
// glutCreateWindow creates a top-level window.

// ----------- 5 -----------
// sin / cos: https://www.youmath.it/lezioni/analisi-matematica/le-funzioni-elementari-e-le-loro-proprieta/144-seno-e-coseno-di-un-angolo.html

// def..
// sin(pa) = py
// cos(pa) = px

// init();
// void init()
// {
//     glClearColor(0.3, 0.3, 0.3, 0);
//     gluOrtho2D(0, 1024, 510, 0);
//     px = 150;
//     py = 400;
//     pa = 90;
//     pdx = cos(degToRad(pa));
//     pdy = -sin(degToRad(pa));  ... -sin perche asse è rovesciato ?
// }

// ----------- 5.A -----------
// glClearColor(0.3, 0.3, 0.3, 0);
// glClearColor — specify clear values for the color buffers
// void glClearColor(	GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
// Specify the red, green, blue, and alpha values used when the color buffers are cleared. The initial values are all 0.
//  Values specified by glClearColor are clamped to the range [0,1].

//  calling glClearColor does not clear anything.
// It usually takes the value you've specified, and writes it to a register on the graphics card.
// Only later when you call glClear, with COLOR_BUFFER_BIT, does the buffer actually get cleared to the color you specified.

// ----------- 5.B -----------
// gluOrtho2D(0, 1024, 510, 0);
// gluOrtho2D — define a 2D orthographic projection matrix
// gluOrtho2D VS glutInitWindowSize ??

// ----------- 6 -----------
// glutDisplayFunc(display);
// void glutDisplayFunc(void (*func)(void));
// glutDisplayFunc sets the display callback for the current window.

// void display()
// {
//     glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//     drawMap2D();
//     drawPlayer2D();
//     drawRays2D();
//     glutSwapBuffers();
// }

// ----------- 6.A -----------
//  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//  the buffer actually get cleared to the color you specified previously.

// void drawMap2D()
// {
//  int x;
//  int y;
//  int xo;
//  int yo;
//  for(y=0;y<mapY;y++)
//  {
//   for(x=0;x<mapX;x++)
//   {
//    if(map[y*mapX+x]==1){ glColor3f(1,1,1);} else{ glColor3f(0,0,0);}
//    xo=x*mapS; yo=y*mapS;
//    glBegin(GL_QUADS);
//    glVertex2i( 0   +xo+1, 0   +yo+1);
//    glVertex2i( 0   +xo+1, mapS+yo-1);
//    glVertex2i( mapS+xo-1, mapS+yo-1);
//    glVertex2i( mapS+xo-1, 0   +yo+1);
//    glEnd();
//   }
//  }
// }
// ----------- 6.A.1 -----------
// glColor — set the current color

void draw_background(t_game *game)
{
    int x;
    int y;

    y = PADDING;
    game->bg.img = mlx_new_image(game->mlx, W_WIDTH, W_HEIGHT);
    game->bg.data = (int *)mlx_get_data_addr(game->bg.img, &game->bg.bpp, &game->bg.size_l, &game->bg.endian);
    while (++y < W_HEIGHT - PADDING)
    {
        x = PADDING;
        while (++x < W_WIDTH - PADDING)
        {
            game->bg.data[y * W_WIDTH + x] = 0xADD8E6; //LIGHT BLUE
            // if (x % 2)
            //     game->bg.data[y * W_WIDTH + x] = 0xADD8E6;
            // else
            //     game->bg.data[y * W_WIDTH + x] = 0;
        }
    }
    // mlx_put_image_to_window(game->mlx, game->mlx_win, game->bg.img, 0, 0);
}

void draw_rectangle(int xo, int yo, t_game *game, int color)
{
    int x;
    int y;
    int size_y;
    int size_x;

    y = yo;
    size_y = 64;
    printf("inizio:draw_rectangle\n");
    while (size_y-- - 2 > 0)
    {
        x = xo;
        size_x = mapS;
        while (size_x-- - 2  > 0)
        {
            game->bg.data[y  * W_WIDTH + x ] = color; // LIGHT BLUE
            printf("x:%d|y%d| size_x: %d| size_y:%d\n", x, y, size_x, size_y);
            x++;
        }
        y++;
        printf("nuovo giro y??\n");
        printf("x:%d|y%d| size_x: %d| size_y:%d\n", x, y, size_x, size_y);
    }
    printf("fine:draw_rectangle\n");
}

void draw_map2d(t_game *game)
{
    int x;
    int y;
    int color; // unsigned int ??
    y = -1;
    while (++y < mapY)
    {
        x = -1;
        while (++x < mapX)
        {
            if (map[y * mapX + x] == 1)
                color = 0xFFFFFF; // WHITE
            else
                color =  0x000000; // BLACK
            draw_rectangle(x * mapS , y * mapS , game, color);
            printf("draw_rectangle\n");
        }
    }
}

void init(t_game *game)
{
    // glClearColor(0.3, 0.3, 0.3, 0);
    // gluOrtho2D(0, 1024, 510, 0);
    draw_background(game);
    draw_map2d(game);
    // game->player.px = 150;
    // game->player.px = 400;
    // game->player.pa = 90;
    // game->player.pdx = cos(degToRad(game->player.pa));
    // game->player.pdy = -sin(degToRad(game->player.pa)); // ... -sin perche asse è rovesciato ?
}

int main(int ac, char **av)
{
    (void) ac;
    (void) av;
    // https://www.youtube.com/watch?v=gYRrGTC7GtA
    // https://github.com/3DSage/OpenGL-Raycaster_v1/blob/master/3DSage_Raycaster_v1.c

    // glutInit(&ac, av);
    // glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    // glutInitWindowSize(1024, 510);
    // glutCreateWindow("YouTube-3DSage");
    // init();
    // glutDisplayFunc(display);
    t_game game;
    game.mlx = mlx_init();
    game.mlx_win = mlx_new_window(game.mlx, W_WIDTH, W_HEIGHT, "YouTube-3DSage");
    init(&game);
    mlx_put_image_to_window(game.mlx, game.mlx_win, game.bg.img, 0, 0);
    mlx_loop(game.mlx);
}
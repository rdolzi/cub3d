# Cub3D 

The ``Cub3D`` project is an introductory graphics programming assignment at 42 School, inspired by the classic game Wolfenstein 3D and requires ``C`` as programming language.
The primary objective of the project is to create a basic 3D game engine using the raycasting technique to render a 3D world from a first-person perspective.
Cub3D serves as a stepping stone to more advanced graphics and game development projects, providing hands-on experience in creating a simple yet functional 3D game engine from scratch.



## Run Program:

MacOS/Linux:

```sh
    cd $HOME/Desktop && git clone https://github.com/rdolzi/cub3d.git && cd cub3d && make && ./cub3d assets/maps/1.cub
```

## Makefile Commands

| Command      | Description                                               |
|--------------|-----------------------------------------------------------|
| `make`       | Compiles the project and generates the executable.        |
| `make re`    | Cleans the project and recompiles everything from scratch.|
| `make clean` | Removes object files and other temporary files.           |
| `make fclean`| Removes all generated files, including the executable.    |

## Game Commands

| KEY           | Action        |
| ------------- |:-------------:|
| `ESC`         | exit          |
| `A`           | move left     |
| `D`           | move right    |
| `W`           | move forward  |
| `S`           | move backward |
| `→`           | turn right    |
| `←`           | turn left     |
| `MOUSE RIGHT ROTATION`| turn right |
| `MOUSE LEFT ROTATION` | turn left|



### Map Modifications
You can freely modify the map with settings of your choice!
Go to assets/maps/1.cub files then follow this rules:
| Code           | Value         |
| -------------  | ------------- |
| `1`            | Wall          |
| `0`            | Floor         |
| `N`/`E`/`W`/`S`| Player initial position & orientation|


You can have a look at the [subject](https://github.com/rdolzi/cub3d/blob/master/subject.pdf) for further details on how `.cub` files and project in general work.



## Project Key Features:
### Ray-Casting Engine
Implement a 2D ray-casting algorithm to simulate a 3D environment.

### Graphics Rendering
Use the MiniLibX library for handling window creation, drawing pixels, and capturing keyboard events.

### Map Parsing
Load and interpret a predefined map layout from a file to generate the game world.

### Player Mechanics
Implement basic player movement and interactions within the 3D space, including collision detection.


## Learning Objectives
### Graphics Programming
Gain foundational knowledge in computer graphics and rendering techniques.
### Algorithm Implementation
Understand and apply the ray-casting algorithm.
### Event Handling
Learn to manage user inputs and real-time events.




**Note:** 42 School developed two version of MinlLibX: one for [macOS](https://github.com/dannywillems/minilibx-mac-osx) one for [Linux](https://github.com/42Paris/minilibx-linux)

### Our project supports both MacOS and Linux!

The project evaluation was done on Linux (Ubuntu distro), so only the Linux library is required for the project.
However, we decided to support both OS because it allowed the team to work remotely with our personal PCs (MacBooks).
For more information about the integration, take a look at the [Makefile](https://github.com/rdolzi/cub3d/blob/master/Makefile) for compilation and [cube.h](https://github.com/rdolzi/cub3d/blob/master/include/cube.h) for key value bindings.



## RESOURCES

### Raycasting:
By [lodev.org](https://lodev.org/cgtutor/raycasting.html)  
By [permadi.com](https://permadi.com/1996/05/ray-casting-tutorial-table-of-contents/)  
By [3DSage, Youtube](https://www.youtube.com/watch?v=PC1RaETIx3Y)  

### MinLibX:
[How to draw a line](https://gontjarow.github.io/MiniLibX/mlx-tutorial-draw-line.html)  
[New image](https://gontjarow.github.io/MiniLibX/mlx_new_image.html)  
[Pixel drawing](https://aurelienbrabant.fr/blog/pixel-drawing-with-the-minilibx)  
[How to flatten a 2-dimensional array](https://github.com/keuhdall/images_example/blob/master/example.c)


## FINAL GRADE : 110/100
### Mandatory: 100/100 | Bonus: 10/25

This project was made in collaboration with [fbiondo](https://github.com/fla0000000)
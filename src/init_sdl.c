/*
** init_sdl.c for  in /home/brilla_a//rendu/rush/epikong
** 
** Made by jason brillante
** Login   <brilla_a@epitech.net>
** 
** Started on  Sun Mar 27 22:41:22 2011 jason brillante
** Last update Sun Mar 27 22:41:55 2011 jason brillante
*/

#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <SDL/SDL.h>
#include "epikong.h"

void			init_sdl(t_epikong *ekg)
{
  if (SDL_Init(SDL_INIT_VIDEO) == -1)
    my_error("error: sdl_INIT\n", DIE);
  SDL_WM_SetCaption("epikong", NULL);
  ekg->sdl.ecran = SDL_SetVideoMode(WIDTH, HEIGHT, 32,
				    SDL_HWSURFACE | SDL_DOUBLEBUF);
  if (ekg->sdl.ecran == NULL)
    my_error("error: SDL_SETVIDEOMODE\n", DIE);
  ekg->sdl.wall.ptr = x_IMG_Load("pic/wall.png");
  ekg->sdl.brush.ptr = x_IMG_Load("pic/brush.png");
  ekg->sdl.ladder.ptr = x_IMG_Load("pic/ladder.png");
  ekg->sdl.jazzanime.ptr = x_IMG_Load("pic/jazzanime2.png");
  ekg->sdl.background.ptr = x_IMG_Load("pic/background.png");
  ekg->sdl.robot.ptr = x_IMG_Load("pic/robotmonster.png");
  ekg->sdl.key.ptr = x_IMG_Load("pic/carot.png");
  ekg->sdl.outdoor.ptr = x_IMG_Load("pic/outdoor.png");
}

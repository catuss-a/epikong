/*
** display.c for epikong in /home/serraj_y//Desktop/epikong
** 
** Made by younes serraj
** Login   <serraj_y@epitech.net>
** 
** Started on  Sun Mar 27 22:38:56 2011 younes serraj
** Last update Sun Mar 27 22:42:57 2011 younes serraj
*/

#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <SDL/SDL.h>
#include "epikong.h"

void			display_background(t_epikong *ekg)
{
  int			x;
  int			y;
  SDL_Rect		coord;
  int			basex;
  int			basey;

  y = ekg->camera.lookat.y / 50;
  basey = 0 - (ekg->camera.lookat.y % 50);
  while (ekg->map[y])
    {
      coord.y = basey;
      x = ekg->camera.lookat.x / 50;
      basex =  - (ekg->camera.lookat.x % 50);
      while (ekg->map[y][x])
	{
	  coord.y = basey;
	  coord.x = basex;
	  if (ekg->map[y][x] == WALL)
	    {
	      SDL_BlitSurface(ekg->sdl.wall.ptr, NULL,
			      ekg->sdl.ecran, &coord);
	    }
	  else if (ekg->map[y][x] == LADDER)
	    {
	      SDL_BlitSurface(ekg->sdl.ladder.ptr, NULL,
			      ekg->sdl.ecran, &coord);
	    }
	  else if (ekg->map[y][x] == BRUSH)
	    {
	      SDL_BlitSurface(ekg->sdl.brush.ptr, NULL,
			      ekg->sdl.ecran, &coord);
	    }
	  basex += 50;
	  ++x;
	}
      basey += 50;
      ++y;
    }
}

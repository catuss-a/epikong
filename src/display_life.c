/*
** display.c for epikong in /home/serraj_y//Desktop/epikong
** 
** Made by younes serraj
** Login   <serraj_y@epitech.net>
** 
** Started on  Sun Mar 27 22:38:56 2011 younes serraj
** Last update Sun Mar 27 22:44:59 2011 younes serraj
*/

#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <SDL/SDL.h>
#include "epikong.h"

void			display_life(t_epikong *ekg)
{
  SDL_Rect		coord;
  SDL_Rect		clip;
  int			x;
  static float		i = 0;

  if (i >= 11)
    i = 0;
  for (x = 0; x < ekg->hero_l->life; ++x)
    {
      coord.x = x * 60 + 25;
      coord.y = 25;
      clip.x = ekg->lifeanime[(int)i].pos.x;
      clip.y = ekg->lifeanime[(int)i].pos.y;
      clip.h = ekg->lifeanime[(int)i].h;
      clip.w = ekg->lifeanime[(int)i].w;
      SDL_BlitSurface(ekg->sdl.jazzanime.ptr, &clip,
		      ekg->sdl.ecran, &coord);
    }
  i += 0.01;
}

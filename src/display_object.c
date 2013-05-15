/*
** display.c for epikong in /home/serraj_y//Desktop/epikong
** 
** Made by younes serraj
** Login   <serraj_y@epitech.net>
** 
** Started on  Sun Mar 27 22:38:56 2011 younes serraj
** Last update Sun Mar 27 22:45:31 2011 younes serraj
*/

#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <SDL/SDL.h>
#include "epikong.h"

void			display_object(t_epikong *ekg)
{
  t_object		*tmp;
  SDL_Rect		coord;

  for (tmp = ekg->objs_l; tmp; tmp = tmp->next)
    {
      coord.x = tmp->pos.x - ekg->camera.lookat.x;
      coord.y = tmp->pos.y - ekg->camera.lookat.y;
      if (tmp->type == KEY)
	{
	  SDL_BlitSurface(ekg->sdl.key.ptr, NULL,
			  ekg->sdl.ecran, &coord);
	}
      else if (tmp->type == OUTDOOR)
	{
	  SDL_BlitSurface(ekg->sdl.outdoor.ptr, NULL,
			  ekg->sdl.ecran, &coord);
	}
    }
}

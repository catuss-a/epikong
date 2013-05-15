/*
** display.c for epikong in /home/serraj_y//Desktop/epikong
** 
** Made by younes serraj
** Login   <serraj_y@epitech.net>
** 
** Started on  Sun Mar 27 22:38:56 2011 younes serraj
** Last update Sun Mar 27 23:07:42 2011 axel catusse
*/

#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <SDL/SDL.h>
#include "epikong.h"

void			display_runleft(t_epikong *ekg)
{
  SDL_Rect		coord;
  SDL_Rect		sprite;
  static float		i = 0;

  if (i >= RUN_JAZZANIM_SIZE)
    i = 0;
  coord.x = ekg->hero_l->pos.x - ekg->camera.lookat.x;
  coord.y = ekg->hero_l->pos.y - ekg->camera.lookat.y;
  sprite.w = ekg->hero_l->animation.runleft[(int)i].w;
  sprite.h = ekg->hero_l->animation.runleft[(int)i].h;
  sprite.x = ekg->hero_l->animation.runleft[(int)i].pos.x;
  sprite.y = ekg->hero_l->animation.runleft[(int)i].pos.y;
  i += 0.05;
  SDL_BlitSurface(ekg->sdl.jazzanime.ptr, &sprite,
		  ekg->sdl.ecran, &coord);
}

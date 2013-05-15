/*
** display.c for epikong in /home/serraj_y//Desktop/epikong
** 
** Made by younes serraj
** Login   <serraj_y@epitech.net>
** 
** Started on  Sun Mar 27 22:38:56 2011 younes serraj
** Last update Sun Mar 27 23:07:58 2011 axel catusse
*/

#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <SDL/SDL.h>
#include "epikong.h"

void			display_runleft_robot(t_epikong *ekg, t_char *monster)
{
  SDL_Rect		coord;
  SDL_Rect		sprite;

  if (monster->idx_anim >= RUN_JAZZANIM_SIZE)
    monster->idx_anim = 0;
  coord.x = monster->pos.x - ekg->camera.lookat.x;
  coord.y = monster->pos.y - ekg->camera.lookat.y;
  sprite.w = monster->animation.runleft[(int)monster->idx_anim].w;
  sprite.h = monster->animation.runleft[(int)monster->idx_anim].h;
  sprite.x = monster->animation.runleft[(int)monster->idx_anim].pos.x;
  sprite.y = monster->animation.runleft[(int)monster->idx_anim].pos.y;
  monster->idx_anim += 0.04;
  SDL_BlitSurface(ekg->sdl.robot.ptr, &sprite,
		  ekg->sdl.ecran, &coord);
}

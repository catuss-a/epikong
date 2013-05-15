/*
** gravity_hero.c for grav in /home/catuss_a//Desktop/epikong/etape_2/src
** 
** Made by axel catusse
** Login   <catuss_a@epitech.net>
** 
** Started on  Sun Mar 27 22:45:31 2011 axel catusse
** Last update Sun Mar 27 23:05:41 2011 axel catusse
*/

#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "epikong.h"

void			gravity_hero(t_epikong *ekg)
{
  int			x;
  int			y;


  x = (ekg->hero_l->pos.x + (WIDTH_ANIM_JAZZ / 2)) / 50;
  y = (ekg->hero_l->pos.y + HEIGHT_ANIM_JAZZ) / 50;
  if (ekg->map[y][x] == EMPTY)
    {
      ekg->hero_l->yspeed += 1;
      ekg->hero_l->pos.y += ekg->hero_l->yspeed / 100 + 2;
      x = (ekg->hero_l->pos.x + (WIDTH_ANIM_JAZZ / 2)) / 50;
      y = (ekg->hero_l->pos.y  + HEIGHT_ANIM_JAZZ) / 50;
      if (y >= ekg->map_size.y)
	{
	  usleep(700000);
	  printf("YOU LOSE !\n");
	  exit(0);
	}
      if (ekg->map[y][x] != EMPTY)
	{
	  if (ekg->hero_l->yspeed > 110)
	    {
	      ekg->hero_l->life -= 1;
	      if (ekg->hero_l->life <= 0)
		{
		  usleep(100000);
		  printf("YOU LOSE !\n");
		  exit(0);
		}
	      ekg->hero_l->blink = 200;
	    }
	  ekg->hero_l->pos.y -= ekg->hero_l->pos.y % 50;
	  ekg->hero_l->yspeed = 0;
	}
    }
}

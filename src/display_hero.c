/*
** display.c for epikong in /home/serraj_y//Desktop/epikong
** 
** Made by younes serraj
** Login   <serraj_y@epitech.net>
** 
** Started on  Sun Mar 27 22:38:56 2011 younes serraj
** Last update Sun Mar 27 22:44:12 2011 younes serraj
*/

#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <SDL/SDL.h>
#include "epikong.h"

void			display_hero(t_epikong *ekg)
{
  static float		beginjump = 0;

  if (ekg->hero_l->grimper != 0)
    display_grimper(ekg);
  else
    {
      if (ekg->hero_l->yspeed > 0)
	display_fall(ekg, &beginjump);
      else if (ekg->hero_l->yspeed < 0)
	display_jump(ekg);
      else if (ekg->hero_l->xspeed > 0)
	display_runright(ekg);
      else if (ekg->hero_l->xspeed < 0)
	display_runleft(ekg);
      else if (ekg->hero_l->xspeed == 0)
	display_idle(ekg);
      if (ekg->hero_l->yspeed == 0)
	beginjump = 0;
    }
}

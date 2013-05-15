/*
** display.c for epikong in /home/serraj_y//Desktop/epikong
** 
** Made by younes serraj
** Login   <serraj_y@epitech.net>
** 
** Started on  Sun Mar 27 22:38:56 2011 younes serraj
** Last update Sun Mar 27 22:45:14 2011 younes serraj
*/

#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <SDL/SDL.h>
#include "epikong.h"

void			display_monster(t_epikong *ekg)
{
  t_char		*tmp;

  for (tmp = ekg->monster_l; tmp; tmp = tmp->next)
    {
      if (tmp->xspeed > 0)
	display_runright_robot(ekg, tmp);
      else if (tmp->xspeed < 0)
	display_runleft_robot(ekg, tmp);
    }
}

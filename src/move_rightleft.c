/*
** move_rightleft.c for move in /home/catuss_a//Desktop/epikong/etape_2/src
** 
** Made by axel catusse
** Login   <catuss_a@epitech.net>
** 
** Started on  Sun Mar 27 22:45:57 2011 axel catusse
** Last update Sun Mar 27 22:47:20 2011 axel catusse
*/

#include "epikong.h"

void			move_rightandleft(t_epikong *ekg)
{
  int			x;
  int			y;
  int			check;
  int			i;

  if (ekg->key.right == 1)
    {
      ekg->hero_l->grimper = 0;
      check = 0;
      for (i = 0; i < HEIGHT_ANIM_JAZZ; ++i)
	{
	  y = (ekg->hero_l->pos.y + i) / 50;
	  x = (ekg->hero_l->pos.x + WIDTH_ANIM_JAZZ - 10 + 1) / 50;
	  if (ekg->map[y][x] == WALL)
	    {
	      check = 1;
	      break;
	    }
	}
      if (check == 0)
	{
	  ekg->hero_l->pos.x += 1;
	  ekg->hero_l->xspeed = 1;
	}
    }
  else if (ekg->key.left == 1)
    {
      ekg->hero_l->grimper = 0;
      check = 0;
      for (i = 0; i < HEIGHT_ANIM_JAZZ; ++i)
	{
	  x = (ekg->hero_l->pos.x - 1) / 50;
	  y = (ekg->hero_l->pos.y + i) / 50;
	  if (ekg->map[y][x] == WALL)
	    {
	      check = 1;
	      break;
	    }
	}
      if (check == 0)
	{
	  ekg->hero_l->pos.x -= 1;
	  ekg->hero_l->xspeed = -1;
	}
    }
  else if (ekg->hero_l->yspeed == 0)
    ekg->hero_l->xspeed = 0;
}

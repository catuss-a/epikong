/*
** move_monster.c for movnster in /home/catuss_a//Desktop/epikong/etape_2/src
** 
** Made by axel catusse
** Login   <catuss_a@epitech.net>
** 
** Started on  Sun Mar 27 22:43:03 2011 axel catusse
** Last update Sun Mar 27 22:43:13 2011 axel catusse
*/

#include "epikong.h"

void			move_monster(t_epikong *ekg)
{
  t_char		*tmp;
  int			x;
  int			y;

  for (tmp = ekg->monster_l; tmp; tmp = tmp->next)
    {
      x = (tmp->pos.x + (WIDTH_ANIM_JAZZ / 2)) / 50;
      y = (tmp->pos.y + HEIGHT_ANIM_JAZZ) / 50;
      if (ekg->map[y][x] == EMPTY)
	tmp->xspeed *= -1;
      if (tmp->xspeed > 0)
	{
	  x = (tmp->pos.x + (WIDTH_ANIM_JAZZ / 2) + 1) / 50;
	  y = (tmp->pos.y + HEIGHT_ANIM_JAZZ / 2) / 50;
	  if (ekg->map[y][x] != WALL)
	    tmp->pos.x += 1;
	  else
	    tmp->xspeed *= -1;
	}
      else if (tmp->xspeed < 0)
	{
	  x = (tmp->pos.x + (WIDTH_ANIM_JAZZ / 2) - 1) / 50;
	  y = (tmp->pos.y + HEIGHT_ANIM_JAZZ / 2) / 50;
	  if (ekg->map[y][x] != WALL)
	    tmp->pos.x -= 1;
	  else
	    tmp->xspeed *= -1;
	}
    }
}

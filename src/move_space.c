/*
** move_space.c for move in /home/catuss_a//Desktop/epikong/etape_2/src
** 
** Made by axel catusse
** Login   <catuss_a@epitech.net>
** 
** Started on  Sun Mar 27 22:44:44 2011 axel catusse
** Last update Sun Mar 27 22:45:02 2011 axel catusse
*/

#include "epikong.h"

void			move_space(t_epikong *ekg)
{
  static int		i = 201;
  static int		ybase = 0;
  int			tmp;
  int			x;
  int			yh;
  int			yf;

  if (ekg->key.space == 1 && i >= 201)
    {
      ekg->hero_l->grimper = 0;
      ybase = ekg->hero_l->pos.y;
      ekg->hero_l->yspeed = -1;
      i = 0;
    }
  if (i < 200)
    {
      tmp = (-0.04 * pow((i / 2) - 50, 2) + 120) * -1 + ybase;
      x = (ekg->hero_l->pos.x + (WIDTH_ANIM_JAZZ / 2)) / 50;
      yf = (tmp + HEIGHT_ANIM_JAZZ) / 50;
      yh = tmp / 50;
      if (i < 100)
	{
	  if (ekg->map[yh][x] == EMPTY || ekg->map[yh][x] == LADDER)
	    ekg->hero_l->pos.y = tmp;
	  else
	    i = (100 - i) + 100;
	}
      else if (i < 201)
	{
	  if (ekg->map[yf][x] == EMPTY)
	    ekg->hero_l->pos.y = tmp;
	  else
	    i = 201;
	}
      i = i + 1;
    }
  if (i >= 200)
    {
      ekg->key.space = 0;
      ekg->hero_l->yspeed = 0;
      i = 201;
    }
}

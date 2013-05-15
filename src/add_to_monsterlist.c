/*
** add_to_monsterlist.c for add in /home/catuss_a//Desktop/epikong/etape_2/src
** 
** Made by axel catusse
** Login   <catuss_a@epitech.net>
** 
** Started on  Sun Mar 27 22:48:51 2011 axel catusse
** Last update Sun Mar 27 22:49:03 2011 axel catusse
*/

#include "epikong.h"

void			add_to_monsterlist(t_epikong *ekg,
					   int x,
					   int y)
{
  t_char		*new;

  ekg->map[y][x] = EMPTY;
  new = xmalloc(sizeof(*new));
  memset(new, 0, sizeof(*new));
  new->pos.x = x * 50;
  new->pos.y = y * 50;
  new->life = 1;
  new->xspeed = 1;
  fill_animation_robotmonster(new);
  new->next = ekg->monster_l;
  ekg->monster_l = new;
}


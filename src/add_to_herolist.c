/*
** add_to_herolist.c for epi in /home/catuss_a//Desktop/epikong/etape_2/src
** 
** Made by axel catusse
** Login   <catuss_a@epitech.net>
** 
** Started on  Sun Mar 27 22:50:19 2011 axel catusse
** Last update Sun Mar 27 22:50:32 2011 axel catusse
*/

#include "epikong.h"

void			add_to_herolist(t_epikong *ekg,
					int x,
					int y)
{
  t_char		*new;

  ekg->map[y][x] = EMPTY;
  new = xmalloc(sizeof(*new));
  memset(new, 0, sizeof(*new));
  new->pos.x = x * 50;
  new->pos.y = y * 50;
  new->life = 3;
  fill_animation_jazz(new);
  new->next = ekg->hero_l;
  ekg->hero_l = new;
}

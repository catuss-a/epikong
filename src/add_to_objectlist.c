/*
** add_to_objectlist.c for add in /home/catuss_a//Desktop/epikong/etape_2/src
** 
** Made by axel catusse
** Login   <catuss_a@epitech.net>
** 
** Started on  Sun Mar 27 22:48:20 2011 axel catusse
** Last update Sun Mar 27 22:48:32 2011 axel catusse
*/

#include "epikong.h"

void			add_to_objectlist(t_epikong *ekg,
					  int x,
					  int y,
					  char type)
{
  t_object		*new;

  ekg->map[y][x] = EMPTY;
  new = xmalloc(sizeof(*new));
  memset(new, 0, sizeof(*new));
  new->type = type;
  new->pos.x = x * 50;
  new->pos.y = y * 50;
  new->next = ekg->objs_l;
  ekg->objs_l = new;
}

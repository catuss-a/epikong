/*
** init_game.c for init in /home/catuss_a//Desktop/epikong/etape_2/src
** 
** Made by axel catusse
** Login   <catuss_a@epitech.net>
** 
** Started on  Sun Mar 27 22:47:29 2011 axel catusse
** Last update Sun Mar 27 22:47:49 2011 axel catusse
*/

#include "epikong.h"

void			init_game(t_epikong *ekg)
{
  int			x;
  int			y;

  ekg->hero_l = NULL;
  ekg->monster_l = NULL;
  ekg->objs_l = NULL;
  ekg->map = ekg->allmap[ekg->level - 1];
  for (y = 0; ekg->map[y]; ++y)
    ;
  ekg->map_size.y = y;
  ekg->map_size.x = strlen(*ekg->map);
  printf("level : %d ! Find The Carott !\n", ekg->level);
  for (y = 0; y < 11; ++y)
    {
      ekg->lifeanime[y].w = WIDTH_ANIM_JAZZ;
      ekg->lifeanime[y].h = HEIGHT_ANIM_JAZZ;
      ekg->lifeanime[y].pos.x = y * WIDTH_ANIM_JAZZ;
      ekg->lifeanime[y].pos.y = 9 * HEIGHT_ANIM_JAZZ;
    }
  for (y = 0; ekg->map[y]; ++y)
    {
      for (x = 0; ekg->map[y][x]; ++x)
	{
	  if (ekg->map[y][x] == INDOOR)
	    add_to_herolist(ekg, x, y);
	  else if (ekg->map[y][x] == MONSTER)
	    add_to_monsterlist(ekg, x, y);
	  else if (ekg->map[y][x] == KEY)
	    add_to_objectlist(ekg, x, y, KEY);
	  else if (ekg->map[y][x] == OUTDOOR)
	    add_to_objectlist(ekg, x, y, OUTDOOR);
	}
    }
}

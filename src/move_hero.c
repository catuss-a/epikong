/*
** move_hero.c for hero in /home/catuss_a//Desktop/epikong/etape_2/src
** 
** Made by axel catusse
** Login   <catuss_a@epitech.net>
** 
** Started on  Sun Mar 27 22:40:48 2011 axel catusse
** Last update Sun Mar 27 23:05:30 2011 axel catusse
*/

#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "epikong.h"

int			find_objs(t_object *obj,
				  char type)

{
  t_object		*ptr;

  for (ptr = obj; ptr; ptr = ptr->next)
    if (ptr->type == type)
      return (1);
  return (0);
}

void			move_updown(t_epikong *ekg)
{
  int			x;
  int			y;

  if (ekg->key.up == 1)
    {
      x = (ekg->hero_l->pos.x + (WIDTH_ANIM_JAZZ / 2)) / 50;
      y = (ekg->hero_l->pos.y + HEIGHT_ANIM_JAZZ - 1) / 50;
      if (ekg->map[y][x] == LADDER)
	{
	  ekg->hero_l->pos.x = x * 50;
	  ekg->hero_l->grimper = -1;
	  ekg->hero_l->pos.y -= 1;
	}
      else
	ekg->hero_l->grimper = 0;
    }
  else if (ekg->key.down == 1)
    {
      x = (ekg->hero_l->pos.x + (WIDTH_ANIM_JAZZ / 2)) / 50;
      y = (ekg->hero_l->pos.y + HEIGHT_ANIM_JAZZ + 1) / 50;
      if (ekg->map[y][x] == LADDER)
	{
	  ekg->hero_l->pos.x = x * 50;
	  ekg->hero_l->grimper = 1;
	  ekg->hero_l->pos.y += 1;
	}
      else
	ekg->hero_l->grimper = 0;
    }
  else
    {
      x = (ekg->hero_l->pos.x + (WIDTH_ANIM_JAZZ / 2)) / 50;
      y = (ekg->hero_l->pos.y + HEIGHT_ANIM_JAZZ / 2) / 50;
      if (ekg->map[y][x] == LADDER)
	ekg->hero_l->grimper = -2;
      else
	ekg->hero_l->grimper = 0;
    }
}

void			move_hero(t_epikong *ekg)
{
  t_object		*ptr;
  t_object		*ptr2;
  t_char		*ptr3;

  move_rightandleft(ekg);
  move_updown(ekg);
  if (ekg->hero_l->yspeed >= 0 && ekg->key.space == 0)
    gravity_hero(ekg);
  else
    move_space(ekg);
  for (ptr = ekg->objs_l; ptr; ptr = ptr->next)
    if (ptr->pos.x / 50 == ekg->hero_l->pos.x / 50 &&
	ptr->pos.y / 50 == ekg->hero_l->pos.y / 50)
      {
	if (ptr->type == KEY)
	  {
	    ptr2 = xmalloc(sizeof(*ptr));
	    memcpy(ptr2, ptr, sizeof(*ptr));
	    ptr2->next = ekg->hero_l->inv_l;
	    ekg->hero_l->inv_l = ptr2;
	    ptr->type = EMPTY;
	    break;
	  }
	else if (ptr->type == OUTDOOR && find_objs(ekg->hero_l->inv_l, KEY))
	  {
	    usleep(100000);
	    ++ekg->level;
	  }
      }
  for (ptr3 = ekg->monster_l; ptr3; ptr3 = ptr3->next)
    if (ptr3->pos.x / 50 == ekg->hero_l->pos.x / 50 &&
	ptr3->pos.y / 50 == ekg->hero_l->pos.y / 50 &&
	ekg->hero_l->blink == 0)
      {
	if ((ekg->hero_l->life -= 1) <= 0)
	  {
	    printf("YOU LOSE !\n");
	    exit(0);
	  }
	ekg->hero_l->blink = 200;
      }
  if (ekg->hero_l->blink > 0)
    ekg->hero_l->blink -= 1;
}

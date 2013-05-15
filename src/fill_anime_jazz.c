/*
** fill_anime_jazz.c for lol in /home/catuss_a//Desktop/epikong/etape_2
** 
** Made by axel catusse
** Login   <catuss_a@epitech.net>
** 
** Started on  Sun Mar 27 23:10:50 2011 axel catusse
** Last update Sun Mar 27 23:12:51 2011 axel catusse
*/

#include "epikong.h"

void			fill_anim_1(t_char *new)
{
  int			i;

  for (i = 0; i < RUN_JAZZANIM_SIZE; ++i)
    {
      new->animation.runright[i].w = WIDTH_ANIM_JAZZ;
      new->animation.runright[i].h = HEIGHT_ANIM_JAZZ;
      new->animation.runright[i].pos.x = i * WIDTH_ANIM_JAZZ;
      new->animation.runright[i].pos.y = 0;
    }
  for (i = 0; i < 12; ++i)
    {
      new->animation.ladder[i].w = WIDTH_ANIM_JAZZ;
      new->animation.ladder[i].h = HEIGHT_ANIM_JAZZ;
      new->animation.ladder[i].pos.x = i * WIDTH_ANIM_JAZZ;
      new->animation.ladder[i].pos.y = 3 * HEIGHT_ANIM_JAZZ;
    }
}

void			fill_anim_2(t_char *new)
{
  int			i;

  for (i = RUN_JAZZANIM_SIZE - 1; i >= 0; --i)
    {
      new->animation.runleft[i].w = WIDTH_ANIM_JAZZ;
      new->animation.runleft[i].h = HEIGHT_ANIM_JAZZ;
      new->animation.runleft[i].pos.x = i * WIDTH_ANIM_JAZZ;
      new->animation.runleft[i].pos.y = HEIGHT_ANIM_JAZZ;
    }
  for (i = 0; i < 54; ++i)
    {
      new->animation.idle[i].w = WIDTH_ANIM_JAZZ;
      new->animation.idle[i].h = HEIGHT_ANIM_JAZZ;
      new->animation.idle[i].pos.x = i * WIDTH_ANIM_JAZZ;
      new->animation.idle[i].pos.y = HEIGHT_ANIM_JAZZ * 2;
    }
}

void			fill_animation_jazz(t_char *new)
{
  int			i;

  fill_anim_1(new);
  fill_anim_2(new);
  for (i = 0; i < RUN_JAZZANIM_SIZE; ++i)
    {
      new->animation.jump[i].w = WIDTH_ANIM_JAZZ;
      new->animation.jump[i].h = HEIGHT_ANIM_JAZZ;
      new->animation.jump[i].pos.x = i * WIDTH_ANIM_JAZZ;
      new->animation.jump[i].pos.y = 4 * HEIGHT_ANIM_JAZZ;
    }
  for (i = 0; i < RUN_JAZZANIM_SIZE + 1; ++i)
    {
      new->animation.fall[i].w = WIDTH_ANIM_JAZZ;
      new->animation.fall[i].h = HEIGHT_ANIM_JAZZ;
      new->animation.fall[i].pos.x = i * WIDTH_ANIM_JAZZ;
      new->animation.fall[i].pos.y = 5 * HEIGHT_ANIM_JAZZ;
    }
}

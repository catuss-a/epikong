/*
** fill_anime_robot.c for lol in /home/catuss_a//Desktop/epikong/etape_2/src
** 
** Made by axel catusse
** Login   <catuss_a@epitech.net>
** 
** Started on  Sun Mar 27 22:49:44 2011 axel catusse
** Last update Sun Mar 27 23:06:36 2011 axel catusse
*/

#include "epikong.h"

void			fill_animation_robotmonster(t_char *new)
{
  int			i;

  for (i = 0; i < RUN_JAZZANIM_SIZE; ++i)
    {
      new->animation.runright[i].w = WIDTH_ANIM_JAZZ;
      new->animation.runright[i].h = HEIGHT_ANIM_JAZZ;
      new->animation.runright[i].pos.x = i * WIDTH_ANIM_JAZZ;
      new->animation.runright[i].pos.y = 0;
    }
  for (i = RUN_JAZZANIM_SIZE - 1; i >= 0; --i)
    {
      new->animation.runleft[i].w = WIDTH_ANIM_JAZZ;
      new->animation.runleft[i].h = HEIGHT_ANIM_JAZZ;
      new->animation.runleft[i].pos.x = i * WIDTH_ANIM_JAZZ;
      new->animation.runleft[i].pos.y = HEIGHT_ANIM_JAZZ;
    }
}

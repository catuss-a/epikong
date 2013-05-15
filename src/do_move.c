/*
** do_move.c for monster in /home/catuss_a//Desktop/epikong/etape_2/src
** 
** Made by axel catusse
** Login   <catuss_a@epitech.net>
** 
** Started on  Sun Mar 27 22:43:35 2011 axel catusse
** Last update Sun Mar 27 22:43:46 2011 axel catusse
*/

#include "epikong.h"

void			do_move(t_epikong *ekg)
{
  move_hero(ekg);
  move_camera(ekg);
  move_monster(ekg);
}

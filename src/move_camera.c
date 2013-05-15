/*
** move_camera.c for cam in /home/catuss_a//Desktop/epikong/etape_2/src
** 
** Made by axel catusse
** Login   <catuss_a@epitech.net>
** 
** Started on  Sun Mar 27 22:42:04 2011 axel catusse
** Last update Sun Mar 27 22:42:16 2011 axel catusse
*/

#include "epikong.h"

void			move_camera(t_epikong *ekg)
{
  ekg->camera.lookat.x = ekg->hero_l->pos.x - (WIDTH / 2);
  ekg->camera.lookat.y = ekg->hero_l->pos.y - (HEIGHT / 2);
  if (ekg->camera.lookat.y < 0)
    ekg->camera.lookat.y = 0;
  if (ekg->camera.lookat.x < 0)
    ekg->camera.lookat.x = 0;
  if (ekg->camera.lookat.x + WIDTH > ekg->map_size.x * 50)
    ekg->camera.lookat.x = ekg->map_size.x * 50 - WIDTH;
  if (ekg->camera.lookat.y + HEIGHT > ekg->map_size.y * 50)
    ekg->camera.lookat.y = ekg->map_size.y * 50 - HEIGHT;
}

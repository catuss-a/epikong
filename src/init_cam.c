/*
** init_cam.c for cam in /home/catuss_a//Desktop/epikong/etape_2
** 
** Made by axel catusse
** Login   <catuss_a@epitech.net>
** 
** Started on  Sun Mar 27 23:09:31 2011 axel catusse
** Last update Sun Mar 27 23:09:44 2011 axel catusse
*/

#include "epikong.h"

void			init_camera(t_epikong *ekg)
{
  ekg->camera.lookat.x = 0;
  ekg->camera.lookat.y = 0;
  ekg->camera.scrollspeed = 5;
}


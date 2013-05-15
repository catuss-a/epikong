/*
** main.c for epikong in /home/catuss_a//Desktop/epikong
**
** Made by axel catusse
** Login   <catuss_a@epitech.net>
**
** Started on  Sat Mar 26 01:45:28 2011 axel catusse
** Last update Sun Mar 27 23:11:02 2011 axel catusse
*/

#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <SDL/SDL.h>
#include "epikong.h"

void			start_(t_epikong *ekg)
{
  init_map(ekg);
  init_sdl(ekg);
  init_camera(ekg);
  init_game(ekg);
}

void			epikong(void)
{
  t_epikong		ekg;

  memset(&ekg, 0, sizeof(ekg));
  start_(&ekg);
  ekg.run = ekg.level;
  while (ekg.run < 6)
    {
      handles_event(&ekg);
      do_move(&ekg);
      clean_screen(&ekg);
      display_screen(&ekg);
      if (ekg.level >= 6)
	{
	  printf("GG ! End Game.\n");
	  break ;
	}
      if (ekg.run < ekg.level)
	{
	  init_camera(&ekg);
	  init_game(&ekg);
	  ekg.run += 1;
	}
      usleep(1000);
    }
}

int			main(void)
{
  epikong();
  return (0);
}

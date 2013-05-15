/*
** display.c for epikong in /home/serraj_y//Desktop/epikong
** 
** Made by younes serraj
** Login   <serraj_y@epitech.net>
** 
** Started on  Sun Mar 27 22:38:56 2011 younes serraj
** Last update Sun Mar 27 22:47:38 2011 younes serraj
*/

#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <SDL/SDL.h>
#include "epikong.h"

void			display_screen(t_epikong *ekg)
{
  display_background(ekg);
  display_object(ekg);
  display_monster(ekg);
  display_hero(ekg);
  display_life(ekg);
  SDL_Flip(ekg->sdl.ecran);
}

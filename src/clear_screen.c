/*
** clear_screen.c for  in /home/brilla_a//rendu/rush/epikong
** 
** Made by jason brillante
** Login   <brilla_a@epitech.net>
** 
** Started on  Sun Mar 27 22:42:09 2011 jason brillante
** Last update Sun Mar 27 22:52:47 2011 jason brillante
*/

#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <SDL/SDL.h>
#include "epikong.h"

void                    clean_screen(t_epikong *ekg)
{
  SDL_FillRect(ekg->sdl.ecran, NULL,
	       SDL_MapRGB(ekg->sdl.ecran->format, 0, 0, 0));
}

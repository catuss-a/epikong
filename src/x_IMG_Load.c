/*
** x_IMG_Load.c for  in /home/brilla_a//rendu/rush/epikong
** 
** Made by jason brillante
** Login   <brilla_a@epitech.net>
** 
** Started on  Sun Mar 27 22:42:27 2011 jason brillante
** Last update Sun Mar 27 22:42:40 2011 jason brillante
*/

#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <SDL/SDL.h>
#include "epikong.h"

SDL_Surface             *x_IMG_Load(char *path)
{
  SDL_Surface           *ptr;

  if ((ptr = IMG_Load(path)) == NULL)
    my_error("error: IMG_Load returns NULL.\n", DIE);
  return (ptr);
}

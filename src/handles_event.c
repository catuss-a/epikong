/*
** handles_event.c for asd in /home/catuss_a//Desktop/epikong/etape_2
** 
** Made by axel catusse
** Login   <catuss_a@epitech.net>
** 
** Started on  Sun Mar 27 23:10:09 2011 axel catusse
** Last update Sun Mar 27 23:10:20 2011 axel catusse
*/

#include "epikong.h"

void			handles_event(t_epikong *ekg)
{
  SDL_Event		event;
  SDL_Event		rdm;

  SDL_PollEvent(&event);
  while (SDL_PollEvent(&rdm))
    ;
  if (event.type == SDL_KEYDOWN)
    handles_keydown(ekg, &event);
  else if (event.type == SDL_KEYUP)
    handles_keyup(ekg, &event);
  else if (event.type == SDL_QUIT)
    ekg->run = 10;
}

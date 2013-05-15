/*
** handles_keys.c for lol in /home/catuss_a//Desktop/epikong/etape_2
** 
** Made by axel catusse
** Login   <catuss_a@epitech.net>
** 
** Started on  Sun Mar 27 23:08:45 2011 axel catusse
** Last update Sun Mar 27 23:08:56 2011 axel catusse
*/

#include "epikong.h"

void			handles_keydown(t_epikong *ekg,
					SDL_Event *event)
{
  if (event->key.keysym.sym == SDLK_ESCAPE)
      ekg->run = 10;
  if (event->key.keysym.sym == SDLK_UP)
      ekg->key.up = 1;
  if (event->key.keysym.sym == SDLK_DOWN)
      ekg->key.down = 1;
  if (event->key.keysym.sym == SDLK_RIGHT)
      ekg->key.right = 1;
  if (event->key.keysym.sym == SDLK_LEFT)
      ekg->key.left = 1;
  if (event->key.keysym.sym == SDLK_SPACE && ekg->key.space == 0)
    ekg->key.space = 1;
}

void			handles_keyup(t_epikong *ekg,
				      SDL_Event *event)
{
  switch (event->key.keysym.sym)
    {
    case SDLK_UP:
      ekg->key.up = 0;
      break;
    case SDLK_DOWN:
      ekg->key.down = 0;
      break;
    case SDLK_RIGHT:
      ekg->key.right = 0;
      break;
    case SDLK_LEFT:
      ekg->key.left = 0;
      break;
    default:
      ;
    }
}

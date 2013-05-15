/*
** map.c for  in /home/brilla_a//rendu/rush/epikong
** 
** Made by jason brillante
** Login   <brilla_a@epitech.net>
** 
** Started on  Sun Mar 27 22:39:06 2011 jason brillante
** Last update Sun Mar 27 22:43:25 2011 jason brillante
*/

#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <SDL/SDL.h>
#include "epikong.h"

static void		fill_map(t_epikong *ekg, int fd, int *len, int i)
{
  char			*line;

  if ((line = get_next_line(fd)) == NULL)
    {
      if (*len)
	{
	  ekg->allmap[i] = xmalloc(sizeof(*ekg->map) * (*len + 1));
	  ekg->map_size.y = *len;
	}
      return ;
    }
  *len += 1;
  if (*len > 5000)
    my_error("error: map too large\n", DIE);
  fill_map(ekg, fd, len, i);
  ekg->allmap[i][*len - 1] = line;
  *len -= 1;
}

void			init_map(t_epikong *ekg)
{
  int			fd;
  int			len;
  char			path[15];
  int			i;

  memset(path, 0, 15);
  printf("Welcome. Epikong EPITECH 2014.\n");
  do
    {
      printf("Choose Level : press key: 1 | 2 | 3 | 4 | 5\n");
      ekg->level = atoi(get_next_line(0));
      if (ekg->level < 1 || ekg->level > 5)
	my_error("error: invalid level\n", LIVE);
    }
  while (ekg->level < 1 || ekg->level > 5);
  for (i = ekg->level - 1; i < 5; ++i)
    {
      sprintf(path, "./map/map%d", i + 1);
      if ((fd = open(path, O_RDONLY, 0)) == -1)
	my_error("error: open\n", DIE);
      len = 0;
      fill_map(ekg, fd, &len, i);
    }
}

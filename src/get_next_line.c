/*
** get_next_line.c for epikong in /home/catuss_a//Desktop/epikong
** 
** Made by axel catusse
** Login   <catuss_a@epitech.net>
** 
** Started on  Sat Mar 26 01:56:48 2011 axel catusse
** Last update Sat Mar 26 01:58:33 2011 axel catusse
*/

#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include "epikong.h"

static char    		*line_cpy(char *str, int nb, char *buf, int *begin)
{
  int			str_len;
  char			*new_str;

  str_len = 0;
  if (str)
    {
      while (str[str_len])
	str_len += 1;
    }
  new_str = xmalloc(str_len + nb + 1);
  if (!str)
    str = "";
  strcpy(new_str, str);
  strncpy(new_str + str_len, buf + *begin, nb);
  if (strcmp(str, ""))
    free(str);
  *begin = *begin + nb + 1;
  return (new_str);
}

void			init(int *i, char **line)
{
  *i = 0;
  *line = NULL;
}

char			*get_next_line(const int fd)
{
  int			i;
  char			*line;
  static char  		buffer[BUFF_SIZE];
  static int		buff_len = 0;
  static int		begin = 0;

  init(&i, &line);
  while (1)
    {
      if (buff_len <= begin)
	{
	  if (!(buff_len = read(fd, buffer, BUFF_SIZE)) || (buff_len == -1))
	    return (line);
	  begin = 0;
	  i = 0;
	}
      if (buffer[i + begin] == '\n')
	{
	  line = line_cpy(line, i, buffer, &begin);
	  return (line);
	}
      if (begin + i == buff_len - 1)
	line = line_cpy(line, i + 1, buffer, &begin);
      i += 1;
    }
}

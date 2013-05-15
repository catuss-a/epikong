/*
** xmalloc.c for malloc in /home/catuss_a//Desktop/epikong
** 
** Made by axel catusse
** Login   <catuss_a@epitech.net>
** 
** Started on  Sat Mar 26 01:59:25 2011 axel catusse
** Last update Sat Mar 26 02:00:54 2011 axel catusse
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

void			*xmalloc(int size)
{
  void			*ptr;

  ptr = malloc(size);
  if (!ptr)
    {
      fprintf(stderr, "error: malloc\n");
      exit(0);
    }
  return (ptr);
}

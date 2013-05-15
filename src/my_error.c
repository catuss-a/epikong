/*
** my_error.c for error in /home/catuss_a//Desktop/epikong
** 
** Made by axel catusse
** Login   <catuss_a@epitech.net>
** 
** Started on  Sat Mar 26 01:50:12 2011 axel catusse
** Last update Sat Mar 26 01:51:48 2011 axel catusse
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "epikong.h"

void			my_error(char *str, char live)
{
  fprintf(stderr, str);
  if (live == DIE)
    exit(0);
}

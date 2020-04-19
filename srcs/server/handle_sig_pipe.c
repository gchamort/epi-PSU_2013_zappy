/*
** main.c for zappy in /home/chanut_g/rendu/PSU_2013_zappy/srcs/server
** 
** Made by Guillaume
** Login   <chanut_g@epitech.net>
** 
** Started on  Mon May 12 15:40:21 2014 Guillaume
** Last update Mon Jul  7 16:12:49 2014 Julien ANDRE
*/

#include "includes.h"
#include "server.h"

int                     has_closed(int val)
{
  static int            ret = 0;

  if (val != -1)
    ret = val;
  return (ret);
}

void                    handle_sig_pipe(int sig UNUSED)
{
  has_closed(1);
}

/*
** handle_ctrl_c.c for zappy in /home/chanut_g/rendu/PSU_2013_zappy/srcs/server
** 
** Made by Guillaume
** Login   <chanut_g@epitech.net>
** 
** Started on  Mon May 12 15:40:21 2014 Guillaume
** Last update Tue Jul  1 13:10:40 2014 Guillaume
*/

#include "includes.h"
#include "server.h"

static int		has_stop(int val)
{
  static int            stop = 0;

  if (val != 0)
    stop = val;
  return (stop);
}

int			get_stop(int val)
{
  return (has_stop(val));
}

void			handle_ctrl_c(int sig)
{
  (void)sig;
  get_stop(1);
}

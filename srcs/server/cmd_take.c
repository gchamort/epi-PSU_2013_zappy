/*
** cmd_take.c for zappy in /home/chanut_g/rendu/PSU_2013_zappy/srcs/server
** 
** Made by Guillaume
** Login   <chanut_g@epitech.net>
** 
** Started on  Mon May 12 15:40:21 2014 Guillaume
** Last update Mon Jul  7 16:17:13 2014 Guillaume
*/

#include "includes.h"
#include "server.h"

int			cmd_take(t_serv *s UNUSED, t_client *c UNUSED)
{
  sprintf(c->cmd, "ko\n");
  c->len_cmd = 3;
  return (EXIT_SUCCESS);
}

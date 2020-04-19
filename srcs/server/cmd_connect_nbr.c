/*
** cmd_connect_nbr.c for zappy in /home/chanut_g/rendu/PSU_2013_zappy/srcs/server
** 
** Made by Guillaume
** Login   <chanut_g@epitech.net>
** 
** Started on  Mon May 12 15:40:21 2014 Guillaume
** Last update Mon Jul  7 16:17:13 2014 Guillaume
*/

#include "includes.h"
#include "server.h"

int			cmd_connect_nbr(t_serv *s UNUSED, t_client *c)
{
  sprintf(c->cmd, "0\n");
  c->len_cmd = 2;
  return (EXIT_SUCCESS);
}

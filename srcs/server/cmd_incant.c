/*
** cmd_incant.c for zappy in /home/chanut_g/rendu/PSU_2013_zappy/srcs/server
** 
** Made by Guillaume
** Login   <chanut_g@epitech.net>
** 
** Started on  Mon May 12 15:40:21 2014 Guillaume
** Last update Mon Jul  7 16:17:13 2014 Guillaume
*/

#include "includes.h"
#include "server.h"

int			cmd_incant(t_serv *s UNUSED, t_client *c)
{
  sprintf(c->cmd, "can't elevate niveau actuel %i\n", PERSO.level);
  c->len_cmd = strlen(c->cmd);
  return (EXIT_SUCCESS);
}

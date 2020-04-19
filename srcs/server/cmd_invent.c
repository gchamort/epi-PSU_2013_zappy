/*
** cmd_invent.c for zappy in /home/chanut_g/rendu/PSU_2013_zappy/srcs/server
** 
** Made by Guillaume
** Login   <chanut_g@epitech.net>
** 
** Started on  Mon May 12 15:40:21 2014 Guillaume
** Last update Mon Jul  7 16:17:13 2014 Guillaume
*/

#include "includes.h"
#include "server.h"

int			cmd_invent(t_serv *s UNUSED, t_client *c)
{
  printf("Client %i : inventaire\n", c->sock);
  sprintf(c->cmd, "pin %i %i %i %i %i %i %i %i %i %i\n", c->sock, PERSO.posx,
	  PERSO.posy, PERSO.bag[FOOD], PERSO.bag[1], PERSO.bag[2],
	  PERSO.bag[3], PERSO.bag[4], PERSO.bag[5], PERSO.bag[6]);
  c->len_cmd = strlen(c->cmd);
  return (EXIT_SUCCESS);
}

/*
** cmd_move.c for zappy in /home/chanut_g/rendu/PSU_2013_zappy/srcs/server
** 
** Made by Guillaume
** Login   <chanut_g@epitech.net>
** 
** Started on  Mon May 12 15:40:21 2014 Guillaume
** Last update Sun Jul 13 07:16:49 2014 Julien ANDRE
*/

#include "includes.h"
#include "server.h"

void			check_moves(t_serv *s, t_client *c)
{
  if (PERSO.orient == DOWN)
    {
      if (PERSO.posy == INFO.yworld)
	PERSO.posy = 1;
      else
	PERSO.posy++;
    }
  else if (PERSO.orient == LEFT)
    {
      if (PERSO.posx == 1)
	PERSO.posx = INFO.xworld;
      else
	PERSO.posx--;
    }
}

int			cmd_movefw(t_serv *s, t_client *c)
{
  if (PERSO.orient == UP)
    {
      if (PERSO.posy == 1)
	PERSO.posy = INFO.yworld;
      else
	PERSO.posy--;
    }
  else if (PERSO.orient == RIGHT)
    {
      if (PERSO.posx == INFO.xworld)
	PERSO.posx = 1;
      else
	PERSO.posx++;
    }
  else
    check_moves(s, c);
  printf("Client %i : avance\n", c->sock);
  sprintf(c->cmd, "ok\n");
  c->len_cmd = strlen(c->cmd);
  return (EXIT_SUCCESS);
}

int			cmd_right(t_serv *s UNUSED, t_client *c)
{
  printf("Client %i : droite\n", c->sock);
  if (PERSO.orient == LEFT)
    PERSO.orient = UP;
  else
    PERSO.orient++;
  sprintf(c->cmd, "ok\n");
  c->len_cmd = strlen(c->cmd);
  return (EXIT_SUCCESS);
}

int			cmd_left(t_serv *s UNUSED, t_client *c)
{
  printf("Client %i : gauche\n", c->sock);
  if (PERSO.orient == UP)
    PERSO.orient = LEFT;
  else
    PERSO.orient--;
  sprintf(c->cmd, "ok\n");
  c->len_cmd = strlen(c->cmd);
  return (EXIT_SUCCESS);
}

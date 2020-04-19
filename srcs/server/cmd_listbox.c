/*
** cmd_listbox.c for zappy in /home/chanut_g/rendu/PSU_2013_zappy/srcs/server
** 
** Made by Guillaume
** Login   <chanut_g@epitech.net>
** 
** Started on  Mon May 12 15:40:21 2014 Guillaume
** Last update Mon Jul  7 16:17:13 2014 Guillaume
*/

#include "includes.h"
#include "server.h"

int			cmd_list_up(t_serv *s, t_client *c, int x, int y)
{
  if (y == 1)
    sprintf(c->cmd, "{%i %i %i %i %i %i %i}\n",
	    MAP(get_id_block(s, x, INFO.yworld)).object[FOOD],
	    MAP(get_id_block(s, x, INFO.yworld)).object[1],
	    MAP(get_id_block(s, x, INFO.yworld)).object[2],
	    MAP(get_id_block(s, x, INFO.yworld)).object[3],
	    MAP(get_id_block(s, x, INFO.yworld)).object[4],
	    MAP(get_id_block(s, x, INFO.yworld)).object[5],
	    MAP(get_id_block(s, x, INFO.yworld)).object[6]);
  else
    sprintf(c->cmd, "{%i %i %i %i %i %i %i}\n",
	    MAP(get_id_block(s, x, y - 1)).object[FOOD],
	    MAP(get_id_block(s, x, y - 1)).object[1],
	    MAP(get_id_block(s, x, y - 1)).object[2],
	    MAP(get_id_block(s, x, y - 1)).object[3],
	    MAP(get_id_block(s, x, y - 1)).object[4],
	    MAP(get_id_block(s, x, y - 1)).object[5],
	    MAP(get_id_block(s, x, y - 1)).object[6]);
  c->len_cmd = strlen(c->cmd);
  return (EXIT_SUCCESS);
}

int			cmd_list_right(t_serv *s, t_client *c, int x, int y)
{
  if ((unsigned int)x == INFO.xworld)
    sprintf(c->cmd, "{%i %i %i %i %i %i %i}\n",
	    MAP(get_id_block(s, 1, y)).object[FOOD],
	    MAP(get_id_block(s, 1, y)).object[1],
	    MAP(get_id_block(s, 1, y)).object[2],
	    MAP(get_id_block(s, 1, y)).object[3],
	    MAP(get_id_block(s, 1, y)).object[4],
	    MAP(get_id_block(s, 1, y)).object[5],
	    MAP(get_id_block(s, 1, y)).object[6]);
  else
    sprintf(c->cmd, "{%i %i %i %i %i %i %i}\n",
	    MAP(get_id_block(s, x + 1, y)).object[FOOD],
	    MAP(get_id_block(s, x + 1, y)).object[1],
	    MAP(get_id_block(s, x + 1, y)).object[2],
	    MAP(get_id_block(s, x + 1, y)).object[3],
	    MAP(get_id_block(s, x + 1, y)).object[4],
	    MAP(get_id_block(s, x + 1, y)).object[5],
	    MAP(get_id_block(s, x + 1, y)).object[6]);
  c->len_cmd = strlen(c->cmd);
  return (EXIT_SUCCESS);
}

int			cmd_list_down(t_serv *s, t_client *c, int x, int y)
{
  if ((unsigned int)y == INFO.yworld)
    sprintf(c->cmd, "{%i %i %i %i %i %i %i}\n",
	    MAP(get_id_block(s, x, 1)).object[FOOD],
	    MAP(get_id_block(s, x, 1)).object[1],
	    MAP(get_id_block(s, x, 1)).object[2],
	    MAP(get_id_block(s, x, 1)).object[3],
	    MAP(get_id_block(s, x, 1)).object[4],
	    MAP(get_id_block(s, x, 1)).object[5],
	    MAP(get_id_block(s, x, 1)).object[6]);
  else
    sprintf(c->cmd, "{%i %i %i %i %i %i %i}\n",
	    MAP(get_id_block(s, x, y + 1)).object[FOOD],
	    MAP(get_id_block(s, x, y + 1)).object[1],
	    MAP(get_id_block(s, x, y + 1)).object[2],
	    MAP(get_id_block(s, x, y + 1)).object[3],
	    MAP(get_id_block(s, x, y + 1)).object[4],
	    MAP(get_id_block(s, x, y + 1)).object[5],
	    MAP(get_id_block(s, x, y + 1)).object[6]);
  c->len_cmd = strlen(c->cmd);
  return (EXIT_SUCCESS);
}

int			cmd_list_left(t_serv *s, t_client *c, int x, int y)
{
  if (x == 1)
    sprintf(c->cmd, "{%i %i %i %i %i %i %i}\n",
	    MAP(get_id_block(s, INFO.xworld, y)).object[FOOD],
	    MAP(get_id_block(s, INFO.xworld, y)).object[1],
	    MAP(get_id_block(s, INFO.xworld, y)).object[2],
	    MAP(get_id_block(s, INFO.xworld, y)).object[3],
	    MAP(get_id_block(s, INFO.xworld, y)).object[4],
	    MAP(get_id_block(s, INFO.xworld, y)).object[5],
	    MAP(get_id_block(s, INFO.xworld, y)).object[6]);
  else
    sprintf(c->cmd, "{%i %i %i %i %i %i %i}\n",
	    MAP(get_id_block(s, x - 1, y)).object[FOOD],
	    MAP(get_id_block(s, x - 1, y)).object[1],
	    MAP(get_id_block(s, x - 1, y)).object[2],
	    MAP(get_id_block(s, x - 1, y)).object[3],
	    MAP(get_id_block(s, x - 1, y)).object[4],
	    MAP(get_id_block(s, x - 1, y)).object[5],
	    MAP(get_id_block(s, x - 1, y)).object[6]);
  c->len_cmd = strlen(c->cmd);
  return (EXIT_SUCCESS);
}

static int (*g_seeFctPtr[4])(t_serv *, t_client *, int, int) =
{
  &cmd_list_up,
  &cmd_list_right,
  &cmd_list_down,
  &cmd_list_left
};

int			cmd_listbox(t_serv *s, t_client *c)
{
  (*g_seeFctPtr[PERSO.orient])(s, c, PERSO.posx, PERSO.posy);
  return (EXIT_SUCCESS);
}

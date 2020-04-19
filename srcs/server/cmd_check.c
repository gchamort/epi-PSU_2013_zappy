/*
** cmd_check.c for zappy in /home/andre_j/Project/SysUnix/PSU_2013_zappy/srcs/server
** 
** Made by Julien ANDRE
** Login   <andre_j@epitech.net>
** 
** Started on  Sun Jul 13 02:39:01 2014 Julien ANDRE
** Last update Sun Jul 13 07:07:10 2014 Julien ANDRE
*/

#include	"includes.h"
#include	"server.h"

static t_cmd	g_tab[NBR_ACTIONS] =
  {
    {&cmd_movefw, "avance\n"},
    {&cmd_right, "droite\n"},
    {&cmd_left, "gauche\n"},
    {&cmd_see, "voir\n"},
    {&cmd_invent, "inventaire\n"},
    {&cmd_take, "prendre objet\n"},
    {&cmd_drop, "pose objet\n"},
    {&cmd_broadcast, "broadcast text\n"},
    {&cmd_expulse, "expulse\n"},
    {&cmd_connect_nbr, "connect_nbr\n"},
    {&cmd_incant, "incantation\n"},
    {&cmd_fork, "fork\n"}
  };

func_ptr	is_cmd(char *cmd)
{
  int		count;

  count = 0;
  while (count != NBR_ACTIONS)
    {
      if (strcmp(g_tab[count].cmd, cmd) == 0)
	return (g_tab[count].ptr);
      ++count;
    }
  return (&check_team);
}

int		check_team(t_serv *serv , t_client *client)
{
  int		count;

  count = 0;
  while (serv->info.teamnames != NULL && count != serv->info.nbrteam)
    {
      if (strcmp(client->cmd, serv->info.teamnames[count].teamname) == 0)
	final_connec(serv, client, count);
      ++count;
    }
  return (DONE);
}

int		final_connec(t_serv *serv, t_client *client, int pos)
{
  memset(client->cmd, 0, client->len_cmd);
  client->len_cmd = 0;
  client->team = pos;
  --serv->info.teamnames[pos].teamplace;
  client->buffer.len += sprintf(client->buffer.offset,
	  "%d\n%d %d\n", serv->info.teamnames[pos].teamplace,
				serv->info.xworld, serv->info.yworld);
  client->buffer.offset += client->buffer.len * sizeof(char);
  return (DONE);
}

/*
** manage_clients.c for zappy in /home/andre_j/Project/SysUnix/PSU_2013_zappy
** 
** Made by Julien ANDRE
** Login   <andre_j@epitech.net>
** 
** Started on  Mon Jun 30 15:07:34 2014 Julien ANDRE
** Last update Sun Jul 13 06:47:21 2014 Julien ANDRE
*/

#include		<stdio.h>
#include		<stdlib.h>
#include		"server.h"

int			spawn(t_client *c, t_serv *serv)
{
  PERSO.orient = UP;
  PERSO.posx = rand() % serv->info.xworld;
  PERSO.posy = rand() % serv->info.yworld;
  memset(PERSO.bag, 0, 7 * sizeof(int));
  return (DONE);
}

t_client		*new_client(int s_sock)
{
  t_client		*new;

  if ((new = malloc(sizeof(*new))) == NULL)
    new_client(s_sock);
  if ((new->sock = accept(s_sock, NULL, NULL)) == -1)
    {
      free(new);
      new = NULL;
      return (new);
    }
  if ((new->buffer.buffer = malloc(sizeof(char) * BUFFER_SIZE)) == NULL)
    new_client(s_sock);
  memset(new->buffer.buffer, 0, BUFFER_SIZE);
  new->buffer.offset = new->buffer.buffer;
  new->buffer.len = 0;
  new->cmd = malloc(sizeof(*new->cmd) * PACKET_SIZE);
  memset(new->cmd, 0, PACKET_SIZE);
  new->len_cmd = 0;
  new->next = NULL;
  new->prev = NULL;
  new->up = TRUE;
  new->team = -1;
  return (new);
}

int			add_client(t_serv *serv)
{
  t_client		*new;

  if (FD_ISSET(serv->connec.s_sock, &serv->connec.rfd) &&
     list_size(serv->clients) < (serv->info.nbrteam * serv->info.clientbyteam))
    {
      new = new_client(serv->connec.s_sock);
      if (new != NULL)
	{
	  spawn(new, serv);
	  new->next = serv->clients;
	  if (serv->clients != NULL)
	    serv->clients->prev = new;
	  serv->clients = new;
	  new->buffer.len += sprintf(new->buffer.offset, WELCOME);
	  new->buffer.offset += new->buffer.len * sizeof(char);
	  printf("client connected on sock %d\n", new->sock);
	}
      feed_map(serv);
    }
  return (DONE);
}

unsigned int		list_size(t_client *clients)
{
  int			res;
  t_client		*tmp;

  res = 0;
  tmp = clients;
  while (tmp != NULL)
    {
      ++res;
      tmp = tmp->next;
    }
  return (res);
}

int			rm_client(t_client **clients, t_client *to_rm)
{
  close(to_rm->sock);
  free(to_rm->cmd);
  free(to_rm->buffer.buffer);
  if (to_rm->next != NULL)
    to_rm->next->prev = to_rm->prev;
  if (to_rm->prev != NULL)
    to_rm->prev->next = to_rm->next;
  if (to_rm->prev == NULL)
    *clients = to_rm->next;
  printf("client %d deconnected.\n", to_rm->sock);
  free(to_rm);
  return (DONE);
}

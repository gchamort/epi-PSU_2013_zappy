/*
** manage_fd.c for exam in /home/andre_j/Project/SysUnix/PSU_2013_zappy/srcs/server
** 
** Made by Julien ANDRE
** Login   <andre_j@epitech.net>
** 
** Started on  Thu Jul  3 16:26:51 2014 Julien ANDRE
** Last update Sun Jul 13 06:44:57 2014 Julien ANDRE
*/

#include	<stdio.h>
#include	"server.h"

int		down_client(t_client **tmp, t_client **clients)
{
  t_client	*save;

  save = (*tmp)->next;
  rm_client(clients, *tmp);
  *tmp = save;
  return (DONE);
}

int		wr_set(t_serv *serv)
{
  t_client	*tmp;

  tmp = serv->clients;
  FD_ZERO(&serv->connec.rfd);
  FD_ZERO(&serv->connec.wfd);
  FD_SET(serv->connec.s_sock, &serv->connec.rfd);
  while (tmp != NULL)
    {
      if (tmp->up == FALSE)
	down_client(&tmp, &serv->clients);
      else
	{
	  FD_SET(tmp->sock, &serv->connec.rfd);
	  if (*tmp->cmd != 0)
	    {
	      FD_SET(tmp->sock, &serv->connec.wfd);
	      serv->connec.flag = TRUE;
	    }
	  tmp = tmp->next;
	}
    }
  return (DONE);
}

int		check_fd(t_serv *serv)
{
  t_client	*tmp;

  tmp = serv->clients;
  while (tmp != NULL)
    {
      if (FD_ISSET(tmp->sock, &serv->connec.rfd))
	read_on_socket(tmp);
      if (FD_ISSET(tmp->sock, &serv->connec.wfd))
	write_on_socket(tmp);
      tmp = tmp->next;
    }
  return (DONE);
}

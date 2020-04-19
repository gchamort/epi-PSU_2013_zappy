/*
** server.c for zappy in /home/chanut_g/rendu/PSU_2013_zappy/srcs/server
** 
** Made by Guillaume
** Login   <chanut_g@epitech.net>
** 
** Started on  Mon May 12 15:43:31 2014 Guillaume
** Last update Sun Jul 13 07:09:33 2014 Julien ANDRE
*/

#include <signal.h>

#include "includes.h"
#include "server.h"

int			get_nfds(t_serv *serv)
{
  int			nfds;
  t_client		*tmp;

  tmp = serv->clients;
  nfds = serv->connec.s_sock;
  while (tmp != NULL)
    {
      if (tmp->sock > nfds)
	nfds = tmp->sock;
      tmp = tmp->next;
    }
  return (nfds + 1);
}

int			server_select(t_serv *serv)
{
  signal(SIGINT, handle_ctrl_c);
  signal(SIGTERM, handle_ctrl_c);
  signal(SIGPIPE, handle_sig_pipe);
  init_map(serv);
  while (get_stop(0) == 0)
    {
      serv->timer.tv.tv_sec = 1;
      serv->timer.tv.tv_usec = 0;
      serv->connec.flag = FALSE;
      wr_set(serv);
      if (select(get_nfds(serv), &serv->connec.rfd,
		 serv->connec.flag == TRUE ? &serv->connec.wfd : NULL,
		 NULL, &serv->timer.tv) == -1)
	return (get_stop(1));
      else
	{
	  add_client(serv);
	  check_fd(serv);
	  get_cmd(serv);
	  analyse_cmd(serv->clients);
	  execute_cmd(serv);
	}
    }
  free_map(serv);
  return (0);
}

int			server_init(t_serv* serv)
{
  struct sockaddr_in	server;

  if ((serv->connec.s_sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) == -1)
    return (ERR_CONNEC);
  server.sin_family = AF_INET;
  server.sin_port = htons(serv->info.portnb);
  server.sin_addr.s_addr = INADDR_ANY;
  if (bind(serv->connec.s_sock,
	   (const struct sockaddr *)(&server), sizeof(server)) == -1 ||
      listen(serv->connec.s_sock, QUEUE) == -1)
    return (ERR_CONNEC);
  hw(serv->info.portnb);
  return (server_select(serv));
}

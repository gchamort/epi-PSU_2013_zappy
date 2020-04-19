/*
** wr_on_socket.c for zappy in /home/andre_j/Project/SysUnix/PSU_2013_zappy/srcs/server
** 
** Made by Julien ANDRE
** Login   <andre_j@epitech.net>
** 
** Started on  Thu Jul  3 16:59:26 2014 Julien ANDRE
** Last update Sun Jul 13 07:11:51 2014 Julien ANDRE
*/

#include	<stdio.h>
#include	"server.h"

int		write_on_socket(t_client *client)
{
  write(client->sock, client->cmd, client->len_cmd);
  memset(client->cmd, 0, client->len_cmd + 1);
  client->len_cmd = 0;
  return (DONE);
}

int		read_on_socket(t_client *client)
{
  client->len_cmd = read(client->sock, client->cmd, PACKET_SIZE);
  if (client->len_cmd <= 0)
    client->up = FALSE;
  return (DONE);
}

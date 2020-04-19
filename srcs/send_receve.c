/*
** server.c for zappy in /home/chanut_g/rendu/PSU_2013_zappy/srcs/server
** 
** Made by Guillaume
** Login   <chanut_g@epitech.net>
** 
** Started on  Mon May 12 15:43:31 2014 Guillaume
** Last update Mon May 12 15:43:33 2014 Guillaume
*/

#include "includes.h"
#include "server.h"

int			send_data(char *data, size_t size, int fd)
{
  int			len;
  int			sent;

  len = 0;
  while ((sent = write(fd, data, size - len)) < (int)(size) - len)
    {
      if (sent <= 0)
	return (reterror(EXIT_FAILURE, ERR_WRITE));
      len += sent;
    }
  return (EXIT_SUCCESS);
}

char			*receve_data(size_t size, int fd)
{
  char			*data;

  if ((data = malloc(size + 1)) == NULL)
    return (retnullerror(ERR_MALLOC));
  memset(data, 0, size + 1);
  if (read(fd, data, size) <= 0)
    return (retnullerror(ERR_READ));
  return (data);
}

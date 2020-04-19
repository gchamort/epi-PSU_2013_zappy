/*
** init_client.c for  in /home/bourma_m/Projets/SystemUnix/PSU_2013_zappy
** 
** Made by Mathieu Bourmaud
** Login   <bourma_m@epitech.net>
** 
** Started on  Tue Jun 24 14:23:39 2014 Mathieu Bourmaud
** Last update Sun Jul 13 18:02:22 2014 Mathieu Bourmaud
*/

#include		"includes.h"
#include		"client.h"

int			init_client(t_client client)
{
  struct protoent	*proto;
  struct sockaddr_in	sin;

  if ((proto = getprotobyname("TCP")) == NULL)
    {
      write(2, RED ERR_GETPROTO COLOR_END, strlen(RED ERR_GETPROTO COLOR_END));
      return (EXIT_FAILURE);
    }
  if ((client.socket = socket(AF_INET, SOCK_STREAM, proto->p_proto)) == -1)
    {
      write(2, ERR_SOCKET, strlen(ERR_SOCKET));
      return (EXIT_FAILURE);
    }
  sin.sin_family = AF_INET;
  sin.sin_port = htons(client.port);
  sin.sin_addr.s_addr = inet_addr(client.machine);
  if ((client.cs = connect(client.socket, (const struct sockaddr *)&(sin),
			   sizeof(sin))) == -1)
    {
      write_to(2,  RED ERR_CONNECT COLOR_END);
      return (EXIT_FAILURE);
    }
  do_client(client);
  return (EXIT_SUCCESS);
}

int		getNum(char *buff)
{
  int		val;
  int		i;
  char		*value;

  val = 0;
  i = 0;
  if ((value = malloc(sizeof(char) * 4096)) == NULL)
    return (reterror(EXIT_FAILURE, RED ERR_MALLOC COLOR_END));
  while (buff[i] != ':')
    i++;
  i++;
  while (buff[i])
    {
      strcat(value, &buff[i]);
      i++;
    }
  val = atoi(value);
  return (val);
}

int		start(t_client client)
{
  char		*buff;

  if ((buff = malloc(sizeof(char) * 4096)) == NULL)
    return (reterror(EXIT_FAILURE, RED ERR_MALLOC COLOR_END));
  if (FD_ISSET(client.socket, &(client.fread)))
    {
      bzero(buff, 4096);
      read(client.socket, buff, 4096);
      write(1, buff, 4096);
    }
  return (EXIT_SUCCESS);
}

int             do_client(t_client client)
{
  char		*buff;

  if ((buff = malloc(sizeof(char) * 4096)) == NULL)
    return (reterror(EXIT_FAILURE, RED ERR_MALLOC COLOR_END));
  FD_ZERO(&(client.fread));
  FD_SET(0, &(client.fread));
  FD_SET(client.socket, &(client.fread));
  if (select(client.socket + 1, &(client.fread), NULL, NULL, NULL) == -1)
    return (reterror(EXIT_FAILURE, RED ERR_SELECT COLOR_END));
  start(client);
  write_to(client.socket, strcat(client.team, "\n"));
  start(client);
  start(client);
  while (1)
    {
      if (IAmain(&client) == EXIT_FAILURE)
  	return (reterror(EXIT_FAILURE, RED ERR_IA COLOR_END));
    }
  free(buff);
  return (0);
}

int			helpTo(char *buff)
{
  int			i;

  i = 0;
  while (buff[i])
    {
      if (buff[i] == 'd' && buff[i + 1] == 'i')
	return (42);
      i++;
    }
  return (EXIT_SUCCESS);
}

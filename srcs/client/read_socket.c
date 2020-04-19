/*
** read_socket.c for  in /home/bourma_m/Projets/SystemUnix/TeddyZappy
** 
** Made by Mathieu Bourmaud
** Login   <bourma_m@epitech.net>
** 
** Started on  Sun Jul 13 16:24:14 2014 Mathieu Bourmaud
** Last update Sun Jul 13 18:02:47 2014 Mathieu Bourmaud
*/

#include	"includes.h"
#include	"client.h"

int		parse_readsocket(char *buff)
{
  int		i;

  i = 0;
  while (buff[i])
    {
      if (buff[i] == 'J' && buff[i + 1] == 'a')
	return (1);
      if (buff[i] == 'O' && buff[i + 1] == 'k')
	return (2);
      i++;
    }
  return (0);
}

char		*read_socket(t_client *client)
{
  char		*buff;
  int		i;
  char		nb[10];

  i = 0;
  sprintf(nb, "%d", client->nb);
  if ((buff = malloc(sizeof(char) * 4096)) == NULL)
    return (NULL);
  while (i == 0)
    {
      if (FD_ISSET(client->socket, &(client->fread)))
	{
	  bzero(buff, 4096);
	  read(client->socket, buff, 4096);
    	  if (buff[0] == 'm' && buff[1] == 'e' &&
	      buff[2] == 's' && buff[3] == 's')
    	    call_fdisset(nb, buff, client);
	  else
	    i = 1;
	}
    }
  return (buff);
}

char		*read_socket_incant(t_client *client)
{
  char		*buff;
  int		i;
  char		nb[10];

  i = 0;
  sprintf(nb, "%d", client->nb);
  if ((buff = malloc(sizeof(char) * 4096)) == NULL)
    return (NULL);
  while (i == 0)
    if (FD_ISSET(client->socket, &(client->fread)))
      {
	bzero(buff, 4096);
	read(client->socket, buff, 4096);
	if (buff[0] == 'm' && buff[1] == 'e' && buff[2] == 's' && buff[3] == 's')
	  call_fdisset2(nb, buff, client);
	else
	  i = 1;
      }
  return (buff);
}

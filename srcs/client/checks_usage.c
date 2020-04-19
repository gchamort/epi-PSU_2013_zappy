/*
** checks_usage.c for $ in /home/bourma_m/Projets/SystemUnix/PSU_2013_zappy
** 
** Made by Mathieu Bourmaud
** Login   <bourma_m@epitech.net>
** 
** Started on  Tue Jun 24 14:19:19 2014 Mathieu Bourmaud
** Last update Sun Jul 13 17:51:49 2014 Mathieu Bourmaud
*/

#include		"includes.h"
#include		"client.h"

int			check_port(char *port)
{
  char			*good;
  int			i;
  int			j;
  size_t		occ;

  good = "0123456789";
  i = 0;
  occ = 0;
  while (port[i])
    {
      j = 0;
      while (good[j])
	{
	  if (port[i] == good[j])
	    occ++;
	  j++;
	}
      i++;
    }
  if (occ != strlen(port))
    return (reterror(EXIT_FAILURE, RED BAD_PORT COLOR_END));
  return (EXIT_SUCCESS);
}

int			check_usage(char *team, char *port, char *machine)
{
  t_client		*client;

  if ((client = malloc(sizeof(*client))) == NULL)
    return (reterror(EXIT_FAILURE, RED ERR_MALLOC COLOR_END));
  if (check_port(port) != EXIT_SUCCESS)
    return (reterror(EXIT_FAILURE, RED BAD_FLAGS COLOR_END));
  else
    {
     client->nb = rand() % 10000;
      client->team = team;
      client->port = atoi(port);
      client->machine = machine;
      init_elevation(client, 1);
      init_tab(client);
      client->level = 1;
      client->isHelping = 0;
      init_client(*client);
    }
  return (EXIT_SUCCESS);
}

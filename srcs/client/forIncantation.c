/*
** forIncantation.c for  in /home/bourma_m/Projets/SystemUnix/TeddyZappy
** 
** Made by Mathieu Bourmaud
** Login   <bourma_m@epitech.net>
** 
** Started on  Sun Jul 13 16:00:13 2014 Mathieu Bourmaud
** Last update Sun Jul 13 17:49:23 2014 Mathieu Bourmaud
*/

#include		"includes.h"
#include		"client.h"

int			empty_case(t_client *client)
{
  char			*buff;
  char			*cmd[6];
  int			i;

  i = 0;
  if ((buff = malloc(sizeof(char) * 4096)) == NULL)
    return (reterror(EXIT_FAILURE, RED ERR_MALLOC COLOR_END));
  cmd[0] = "prend linemate\n";
  cmd[1] = "prend deraumere\n";
  cmd[2] = "prend sibur\n";
  cmd[3] = "prend mendiane\n";
  cmd[4] = "prend phiras\n";
  cmd[5] = "prend thystame\n";
  while (i < 6)
    {
      write_to(client->socket, cmd[i]);
      buff = read_socket(client);
      if (strcmp(buff, "ko\n") == 0)
	i++;
      else
	client->myJewel[i]++;
      bzero(buff, 4096);
    }
  return (EXIT_SUCCESS);
}

int			count_player(t_client client)
{
  int			nb_player;
  char			*buff;
  int			i;

  i = 0;
  nb_player = 0;
  if ((buff = malloc(sizeof(char) * 4096)) == NULL)
    return (reterror(EXIT_FAILURE, RED ERR_MALLOC COLOR_END));
  write_to(client.socket, "voir\n");
  buff = read_socket(&client);
  if (buff[0] == 'o' || buff[0] == 'k')
    return (0);
  while (buff[i] != ',')
    {
      if (buff[i] == 'j' && buff[i + 1] == 'o')
	nb_player++;
      i++;
    }
  return (nb_player);
}

int			incantation(t_client *client)
{
  char			*buff;
  int			i;

  client->nb_player = count_player(*client);
  if ((buff = malloc(sizeof(char) * 4096)) == NULL)
    return (reterror(EXIT_FAILURE, RED ERR_MALLOC COLOR_END));
  bzero(buff, 4096);
  broadcastLoops(client, buff);
  i = 0;
  while (i < 6)
    {
      drop_jewels(client, i);
      i++;
    }
  bzero(buff, 4096);
  startIncantation(client, buff);
  return (EXIT_SUCCESS);
}

void			startIncantation(t_client *client, char *buff)
{
  write_to(client->socket, "incantation\n");
  buff = read_socket(client);
  if (strcmp(buff, "elevation en cours\n") == 0)
    {
      bzero(buff, 4096);
      buff = read_socket(client);
      if (strcmp("ko\n", buff) != 0)
	{
	  client->level++;
	  init_elevation(client, client->level);
	  client->isHelping = 0;
	}
    }
}

int			drop_jewels(t_client *client, int nb)
{
  char			*buff;
  char			*cmd;
  int			i;

  i = 0;
  if ((buff = malloc(sizeof(char) * 4096)) == NULL)
    return (reterror(EXIT_FAILURE, RED ERR_MALLOC COLOR_END));
  if ((cmd = malloc(sizeof(char) * 4096)) == NULL)
    return (reterror(EXIT_FAILURE, RED ERR_MALLOC COLOR_END));
  bzero(buff, 4096);
  bzero(cmd, 4096);
  while (i < client->jewel_req[nb])
    {
      bzero(buff, 4096);
      strcpy(cmd, "pose ");
      strcat(cmd, getJewel(nb));
      write_to(client->socket, cmd);
      buff = read_socket(client);
      client->myJewel[nb]--;
      i++;
    }
  free(buff);
  return (EXIT_SUCCESS);
}

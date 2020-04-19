/*
** IATeam.c for  in /home/bourma_m/Projets/SystemUnix/TeddyZappy
**
** Made by Mathieu Bourmaud
** Login   <bourma_m@epitech.net>
**
** Started on  Thu Jun 26 16:22:33 2014 Mathieu Bourmaud
** Last update Sun Jul 13 17:49:07 2014 Mathieu Bourmaud
*/

#include		"includes.h"
#include		"client.h"

int			IAGetTeam(t_client client)
{
  if (isEnoughTrantoriens(client) != EXIT_SUCCESS)
    {
      askTeam(client);
    }
  return (EXIT_SUCCESS);
}

int			isEnoughTrantoriens(t_client client)
{
  (void)client;
  return (EXIT_FAILURE);
}

int			askTeam(t_client client)
{
  char			*buff;
  char			*broadcast;
  char			level[2];
  char			players[2];

  sprintf(level, "%d", client.level);
  sprintf(players, "%d", client.player_req - 1);
  if ((buff = malloc(sizeof(char) * 4096)) == NULL)
    return (reterror(EXIT_FAILURE, RED ERR_MALLOC COLOR_END));
  if ((broadcast = malloc(sizeof(char) * 17)) == NULL)
    return (reterror(EXIT_FAILURE, RED ERR_MALLOC COLOR_END));
  bzero(buff, 4096);
  strcpy(broadcast, "broadcast ");
  strcat(broadcast, level);
  strcat(broadcast, ",");
  strcat(broadcast, players);
  strcat(broadcast, "\n");
  write_to(client.socket, broadcast);
  buff = read_socket(&client);
  return (EXIT_SUCCESS);
}

char			*getJewel(int nb)
{
  if (nb == 0)
    return ("linemate\n");
  if (nb == 1)
    return ("deraumere\n");
  if (nb == 2)
    return ("sibur\n");
  if (nb == 3)
    return ("mendiane\n");
  if (nb == 4)
    return ("phiras\n");
  if (nb == 5)
    return ("thystame\n");
  return (NULL);
}

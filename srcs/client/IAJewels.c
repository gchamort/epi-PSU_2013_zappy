/*
** IAJewels.c for  in /home/bourma_m/Projets/SystemUnix/TeddyZappy
** 
** Made by Mathieu Bourmaud
** Login   <bourma_m@epitech.net>
** 
** Started on  Thu Jun 26 16:10:37 2014 Mathieu Bourmaud
** Last update Wed Jul  9 17:32:04 2014 Mathieu Bourmaud
*/

#include		"includes.h"
#include		"client.h"

int			IAGetJewels(t_client *client)
{
  int			pos;
  char			*buff;
  int			type;

  pos = 0;
  type = check_tab(client);
  if ((buff = malloc(sizeof(char) * 4096)) == NULL)
    return (reterror(EXIT_FAILURE, RED ERR_MALLOC COLOR_END));
  if (isEnoughJewels(*client) != EXIT_SUCCESS)
    {
      if (isJewelHere(*client) != EXIT_SUCCESS)
	{
	  pos = getPos(*client, client->JewelToGet);
	  moveTo(*client, buff, pos);
	}
      else
	takeJewel(client, type);
      return (EXIT_FAILURE);
    }
  return (EXIT_SUCCESS);
}

int			move(t_client client)
{
  char			*buff;

  if ((buff = malloc(sizeof(char) * 4096)) == NULL)
    return (reterror(EXIT_FAILURE, RED ERR_MALLOC COLOR_END));
  write_to(client.socket, "avance\n");
  buff = read_socket(&client);
  return (EXIT_SUCCESS);
}

int			takeJewel(t_client *client, int type)
{
  char			*buff;
  char			*cmd;

  if ((buff = malloc(sizeof(char) * 4096)) == NULL)
    return (reterror(EXIT_FAILURE, RED ERR_MALLOC COLOR_END));
  if ((cmd = malloc(sizeof(char) * (strlen(client->JewelToGet)
				    + strlen("prend ") + 1))) == NULL)
    return (reterror(EXIT_FAILURE, RED ERR_MALLOC COLOR_END));
  strcpy(cmd, "prend ");
  strcat(cmd, client->JewelToGet);
  write_to(client->socket, cmd);
  buff = read_socket(client);
  if (strcmp(buff, "ok\n") == 0)
    client->myJewel[type]++;
  return (EXIT_SUCCESS);
}

int			isJewelHere(t_client client)
{
  int			jewel_pos;

  if ((jewel_pos = getPos(client, client.JewelToGet)) != 0)
    return (reterror(EXIT_FAILURE, RED NOJEWEL_HERE COLOR_END));
  return (EXIT_SUCCESS);
}

int			isEnoughJewels(t_client client)
{
  if (compare_tab(client) != EXIT_SUCCESS)
    return (EXIT_FAILURE);
  return (EXIT_SUCCESS);
}

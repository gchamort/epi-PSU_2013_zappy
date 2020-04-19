/*
** IAFood.c for  in /home/bourma_m/Projets/SystemUnix/TeddyZappy
**
** Made by Mathieu Bourmaud
** Login   <bourma_m@epitech.net>
**
** Started on  Thu Jun 26 15:35:36 2014 Mathieu Bourmaud
** Last update Sun Jul 13 17:53:07 2014 Mathieu Bourmaud
*/

#include		"includes.h"
#include		"client.h"

int			IAGetFood(t_client client)
{
  int			pos;
  char			*buff;

  if ((buff = malloc(sizeof(char) * 4096)) == NULL)
    return (reterror(EXIT_FAILURE, RED ERR_MALLOC COLOR_END));
  pos = 0;
  if (isEnoughFood(client) != EXIT_SUCCESS)
    {
      if (isFoodHere(client) != EXIT_SUCCESS)
	{
	  pos = getPos(client, "nourriture");
	  moveTo(client, buff, pos);
	}
      else
	takeFood(client);
      return (EXIT_FAILURE);
    }
  return (EXIT_SUCCESS);
}

int			avance(t_client client)
{
  char			*buff;

  if ((buff = malloc(sizeof(char) * 4096)) == NULL)
    return (reterror(EXIT_FAILURE, RED ERR_MALLOC COLOR_END));
  write_to(client.socket, "avance\n");
  buff = read_socket(&client);
  return (EXIT_SUCCESS);
}

int			takeFood(t_client client)
{
  char			*buff;

  if ((buff = malloc(sizeof(char) * 4096)) == NULL)
    return (reterror(EXIT_FAILURE, RED ERR_MALLOC COLOR_END));
  write_to(client.socket, "prend nourriture\n");
  buff = read_socket(&client);
  return (EXIT_SUCCESS);
}

int			isFoodHere(t_client client)
{
  int			food_pos;

  if ((food_pos = getPos(client, "nourriture")) != 0)
    return (reterror(EXIT_FAILURE, RED NOFOOD_HERE COLOR_END));
  return (EXIT_SUCCESS);
}

int			isEnoughFood(t_client client)
{
  char			*buff;

  if ((buff = malloc(sizeof(char) * 4096)) == NULL)
    return (reterror(EXIT_FAILURE, RED ERR_MALLOC COLOR_END));
  write_to(client.socket, "inventaire\n");
  buff = read_socket(&client);
  if (buff[0] == '{' && getFoodValue(buff) < 7)
    return (EXIT_FAILURE);
  return (EXIT_SUCCESS);
}

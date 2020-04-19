/*
** tabs.c for  in /home/bourma_m/Projets/SystemUnix/TeddyZappy
** 
** Made by Mathieu Bourmaud
** Login   <bourma_m@epitech.net>
** 
** Started on  Wed Jul  9 17:31:25 2014 Mathieu Bourmaud
** Last update Sun Jul 13 17:50:56 2014 Mathieu Bourmaud
*/

#include			"includes.h"
#include			"client.h"

int			check_tab(t_client *client)
{
  int			i;

  i = 0;
  while (i < 6)
    {
      if (client->jewel_req[i] > client->myJewel[i])
	{
	  if (i == 0)
	    client->JewelToGet = "linemate\n";
	  if (i == 1)
	    client->JewelToGet = "deraumere\n";
	  if (i == 2)
	    client->JewelToGet = "sibur\n";
	  if (i == 3)
	    client->JewelToGet = "mendiane\n";
	  if (i == 4)
	    client->JewelToGet = "phiras\n";
	  if (i == 5)
	    client->JewelToGet = "thystame\n";
	  return (i);
	}
      i++;
    }
  return (i);
}

int			compare_tab(t_client client)
{
  int			i;
  int			nice;

  i = 0;
  nice = 0;
  while (i < 6)
    {
      if (client.jewel_req[i] <= client.myJewel[i])
	nice++;
      i++;
    }
  if (nice != i)
    {
      write(1, RED NEAD_MORE COLOR_END, strlen(BLUE NEAD_MORE COLOR_END));
      return (EXIT_FAILURE);
    }
  return (EXIT_SUCCESS);
}

int			init_tab(t_client *client)
{
  int			i;

  i = 0;
  while (i < 6)
    {
      client->myJewel[i] = 0;
      i++;
    }
  return (EXIT_SUCCESS);
}

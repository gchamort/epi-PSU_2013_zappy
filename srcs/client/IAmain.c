/*
** IAmain.c for  in /home/bourma_m/Projets/SystemUnix/TeddyZappy
** 
** Made by Mathieu Bourmaud
** Login   <bourma_m@epitech.net>
** 
** Started on  Mon Jun 30 11:47:36 2014 Mathieu Bourmaud
** Last update Sun Jul 13 16:03:56 2014 Mathieu Bourmaud
*/

#include		"includes.h"
#include		"client.h"

int			IAmain(t_client *client)
{
  if (IAGetFood(*client) == EXIT_SUCCESS)
    {
      if (IAGetJewels(client) == EXIT_SUCCESS)
	{
	  if (empty_case(client) == EXIT_SUCCESS)
	    incantation(client);
	}
    }
  return (EXIT_SUCCESS);
}

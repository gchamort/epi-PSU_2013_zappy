/*
** main.c for zappy in /home/chanut_g/rendu/PSU_2013_zappy/srcs/client
**
** Made by Guillaume
** Login   <chanut_g@epitech.net>
**
** Started on  Mon May 12 15:22:42 2014 Guillaume
** Last update Sun Jul 13 17:51:07 2014 Mathieu Bourmaud
*/

#include		"includes.h"
#include		"client.h"

int			main(int ac, char **av)
{
  srand(time(NULL));
  if (ac != 5 && ac != 7)
    reterror(EXIT_FAILURE, RED USAGE COLOR_END);
  else if (ac == 5)
    {
      if (strcmp(av[1], "-n") != 0 || strcmp(av[3], "-p") != 0)
	reterror(EXIT_FAILURE, RED BAD_FLAGS COLOR_END);
      else
	if (check_usage(av[2], av[4], "127.0.0.1") == EXIT_FAILURE)
	  reterror(EXIT_FAILURE, RED USAGE COLOR_END);
    }
  else if (ac == 7)
    {
      if (strcmp(av[1], "-n") != 0 || strcmp(av[3], "-p") != 0
	  || strcmp(av[5], "-h") != 0)
	reterror(EXIT_FAILURE, RED BAD_FLAGS COLOR_END);
      if (check_usage(av[2], av[4], av[6]) == EXIT_FAILURE)
	reterror(EXIT_FAILURE, RED USAGE COLOR_END);
    }
  return (EXIT_SUCCESS);
}

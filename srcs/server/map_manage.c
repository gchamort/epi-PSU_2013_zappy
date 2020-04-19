/*
** map_manage.c for zappy in /home/chanut_g/rendu/PSU_2013_zappy/srcs/server
** 
** Made by Guillaume
** Login   <chanut_g@epitech.net>
** 
** Started on  Mon May 12 15:40:21 2014 Guillaume
** Last update Fri Jul  4 11:58:46 2014 Guillaume
*/

#include <time.h>
#include "includes.h"
#include "server.h"

int			init_map(t_serv *s)
{
  int			map_len;
  unsigned int		i;

  if ((s->info.xworld > 0) && (s->info.yworld > 0))
    {
      map_len = (s->info.xworld * s->info.xworld) + 1;
      if ((s->map = malloc(sizeof(t_box) * map_len)) == NULL)
	return (reterror(EXIT_FAILURE, ERR_MALLOC));
      i = 0;
      while (i < (s->info.xworld * s->info.yworld))
	{
	  s->map[i].object[FOOD] = 0;
	  s->map[i].object[LINEMATE] = 0;
	  s->map[i].object[DERAUMERE] = 0;
	  s->map[i].object[SIBUR] = 0;
	  s->map[i].object[MENDIANE] = 0;
	  s->map[i].object[PHIRAS] = 0;
	  s->map[i].object[THYSTAME] = 0;
	  ++i;
	}
    }
  else
    return (reterror(EXIT_FAILURE, ERR_SIZE_MAP));
  return (EXIT_SUCCESS);
}

int			feed_map(t_serv *s)
{
  unsigned int		i;

  i = 0;
  while (i < (s->info.xworld * s->info.yworld))
    {
      s->map[i].object[FOOD] += rand() % 2;
      s->map[i].object[LINEMATE] += rand() % 2;
      s->map[i].object[DERAUMERE] += rand() % 2;
      s->map[i].object[SIBUR] += rand() % 2;
      s->map[i].object[MENDIANE] += rand() % 2;
      s->map[i].object[PHIRAS] += rand() % 2;
      s->map[i].object[THYSTAME] += rand() % 2;
      ++i;
    }
  return (EXIT_SUCCESS);
}

int			free_map(t_serv *s)
{
  free(s->map);
  return (EXIT_SUCCESS);
}

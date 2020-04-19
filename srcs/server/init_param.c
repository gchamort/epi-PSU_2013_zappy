/*
** main.c for zappy in /home/chanut_g/rendu/PSU_2013_zappy/srcs/server
**
** Made by Guillaume
** Login   <chanut_g@epitech.net>
**
** Started on  Mon May 12 15:40:21 2014 Guillaume
** Last update Sun Jul 13 07:08:34 2014 Julien ANDRE
*/

#include "includes.h"
#include "server.h"

static t_getargs	g_getargs[NBR_OPT] =
  {
    {'p', &setport},
    {'x', &setwidth},
    {'y', &setheight},
    {'n', &setteamname},
    {'c', &setcbt},
    {'t', &setdelay}
  };

void			setteamname(t_serv *serv, int ac, char **av)
{
  int			count;
  int			nbr_team;

  --optind;
  nbr_team = 0;
  count = optind;
  while (count < ac && *av[count++] != '-')
    ++nbr_team;
   serv->info.nbrteam = nbr_team;
  if ((serv->info.teamnames =
       malloc(sizeof(*serv->info.teamnames) * (nbr_team + 1))) == NULL)
    return;
  count = optind;
  while (--nbr_team >= 0)
    {
      if ((serv->info.teamnames[nbr_team].teamname =
	   malloc(sizeof(*serv->info.teamnames[nbr_team].teamname) *
		  (strlen(av[count]) + 2))) == NULL)
	return;
      memset(serv->info.teamnames[nbr_team].teamname, 0, strlen(av[count]) + 2);
      sprintf(serv->info.teamnames[nbr_team].teamname, "%s\n", av[count]);
      ++count;
    }
}

int			init_places(t_serv *serv)
{
  int			count;

  count = 0;
  while (serv->info.teamnames != NULL && count != serv->info.nbrteam)
    {
      serv->info.teamnames[count].teamplace = serv->info.clientbyteam;
      ++count;
    }
  return (DONE);
}

int			init_param(t_serv* s, int ac, char** av)
{
  int			opt;
  int			count;

  s->info.portnb = DEF_PORT;
  s->info.xworld = DEF_XWORLD;
  s->info.yworld = DEF_YWORLD;
  s->info.clientbyteam = DEF_CBT;
  s->info.nbrteam = DEF_NBR_TEAM;
  s->info.delay = DEF_DELAY;
  s->info.teamnames = NULL;
  s->clients = NULL;
  while ((opt = getopt(ac, av, "p:x:y:n:c:t:")) != -1)
    {
      count = 0;
      while (count != NBR_OPT)
	{
	  if (g_getargs[count].opt == opt)
	    g_getargs[count].ptr(s, ac, av);
	  ++count;
	}
    }
  init_places(s);
  return (EXIT_SUCCESS);
}

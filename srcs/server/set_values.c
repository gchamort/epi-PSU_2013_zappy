/*
** set_values.c for zappy in /home/andre_j/Project/SysUnix/PSU_2013_zappy/srcs/server
** 
** Made by Julien ANDRE
** Login   <andre_j@epitech.net>
** 
** Started on  Mon Jul  7 16:14:02 2014 Julien ANDRE
** Last update Mon Jul  7 16:16:25 2014 Julien ANDRE
*/

#include	"includes.h"
#include	"server.h"

void			setport(t_serv *serv, int ac UNUSED, char **av UNUSED)
{
  serv->info.portnb = atoi(optarg);
}

void			setwidth(t_serv *serv, int ac UNUSED, char **av UNUSED)
{
  serv->info.xworld = atoi(optarg);
}

void			setheight(t_serv *serv, int ac UNUSED, char **av UNUSED)
{
  serv->info.yworld = atoi(optarg);
}

void			setcbt(t_serv *serv, int ac UNUSED, char **av UNUSED)
{
  serv->info.clientbyteam = atoi(optarg);
}

void			setdelay(t_serv *serv, int ac UNUSED, char **av UNUSED)
{
  serv->info.delay = atoi(optarg);
}

/*
** main.c for zappy in /home/chanut_g/rendu/PSU_2013_zappy/srcs/server
** 
** Made by Guillaume
** Login   <chanut_g@epitech.net>
** 
** Started on  Mon May 12 15:40:21 2014 Guillaume
** Last update Mon Jul  7 16:17:13 2014 Julien ANDRE
*/

#include "includes.h"
#include "server.h"

int			main(int ac, char **av)
{
  t_serv		serv;

  init_param(&serv, ac, av);
  return (server_init(&serv));
}

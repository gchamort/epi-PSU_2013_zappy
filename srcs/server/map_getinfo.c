/*
** map_getinfo.c for zappy in /home/chanut_g/rendu/PSU_2013_zappy/srcs/server
** 
** Made by Guillaume
** Login   <chanut_g@epitech.net>
** 
** Started on  Mon May 12 15:40:21 2014 Guillaume
** Last update Fri Jul  4 11:58:46 2014 Guillaume
*/

#include "includes.h"
#include "server.h"

int			get_id_block(t_serv *s, int x, int y)
{
  return (x + (s->info.xworld * y));
}

int			get_block_posx(t_serv *s, int id)
{
  return (id % s->info.xworld);
}

int			get_block_posy(t_serv *s, int id)
{
  return (id / s->info.xworld);
}

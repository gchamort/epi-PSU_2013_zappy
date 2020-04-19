/*
** endElevation.c for  in /home/bourma_m/Projets/SystemUnix/TeddyZappy
** 
** Made by Mathieu Bourmaud
** Login   <bourma_m@epitech.net>
** 
** Started on  Tue Jul  1 14:47:29 2014 Mathieu Bourmaud
** Last update Mon Jul  7 11:24:03 2014 Mathieu Bourmaud
*/

#include			"includes.h"
#include			"client.h"

void			elev5(t_client *client)
{
  client->player_req = 4;
  client->jewel_req[0] = 1;
  client->jewel_req[1] = 2;
  client->jewel_req[2] = 1;
  client->jewel_req[3] = 3;
  client->jewel_req[4] = 0;
  client->jewel_req[5] = 0;
}

void			elev6(t_client *client)
{
  client->player_req = 6;
  client->jewel_req[0] = 1;
  client->jewel_req[1] = 2;
  client->jewel_req[2] = 3;
  client->jewel_req[3] = 0;
  client->jewel_req[4] = 1;
  client->jewel_req[5] = 0;
}

void			elev7(t_client *client)
{
  client->player_req = 6;
  client->jewel_req[0] = 2;
  client->jewel_req[1] = 2;
  client->jewel_req[2] = 2;
  client->jewel_req[3] = 2;
  client->jewel_req[4] = 2;
  client->jewel_req[5] = 1;
}

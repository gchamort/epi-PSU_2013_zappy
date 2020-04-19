/*
** initElevation.c for  in /home/bourma_m/Projets/SystemUnix/TeddyZappy
** 
** Made by Mathieu Bourmaud
** Login   <bourma_m@epitech.net>
** 
** Started on  Tue Jul  1 14:44:57 2014 Mathieu Bourmaud
** Last update Mon Jul  7 16:28:05 2014 Mathieu Bourmaud
*/

#include			"includes.h"
#include			"client.h"

void			elev1(t_client *client)
{
  client->player_req = 1;
  client->jewel_req[0] = 1;
  client->jewel_req[1] = 0;
  client->jewel_req[2] = 0;
  client->jewel_req[3] = 0;
  client->jewel_req[4] = 0;
  client->jewel_req[5] = 0;
}

void			elev2(t_client *client)
{
  client->player_req = 2;
  client->jewel_req[0] = 1;
  client->jewel_req[1] = 1;
  client->jewel_req[2] = 1;
  client->jewel_req[3] = 0;
  client->jewel_req[4] = 0;
  client->jewel_req[5] = 0;
}

void			elev3(t_client *client)
{
  client->player_req = 2;
  client->jewel_req[0] = 2;
  client->jewel_req[1] = 0;
  client->jewel_req[2] = 1;
  client->jewel_req[3] = 0;
  client->jewel_req[4] = 2;
  client->jewel_req[5] = 0;
}

void			elev4(t_client *client)
{
  client->player_req = 4;
  client->jewel_req[0] = 1;
  client->jewel_req[1] = 1;
  client->jewel_req[2] = 2;
  client->jewel_req[3] = 0;
  client->jewel_req[4] = 1;
  client->jewel_req[5] = 0;
}

void			init_elevation(t_client *client, int elevation)
{
  if (elevation == 1)
    elev1(client);
  if (elevation == 2)
    elev2(client);
  if (elevation == 3)
    elev3(client);
  if (elevation == 4)
    elev4(client);
  if (elevation == 5)
    elev5(client);
  if (elevation == 6)
    elev6(client);
  if (elevation == 7)
    elev7(client);
}

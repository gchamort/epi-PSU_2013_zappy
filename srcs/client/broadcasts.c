/*
** broadcasts.c for  in /home/bourma_m/Projets/SystemUnix/TeddyZappy
** 
** Made by Mathieu Bourmaud
** Login   <bourma_m@epitech.net>
** 
** Started on  Sun Jul 13 16:12:48 2014 Mathieu Bourmaud
** Last update Sun Jul 13 17:52:27 2014 Mathieu Bourmaud
*/

#include		"includes.h"
#include		"client.h"

void			broadcastLoops(t_client *client, char *buff)
{
  char			level[10];

  while (client->nb_player != client->player_req)
    {
      sprintf(level, "%d", client->level);
      strcpy(buff, "broadcast ");
      strcat(buff, level);
      strcat(buff, "\n");
      write_to(client->socket, buff);
      bzero(buff, 4096);
      buff = read_socket_incant(client);
    }
  while (count_player(*client) != client->player_req)
    {
      bzero(buff, 4096);
      write_to(client->socket, "broadcast direction\n");
      read(client->socket, buff, 4096);
    }
}

int		broadcast(int fct, t_client *client, char *buff)
{
  char		*cmd;

  (void)fct;
  if ((cmd = malloc(sizeof(char) * 4096)) == NULL)
    return (reterror(EXIT_FAILURE, RED ERR_MALLOC COLOR_END));
  write_to(client->socket, buff);
  bzero(cmd, 4096);
  cmd = read_socket(client);
  return (EXIT_SUCCESS);
}

int		getPlayersVal(char *buff)
{
  int		val;
  int		i;

  i = 0;
  val = 0;
  while (buff[i] != ',')
    i++;
  i = i + 3;
  val = atoi(&buff[i]);
  return (val);
}

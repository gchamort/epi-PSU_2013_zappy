/*
** fdisset.c for  in /home/bourma_m/Projets/SystemUnix/TeddyZappy
** 
** Made by Mathieu Bourmaud
** Login   <bourma_m@epitech.net>
** 
** Started on  Sun Jul 13 16:57:44 2014 Mathieu Bourmaud
** Last update Sun Jul 13 17:53:08 2014 Mathieu Bourmaud
*/

#include	"includes.h"
#include	"client.h"

void		call_fdisset(char *nb, char *buff, t_client *client)
{
  int		fct;

  fct = parse_readsocket(buff);
  if (fct == 0)
    fdisset0(fct, nb, client);
  if (fct == 2)
    fdisset2(buff, client);
}

void		call_fdisset2(char *nb, char *buff, t_client *client)
{
  int		fct;

  fct = parse_readsocket(buff);
  if (fct == 0)
    fdisset0(fct, nb, client);
  if (fct == 1)
    fdisset1(client, buff);
}

int		fdisset0(int fct, char *nb, t_client *client)
{
  char		*cmd;

  if ((cmd = malloc(sizeof(char) * 4096)) == NULL)
    return (reterror(EXIT_FAILURE, RED ERR_MALLOC COLOR_END));
  strcpy(cmd, "broadcast Jarrive:");
  strcat(cmd, nb);
  strcat(cmd, "\n");
  broadcast(fct, client, cmd);
  return (EXIT_SUCCESS);
}

void		fdisset2(char *buff, t_client *client)
{
  if (getNum(buff) == client->nb)
    {
      client->isHelping = 1;
      while (client->isHelping == 1)
	{
	  bzero(buff, 4096);
	  read(client->socket, buff, 4096);
	  if (helpTo(buff) == 42)
	    goToFriend(client, buff);
	}
    }
}

int		fdisset1(t_client *client, char *buff)
{
  char		nb2[10];
  char		*cmd;

  if ((cmd = malloc(sizeof(char) * 4096)) == NULL)
    return (reterror(EXIT_FAILURE, RED ERR_MALLOC COLOR_END));
  if (client->nb_player != client->player_req)
    {
      sprintf(nb2, "%d", getNum(buff));
      strcpy(cmd, "broadcast Ok:");
      strcat(cmd, nb2);
      strcat(cmd, "\n");
      write_to(client->socket, cmd);
      bzero(buff, 4096);
      read(client->socket, buff, 4096);
      client->nb_player++;
    }
  return (EXIT_SUCCESS);
}

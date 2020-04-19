/*
** moves.c for  in /home/bourma_m/Projets/SystemUnix/TeddyZappy
** 
** Made by Mathieu Bourmaud
** Login   <bourma_m@epitech.net>
** 
** Started on  Wed Jul  9 17:16:08 2014 Mathieu Bourmaud
** Last update Sun Jul 13 17:44:00 2014 Mathieu Bourmaud
*/

#include		"includes.h"
#include		"client.h"

int			goTo(t_client client, char *buff, int k)
{
  if (k > 0)
    {
      write(client.socket, "droite\n", strlen("droite\n"));
      bzero(buff, 4096);
      buff = read_socket(&client);
      write(1, buff, strlen(buff));
      while (k > 0)
	{
	  avance(client);
	  k--;
	}
    }
  if (k < 0)
    {
      write(client.socket, "gauche\n", strlen("gauche\n"));
      bzero(buff, 4096);
      buff = read_socket(&client);
      write(1, buff, strlen(buff));
      while (k < 0)
	{
	  avance(client);
	  k++;
	}
    }
  return (EXIT_SUCCESS);
}

int			moveTo(t_client client, char *buff, int pos)
{
  int			i;
  int			j;
  int			cpt;
  int			tab[6] = {0, 2, 6, 12, 20};

  i = 0;
  j = 3;
  cpt = 0;
  if (pos == -1)
    {
      avance(client);
      avance(client);
      return (EXIT_SUCCESS);
    }
  while (i < pos)
    {
      i = i + j;
      j = j + 2;
      avance(client);
      cpt++;
    }
  goTo(client, buff, pos - tab[cpt]);
  return (EXIT_SUCCESS);
}

void			movestofriend(t_client *client, char *cmd, char *move)
{
  bzero(cmd, 4096);
  write_to(client->socket, move);
  read(client->socket, cmd, 4096);
}

int			goToFriend(t_client *client, char *buff)
{
  int			i;
  char			*cmd;

  i = 0;
  if ((cmd = malloc(sizeof(char *) * 4096)) == NULL)
    return (reterror(EXIT_SUCCESS, RED ERR_MALLOC COLOR_END));
  while (buff[i])
    {
      bzero(cmd, 4096);
      if (buff[i] == '2' || buff[i] == '1' || buff[i] == '8')
	movestofriend(client, cmd, "avance\n");
      else if (buff[i] == '4' || buff[i] == '5' || buff[i] == '6')
	{
	  movestofriend(client, cmd, "droite\n");
	  movestofriend(client, cmd, "droite\n");
	  movestofriend(client, cmd, "avance\n");
	}
      else if (buff[i] == '3')
	movestofriend(client, cmd, "gauche\n");
      else if (buff[i] == '7')
	movestofriend(client, cmd, "droite\n");
      i++;
    }
  free(cmd);
  return (EXIT_SUCCESS);
}

/*
** ParseData.c for  in /home/bourma_m/Projets/SystemUnix/TeddyZappy
** 
** Made by Mathieu Bourmaud
** Login   <bourma_m@epitech.net>
** 
** Started on  Mon Jun 30 14:45:48 2014 Mathieu Bourmaud
** Last update Sun Jul 13 17:56:14 2014 Mathieu Bourmaud
*/

#include		"includes.h"
#include		"client.h"

int			getPortee(int level)
{
  int			portee;

  portee = 0;
  if (level == 1)
    portee = 4;
  if (level == 2)
    portee = 9;
  if (level == 3)
    portee = 16;
  return (portee);
}

int			getFoodValue(char *buff)
{
  int			val;
  int			i;
  char			*value;

  if ((value = malloc(sizeof(char) * 4096)) == NULL)
    return (reterror(EXIT_FAILURE, RED ERR_MALLOC COLOR_END));
  i = 0;
  while (buff[i] != ' ')
    i++;
  i++;
  while (buff[i] != ',')
    {
      strcat(value, &buff[i]);
      i++;
    }
  val = atoi(value);
  return (val);
}

int			getPos(t_client client, char *type)
{
  int			i;
  int			pos;
  int			check;
  char			*buff;

  i = -1;
  pos = 0;
  check = 0;
  if ((buff = malloc(sizeof(char) * 4096)) == NULL)
    return (reterror(EXIT_FAILURE, RED ERR_MALLOC COLOR_END));
  write_to(client.socket, "voir\n");
  buff = read_socket(&client);
  if (buff[0] == '{' && buff[1] == ' ')
    while (buff[++i] && pos != -1)
      {
	if (buff[i] == ',')
	  pos++;
	if (buff[i] == type[0] && buff[i + 1] == type[1])
	  {
	    check++;
	    break;
	  }
      }
  if (check == 0)
    pos = -1;
  return (pos);
}

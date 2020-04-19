/*
** write_to.c for  in /home/bourma_m/Projets/SystemUnix/PSU_2013_zappy
** 
** Made by Mathieu Bourmaud
** Login   <bourma_m@epitech.net>
** 
** Started on  Tue Jun 24 14:32:13 2014 Mathieu Bourmaud
** Last update Tue Jun 24 14:42:13 2014 Mathieu Bourmaud
*/

#include	"includes.h"
#include	"client.h"

void		write_to(int cs, char *str)
{
  int		len;
  int		len2;

  len = strlen(str);
  len2 = write(cs, str, len);
  if (len2 != -1)
    while (len2 < len)
      len2 += write(cs, &(str[len2]), len - len2);
}

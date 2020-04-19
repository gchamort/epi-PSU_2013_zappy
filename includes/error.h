/*
** error.h for zappy in /home/chanut_g/rendu/PSU_2013_zappy/includes
** 
** Made by Guillaume
** Login   <chanut_g@epitech.net>
** 
** Started on  Mon May 12 15:44:37 2014 Guillaume
** Last update Mon Jun 30 11:07:50 2014 Julien ANDRE
*/

#ifndef		ERROR_H_
# define	ERROR_H_

# define	ERROR		"Error:"
# define	ERR_MALLOC	"Malloc failed\n"
# define	ERR_CONNEC	-1

# define	ERR_SIZE_MAP	"Cannot creat map, invalide size\n"

int		reterror(int, char *);
void		*retnullerror(char *);

#endif

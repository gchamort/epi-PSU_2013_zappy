/*
** cmd_manage.c for zappy in /home/andre_j/Project/SysUnix/PSU_2013_zappy/srcs/server
** 
** Made by Julien ANDRE
** Login   <andre_j@epitech.net>
** 
** Started on  Sat Jul  5 14:15:20 2014 Julien ANDRE
** Last update Sun Jul 13 07:14:19 2014 Julien ANDRE
*/

#include	<stdio.h>
#include	"server.h"

int		handle_buffer_end(t_client *tmp, int *move)
{
  int		actl;
  int		pend;

  pend = (tmp->buffer.len + tmp->len_cmd) - BUFFER_SIZE;
  actl = tmp->len_cmd - pend;
  memcpy(tmp->buffer.offset, tmp->cmd, actl);
  tmp->buffer.offset = tmp->buffer.buffer;
  memcpy(tmp->buffer.offset, tmp->cmd + actl, pend);
  *move = pend;
  return (DONE);
}

int		get_cmd(t_serv *serv)
{
  int		move;
  t_client	*tmp;

  tmp = serv->clients;
  while (tmp != NULL)
    {
      if (*tmp->cmd != 0)
	{
	  move = tmp->len_cmd;
	  if (tmp->len_cmd + tmp->buffer.len <= BUFFER_SIZE)
	    memcpy(tmp->buffer.offset, tmp->cmd, tmp->len_cmd);
	  else if (tmp->len_cmd + tmp->buffer.len > BUFFER_SIZE)
	    handle_buffer_end(tmp, &move);
	  tmp->buffer.offset += move * sizeof(char);
	  tmp->buffer.len = (tmp->buffer.len + tmp->len_cmd) % BUFFER_SIZE;
	  memset(tmp->cmd, 0, tmp->len_cmd + 1);
	  tmp->len_cmd = 0;
	}
      tmp = tmp->next;
    }
  return (DONE);
}

int		extract_cmd(int pos, t_client *tmp)
{
  int		save;

  save = pos;
  while (tmp->buffer.buffer + pos != tmp->buffer.offset &&
	 tmp->buffer.buffer[pos] != '\n')
    ++pos;
  if (tmp->buffer.buffer[pos] == '\n')
    {
      tmp->cmd = memcpy(tmp->cmd, tmp->buffer.buffer + save, pos - save + 1);
      tmp->len_cmd = pos - save;
      memset(tmp->buffer.buffer + save , 0, pos - save + 1);
    }
  return (DONE);
}

int		analyse_cmd(t_client *clients)
{
  int		pos;
  t_client	*tmp;

  tmp = clients;
  while (tmp != NULL)
    {
      if (tmp->buffer.len != 0)
	{
	  pos = 0;
	  while (pos != BUFFER_SIZE && tmp->buffer.buffer[pos] == 0)
	    ++pos;
	  if (pos != BUFFER_SIZE)
	    extract_cmd(pos, tmp);
	}
      tmp = tmp->next;
    }
  return (DONE);
}

int		execute_cmd(t_serv *serv)
{
  t_client	*tmp;
  func_ptr	ptr;

  tmp = serv->clients;
  while (tmp != NULL)
    {
      if (*tmp->cmd != 0)
	if ((ptr = is_cmd(tmp->cmd)) != NULL)
	  ptr(serv, tmp);
      tmp = tmp->next;
    }
  return (DONE);
}

/*
** server.h for zappy in /home/chanut_g/rendu/PSU_2013_zappy/includes/server
** 
** Made by Guillaume
** Login   <chanut_g@epitech.net>
** 
** Started on  Mon May 12 15:30:19 2014 Guillaume
** Last update Sun Jul 13 06:47:38 2014 Julien ANDRE
*/

#ifndef			SERVER_H_
# define		SERVER_H_

# include		<ctype.h>
# include		<string.h>
# include		<unistd.h>
# include		<netinet/in.h>
# include		<arpa/inet.h>
# include		<netdb.h>
# include		<sys/types.h>
# include		<sys/socket.h>
# include		<sys/time.h>

# include		"messages.h"

typedef enum		{TRUE, FALSE}		bool;

# define		DEF_PORT		4242
# define		DEF_XWORLD		20
# define		DEF_YWORLD		20
# define		DEF_TEAMNAME		Team_
# define		DEF_CBT			10
# define		DEF_DELAY		100
# define		DEF_NBR_TEAM		2

# define		QUEUE			25
# define		PACKET_SIZE		2048
# define		BUFFER_SIZE		4096

# define		FAIL			1
# define		DONE			2

# define		UNUSED			__attribute__((__unused__))

# define		WELCOME			"BIENVENU\n"

typedef struct		s_team
{
  char			*teamname;
  int			teamplace;
}			t_team;

typedef struct		s_info
{
  unsigned int		portnb;
  unsigned int		xworld;
  unsigned int		yworld;
  int			nbrteam;
  t_team		*teamnames;
  unsigned int		clientbyteam;
  unsigned int		delay;
}			t_info;

typedef struct		s_connec
{
  int			s_sock;
  fd_set		rfd;
  fd_set		wfd;
  bool			flag;
}			t_connec;

# define		FOOD		0
# define		LINEMATE	1
# define		DERAUMERE	2
# define		SIBUR		3
# define		MENDIANE	4
# define		PHIRAS		5
# define		THYSTAME	6

typedef struct		s_buffer
{
  char			*buffer;
  char			*offset;
  int			len;
}			t_buffer;

typedef enum		e_orient
  {
    UP = 0,
    RIGHT = 1,
    DOWN = 2,
    LEFT = 3
  }			e_orient;

typedef struct		s_perso
{
  unsigned short	level;
  unsigned int		posx;
  unsigned int		posy;
  e_orient		orient;
  unsigned int		bag[7];
}			t_perso;

# define		PERSO		c->perso

typedef struct		s_client
{
  int			sock;
  int			team;
  char			*cmd;
  int			len_cmd;
  t_buffer		buffer;
  bool			up;
  t_perso		perso;
  struct s_client	*next;
  struct s_client	*prev;
}			t_client;

typedef struct		s_timer
{
  struct timeval	tv;
  int			clock_beg;
  int			clock_end;
}			t_timer;

typedef struct		s_box
{
  unsigned char		object[7];
}			t_box;

# define		MAP(x)		s->map[x]
# define		INFO		s->info

typedef struct		s_serveur
{
  t_box			*map;
  t_info		info;
  t_timer		timer;
  t_connec		connec;
  t_client		*clients;
}			t_serv;

# define		NBR_ACTIONS	12

typedef int		(*func_ptr)(t_serv *, t_client *);

typedef struct		s_cmd
{
  func_ptr		ptr;
  char			*cmd;
}			t_cmd;

int			server_init(t_serv*);
int			server_select(t_serv *);

int			has_closed(int);
int			get_stop(int);
void			handle_ctrl_c(int);
void			handle_sig_pipe(int);

int			get_nfds(t_serv *);

int			set_timer(t_serv *);

int			add_client(t_serv *);
int			rm_client(t_client **, t_client *);
t_client		*new_client(int);
unsigned int	       	list_size(t_client *);

int			wr_set(t_serv *);
int			check_fd(t_serv *);

int			read_on_socket(t_client *);
int			write_on_socket(t_client *);

int			get_cmd(t_serv *);
int			analyse_cmd(t_client *);
int			handle_buffer_end(t_client *, int *);
int			extract_cmd(int, t_client *);
int			execute_cmd(t_serv *);

func_ptr		is_cmd(char *);
int			check_team(t_serv *, t_client *);
int			final_connec(t_serv *, t_client *, int);

/* GETARGS */

# define		NBR_OPT			6

typedef struct		s_getargs
{
  int			opt;
  void			(*ptr)(t_serv *, int, char **);
}			t_getargs;

int			init_param(t_serv*, int, char **);

/* ### */

void			setport(t_serv*, int, char **);
void			setwidth(t_serv*, int, char **);
void			setheight(t_serv*, int, char **);
void			setteamname(t_serv*, int, char **);
void			setcbt(t_serv*, int, char **);
void			setdelay(t_serv*, int, char **);

void			hw(int);

int			init_places(t_serv *);

/* MAP */
int			init_map(t_serv *);
int			feed_map(t_serv *);
int			free_map(t_serv *);

int			get_id_block(t_serv *, int, int);
int			get_block_posx(t_serv *, int);
int			get_block_posy(t_serv *, int);

/* CMD */
int                     cmd_broadcast(t_serv *, t_client *);
int                     cmd_connect_nbr(t_serv *, t_client *);
int                     cmd_drop(t_serv *, t_client *);
int                     cmd_expulse(t_serv *, t_client *);
int                     cmd_fork(t_serv *, t_client *);
int                     cmd_incant(t_serv *, t_client *);
int			cmd_invent(t_serv *, t_client *);
int                     cmd_listbox(t_serv *, t_client *);
int			cmd_movefw(t_serv *, t_client *);
int			cmd_right(t_serv *, t_client *);
int			cmd_left(t_serv *, t_client *);
int                     cmd_see(t_serv *, t_client *);
int                     cmd_take(t_serv *, t_client *);

#endif

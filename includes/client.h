/*
** client.h for  in /home/bourma_m/Projets/SystemUnix/PSU_2013_zappy
** 
** Made by Mathieu Bourmaud
** Login   <bourma_m@epitech.net>
** 
** Started on  Tue Jun 24 10:35:30 2014 Mathieu Bourmaud
** Last update Sun Jul 13 17:20:13 2014 Mathieu Bourmaud
*/

#ifndef		CLIENT_H_
# define	CLIENT_H_

#include	<sys/types.h>
#include	<sys/socket.h>
#include	<sys/select.h>
#include	<netdb.h>
#include	<arpa/inet.h>
#include	<netinet/in.h>
#include	<string.h>
#include	<errno.h>
#include	<stdio.h>
#include	<unistd.h>
#include	<stdlib.h>
#include	<time.h>

/*		COLORS			*/
# define	RED			"\e[1;31m"
# define	GREEN			"\e[1;32m"
# define	BLUE			"\e[1;34m"
# define	PINK			"\e[1;35m"
# define	COLOR_END		"\e[m"

/*		MESSAGES		*/
# define	WELCOME			"Weclome to client\n"
# define	USAGE			"Usage : ./client -n [TEAM_NAME] -p \
[PORT] -h [MACHINE_NAME : default localhost]\n"
# define	BAD_FLAGS		"Bad usage, you must use -n, -p and -h. \
-n is for the team name, -p is for the port, and -h for the machine name\n"
# define	BAD_PORT		"The port must contains only numbers. \
Not letters.\n"
# define	CLIENT			"Team : %s\nPort : %d\nMachine : %s\n"
# define	ERR_GETPROTO		"Error : getprotobyname(TCP) has failed \
in client.c\n"
# define	ERR_SOCKET		"Error : socket() has failed in \
client.c\n"
# define	ERR_SELECT		"Error : select() has failed in \
client.c\n"
# define	ERR_CONNECT		"Error : connect() has failed in \
client.c\n"
# define	ERR_RSOCKET		"Error : read_socket() has failed \
in client.c\n"
# define	ERR_IA			"Error : IAmain() has failed in \
client.c\n"
# define	DEAD			"You are dead. :/\n"
# define	FOOD_OK			"I have enough food"
# define	NOFOOD_HERE		"There is no food here. \
We have to moove\n"
# define	NOJEWEL_HERE		"There is no jewel here. \
We have to moove\n"
# define	NEAD_MORE		"You don't have all the \
required jewels\n"

typedef	struct	s_client
{
  int		port;
  int		socket;
  char		*team;
  char		*machine;
  int		cs;
  int		*inventory;
  fd_set	fread;
  int		jewel_req[7];
  int		player_req;
  int		level;
  int		myJewel[7];
  char*		JewelToGet;
  int		isHelping;
  int		nb;
  int		nb_player;
}		t_client;

/*
**		checks_usage.c
*/
int		check_usage(char *, char *, char *);
int		check_port(char *);
/*
**		write_to.c
*/
void		write_to(int, char *);
/*
**		client.c
*/
int		init_client(t_client);
int		do_client(t_client);
char		*read_socket(t_client *);
char		*read_socket_incant(t_client *);
int		getNum(char *);
int		helpTo(char *);
int		goToFriend(t_client *, char *);
/*
**		IAFood.c
*/
int		IAGetFood(t_client);
int		moveTo(t_client, char *, int);
int		avance(t_client);
int		takeFood(t_client);
int		isFoodHere(t_client);
int		isEnoughFood(t_client);
/*
**		IAJewels.c
*/
int		drop_jewels(t_client *, int);
int		check_tab(t_client *);
int		IAGetJewels(t_client *);
int		takeJewel(t_client *, int);
int		isJewelHere(t_client);
int		isEnoughJewels(t_client);
int		move(t_client);
/*
**		IATeam.c
*/
int		IAGetTeam(t_client);
int		askTeam(t_client);
int		isEnoughTrantoriens(t_client);
int		broadcast(int, t_client *, char *);
char		*getJewel(int);
/*
**		IAmain.c
*/
int		count_player(t_client);
int		IAmain(t_client *);
int		compare_tab(t_client);
int		init_tab(t_client *);
/*
**		ParseData.c
**/
int		getFoodValue(char *);
int		getPos(t_client, char *);
/*
**		initElevation.c
*/
void		init_elevation(t_client *, int);
void		elev1(t_client *);
void		elev2(t_client *);
void		elev3(t_client *);
void		elev4(t_client *);
/*
**		endElevation.c
*/
void		elev5(t_client *);
void		elev6(t_client *);
void		elev7(t_client *);
/*
**		forIncantation.c
*/
int		empty_case(t_client *);
int		incantation(t_client *);
void		startIncantation(t_client *, char *);
/*
**		broadcast.c
*/
void		broadcastLoops(t_client *, char *);
/*
**		read_socket.c
*/
int		parse_readsocket(char *);
void		fd_isset_readsocket(t_client *, char *, int, int);
int		fdisset0(int, char *, t_client *);
void            fdisset2(char *, t_client *);
int		fdisset1(t_client *, char *);
void		call_fdisset(char *, char *, t_client *);
void		call_fdisset2(char *, char *, t_client *);

#endif

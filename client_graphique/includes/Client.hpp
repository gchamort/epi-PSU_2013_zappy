//
// client.hpp for client in /home/genaud_p/SystemeUnix/TeddyZappyG/graphics
// 
// Made by Pierre Genaudeau
// Login   <genaud_p@epitech.net>
// 
// Started on  Wed Jul  9 11:06:02 2014 Pierre Genaudeau
// Last update Sun Jul 13 16:46:15 2014 Pierre Genaudeau
//

#ifndef	CLIENT_HPP_
#define CLIENT_HPP_

#include	<string.h>
#include	<iostream>
#include	<cstdlib>
#include	<sys/types.h>
#include	<sys/select.h>
#include	<netdb.h>
#include	<netinet/in.h>
#include	<arpa/inet.h>
#include	<unistd.h>
#include	"Display.hpp"
#include	<string>
#include	<sstream>
#include	<vector>
#include	<SFML/Graphics.hpp>
#include	<SFML/System.hpp>

class	Client
{
public:
  Client();
  ~Client();
  int	do_client(int socket);
  int	run_client(int port, char *ip);
  void	cmdDisplay(std::vector<std::string> &vec, std::string &str);
};

int	my_atoi(const std::string nb);
  
#endif

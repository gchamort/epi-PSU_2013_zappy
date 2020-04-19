//
// main.cpp for main in /home/genaud_p/SystemeUnix/client_graphique_zappy
// 
// Made by Pierre Genaudeau
// Login   <genaud_p@epitech.net>
// 
// Started on  Mon Jun 30 15:27:35 2014 Pierre Genaudeau
// Last update Sun Jul 13 15:36:20 2014 Pierre Genaudeau
//

#include	"Display.hpp"
#include	"Client.hpp"

int	main(int ac, char **av)
{
  (void)av;
  Client	client;

  if (ac != 3)
    {
      std::cerr << "Usage : ./client_graphique ip port"  << std::endl;
      return (-1);
    }
  else
    client.run_client(atoi(av[2]), av[1]);
  return (0);
}

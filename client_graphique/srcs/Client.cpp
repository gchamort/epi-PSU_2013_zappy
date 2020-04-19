//
// client.cpp for client in /home/ladene_t/project/TeddyZappyG/graphics/srcs
// 
// Made by Teddy Ladener
// Login   <ladene_t@epitech.net>
// 
// Started on  Mon Jul  7 16:02:32 2014 Teddy Ladener
// Last update Sun Jul 13 18:11:20 2014 Pierre Genaudeau
//

#include	"Client.hpp"

Client::Client()
{
}

Client::~Client()
{
}

int		Client::do_client(int socket)
{
  fd_set	fd_read;
  char		*buff;
  std::string	buffer;
  std::vector<std::string> string_tab;
  std::vector<std::string> string_word;
  Display	display;
  int i = 0,j = 0;
  
  buff = (char*)malloc(sizeof(char) * 80000);
  write(socket, "GRAPHIC\n", strlen("GRAPHIC\n"));
  FD_ZERO(&fd_read);
  FD_SET(socket, &fd_read);
  select(socket + 1, &fd_read, NULL, NULL, NULL);
  if (FD_ISSET(socket, &fd_read))
    {
      bzero(buff, 4096);
      read(socket, buff, 4096);
      buffer = buff;
    }
  while (1)
    {
      if (FD_ISSET(socket, &fd_read))
	{
	  bzero(buff, 80000);
	  recv(socket, buff, 80000, MSG_DONTWAIT);
	  buffer = buff;
	  i = 0;
	  j = 0;
	  while (buffer[i] != '\0')
	    {
	      if (buffer[i] == '\n')
		{
		  string_tab.push_back(buffer.substr(j, i - j));
		  j = i;
		}
	      i++;
	    }
	  while (!string_tab.empty())
	    {
	      int k = 0, l = 0, check = 0;
	      while (string_tab.front()[k] != '\0')
		{
		  if (string_tab.front()[k] == ' ')
		    {
	      if (check == 1)
		string_word.push_back(string_tab.front().substr(l + 1, k - l));
	      else
		string_word.push_back(string_tab.front().substr(l, k - l));
	      l = k;
	      check = 1;
		    }
		  if (string_tab.front()[k + 1] == '\0')
		    {
		      string_word.push_back(string_tab.front().substr(l, k + 1 - l));
		      l = k;
		    }
		  k++;
		}
      if (string_word.front() == "msz")
	{
	  int nb;
	  int nb2;
	  
	      nb = my_atoi(string_word[1]);
	      nb2 = my_atoi(string_word[2]);
	      display.initialize(nb, nb2);
	      std::cout << "Command msz = " << string_word[1] << string_word[2] << std::endl;
	    }
	  if (string_word.front() == "\nbct")
	    {
	      for (unsigned int map = 0; map != display.getMap().size(); ++map)
		{
		  if (my_atoi(string_word[1]) == display.getMap()[map]->getXGraph() && my_atoi(string_word[2]) == display.getMap()[map]->getYGraph())
		    {
		      display.setQuantity(map, my_atoi(string_word[3]), my_atoi(string_word[4]), my_atoi(string_word[5]), my_atoi(string_word[6]), my_atoi(string_word[7]), my_atoi(string_word[8]), my_atoi(string_word[9]));
		    }
		}
	      std::cout << "Command = bct " << string_word[1] << string_word[2] << string_word[3] << string_word[4] << string_word[5] << string_word[6] << string_word[7] << string_word[8] << string_word[9] << std::endl;
	    }
	  if (string_word.front() == "\npnw")
	    {
	      int	posX = my_atoi(string_word[2]) + (64 * my_atoi(string_word[2]));
	      int	posY = my_atoi(string_word[3]) + (64 * my_atoi(string_word[3]));
	      sf::Vector2f	pos;
	      
	      pos.x = posX;
	      pos.y = posY;
	      display.addPerso("./ressources/spriteFinal.png", my_atoi(string_word[1]), pos, my_atoi(string_word[4]), string_word[6], my_atoi(string_word[2]), my_atoi(string_word[3]));
	    }
	  if (string_word.front() == "ppo")
	    {
	      int	posX = my_atoi(string_word[2]) + (64 * my_atoi(string_word[2]));
	      int	posY = my_atoi(string_word[3]) + (64 * my_atoi(string_word[3]));
	      for (unsigned int c = 0; c != display.getPersos().size(); ++c)
		{
		  if (my_atoi(string_word[1]) == display.getPersos()[c]->getNumero())
		    display.setPosition(c, posX, posY, my_atoi(string_word[4]));
		}
	      std::cout << "Command = pnw " << string_word[1] << " " << string_word[2] << " " << string_word[3] << " " << string_word[4] << " " << string_word[5] << std::endl;
	    }
	  if (string_word.front() == "\nseg")
	    {
	      std::cout << "Commands : seg " << string_word[1] << std::endl;
	      exit(0);
	    }
	  if (string_word.front() == "enw")
	    {
	      int	posX = my_atoi(string_word[3]) + (64 * my_atoi(string_word[3]));
	      int	posY = my_atoi(string_word[4]) + (64 * my_atoi(string_word[4]));
	      for (unsigned int c = 0; c != display.getPersos().size(); ++c)
		{
		  if (my_atoi(string_word[2]) == display.getPersos()[c]->getNumero())
		    display.addEgg("./ressources/spriteFinal.png", sf::IntRect(64, 0, 40, 52), sf::Vector2f(posX, posY), my_atoi(string_word[1]));
		}
	    }
	  if (string_word.front() == "\npdi")
	    {
	      for (unsigned int c = 0; c != display.getPersos().size(); ++c)
		{
		  if (my_atoi(string_word[1]) == display.getPersos()[c]->getNumero())
		    {
		      display.removePersos(c);
		      break;
		    }
		}
	    }
	  if (string_word.front() == "ebo" || string_word.front() == "edi")
	    {
	      for (unsigned int c = 0; c != display.getEgg().size(); ++c)
		{
		  if (my_atoi(string_word[1]) == display.getEgg()[c]->getNumero())
		    display.removeEgg(c);
		}
	    }
	  if (string_word.front() == "pie")
	    {
	      if (my_atoi(string_word[3]) == 1)
		{
		  for (unsigned int c = 0; c != display.getPersos().size(); ++c)
		    {
		      if (my_atoi(string_word[1]) == display.getPersos()[c]->getXMap() && 
			  my_atoi(string_word[2]) == display.getPersos()[c]->getYMap())
			display.levelUp(c);
		    }
		}
	    }
	  if (string_word.front() == "pdr ")
	    {
	      std::cout << "Command = pdr" << string_word[1] << string_word[2] << std::endl;
	      for (unsigned int k = 0; k != display.getPersos().size(); ++k)
		{
		  if (my_atoi(string_word[1]) == display.getPersos()[k]->getNumero())
		    {
		      display.setQuantityPerso(k, my_atoi(string_word[2]), display.getPersos()[k]->getQuantity(my_atoi(string_word[2])) - 1);
		    }
		}
	    }
	  if (string_word.front() == "pgt")
	    {
	      std::cout << "Command = pgt " << string_word[1] << string_word[2] << std::endl;
	      for (unsigned int c = 0; c != display.getPersos().size(); ++c)
		{
		  if (my_atoi(string_word[1]) == display.getPersos()[c]->getNumero())
		    {
		      display.setQuantityPerso(c, my_atoi(string_word[2]), display.getPersos()[c]->getQuantity(my_atoi(string_word[2])) + 1);
		    }
		}
	    }
	  this->cmdDisplay(string_word, string_word.front());
	  string_word.clear();
	  string_tab.erase(string_tab.begin());
	    }
	}
      display.update();
    }
}

void	Client::cmdDisplay(std::vector<std::string> &vec, std::string &str)
{
  if (str == "smg")
    std::cout << "smg " << vec[1]  << std::endl;
  if (str == "suc")
    std::cout << "Commande inconnue" << std::endl;
  if (str == "sbp")
    std::cout << "Mauvais parametre pour la commande" << std::endl;
  if (str == "\nsgt")
    std::cout << "Command sgt =" << vec[1] << std::endl;
  if (str == "\nplv")
    std::cout << "Command plv =" << vec[1] << vec[2] << std::endl;
  if (str == "\npin")
    {
      std::cout << "Command pin =" << vec[1] << vec[2] << vec[3] << vec[4] << vec[5] << vec[6] << vec[7] << vec[8] << vec[9] << vec[10] << std::endl;
    }
  if (str == "pfk ")
    std::cout << "Command = pfk" << vec[1] << std::endl;
}

int     Client::run_client(int port, char *ip)
{
  struct protoent       *proto;
  struct sockaddr_in    sin;
  int                   sock;

  if ((proto = getprotobyname("TCP")) == NULL)
    {
      std::cerr << "Getprotobyname error\n" << std::endl;
      return (-1);
    }
  if ((sock = socket(AF_INET, SOCK_STREAM, proto->p_proto)) == -1)
    {
      std::cerr << "Socket error\n" << std::endl;
      return (-1);
    }
  sin.sin_family = AF_INET;
  sin.sin_port = htons(port);
  sin.sin_addr.s_addr = inet_addr(ip);
  if ((connect(sock, (const struct sockaddr *)&(sin), sizeof(sin))) == -1)
    {
      std::cerr <<  "Erreur Connect\n" << std::endl;
      return (-1);
    }
  do_client(sock);
  return (0);
}

int	my_atoi(const std::string nb)
{
  std::stringstream ss;
  int	nbToReturn;

  ss << nb;
  ss >> nbToReturn;

  return (nbToReturn);
}

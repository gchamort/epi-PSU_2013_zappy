//
// Display.cpp for Display in /home/genaud_p/SystemeUnix/client_graphique_zappy
// 
// Made by Pierre Genaudeau
// Login   <genaud_p@epitech.net>
// 
// Started on  Mon Jun 30 15:09:35 2014 Pierre Genaudeau
// Last update Sun Jul 13 10:57:54 2014 Pierre Genaudeau
//

#include	"Display.hpp"

Display::Display()
{
}

Display::~Display()
{
}

void	Display::initialize(int x, int y)
{
  _size = x * y;
  int X = 0, Y = 0;
  //  _persos.push_back(new Perso("./ressources/spriteFinal.png", sf::IntRect(0, 96, 34, 59), sf::Vector2f(10, 10), Perso::S, "toto"));
  for (int i = 0; i != x; ++i)
    {
      Y = 0;
      for (int j = 0; j != y; ++j)
	{
	  _map.push_back(new Floor("./ressources/spriteFinal.png", sf::IntRect(0, 0, 64, 64), sf::Vector2f(X, Y), i, j));
	  Y += 64;
	}
      X += 64;
    }
  _window.create(sf::VideoMode(1280, 720), "Zappy");
  _window.setPosition(sf::Vector2i(0, 0));
}

void	Display::update()
{
  // while (_window.isOpen())
  //   {
  while (_window.pollEvent(_event))
    {
      if (_event.type == sf::Event::Closed)
	_window.close();
      if (_event.type == sf::Event::KeyPressed)
	if (_event.key.code == sf::Keyboard::Escape)
	  _window.close();
    }
  this->moveView();
  this->handleCollision();
  this->draw();
      //    }
}
void	Display::draw()
{
  _window.clear(sf::Color(51, 153, 255));
  for (int i = 0; i != _size; ++i)
    _window.draw(_map[i]->getSprite());
  for (unsigned int i = 0; i != _persos.size(); ++i)
    _window.draw(_persos[i]->getSprite());
  for (unsigned int i = 0; i != _fondPersos.size(); ++i)
    _window.draw(_fondPersos[i]->getSprite());
  for (unsigned int i = 0; i != _fond.size(); ++i)
    _window.draw(_fond[i]->getSprite());
  for (unsigned int i = 0; i != _mineralPersos.size(); ++i)
    _window.draw(_mineralPersos[i]->getText());
  for (unsigned int i = 0; i != _foodPerso.size(); ++i)
    _window.draw(_foodPerso[i]->getText());
  for (unsigned int i = 0; i != _mineral.size(); ++i)
    _window.draw(_mineral[i]->getSprite());
  for (unsigned int i = 0; i != _mineral.size(); ++i)
    _window.draw(_mineral[i]->getText());
  for (unsigned int i = 0; i != _mineralPersos.size(); ++i)
    _window.draw(_mineralPersos[i]->getSprite());
  for (unsigned int i = 0; i != _food.size(); ++i)
    _window.draw(_food[i]->getSprite());
  for (unsigned int i = 0; i != _food.size(); ++i)
    _window.draw(_food[i]->getText());
  for (unsigned int i = 0; i != _foodPerso.size(); ++i)
    _window.draw(_foodPerso[i]->getSprite());
  for (unsigned int i = 0; i != _fondPersos.size(); ++i)
    _window.draw(_fondPersos[i]->getText());
  for (unsigned int i = 0; i != _egg.size(); ++i)
    _window.draw(_egg[i]->getSprite());
  for (unsigned int i = 0; i != _persos.size(); ++i)
    _window.draw(_persos[i]->getText());
  _window.display();
}
void	Display::moveView()
{
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
      for (int i = 0; i != _size; ++i)
	_map[i]->move(10, 0);
      for (unsigned int i = 0; i != _persos.size(); ++i)
	_persos[i]->move(10, 0);
      for (unsigned int j = 0; j != _egg.size(); ++j)
	_egg[j]->move(10, 0);
    }
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
      for (int i = 0; i != _size; ++i)
	_map[i]->move(-10, 0);
      for (unsigned int i = 0; i != _persos.size(); ++i)
	_persos[i]->move(-10, 0);
      for (unsigned int j = 0; j != _egg.size(); ++j)
	_egg[j]->move(-10, 0);
    }
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
      for (int i = 0; i != _size; ++i)
	_map[i]->move(0, 10);
      for (unsigned int i = 0; i != _persos.size(); ++i)
	_persos[i]->move(0, 10);
      for (unsigned int j = 0; j != _egg.size(); ++j)
	_egg[j]->move(0, 10);
    }
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
      for (int i = 0; i != _size; ++i)
	_map[i]->move(0, -10);
      for (unsigned int i = 0; i != _persos.size(); ++i)
	_persos[i]->move(0, -10);
      for (unsigned int j = 0; j != _egg.size(); ++j)
	_egg[j]->move(0, -10);
    }
}
void	Display::moveZoom()
{

}

void	Display::setView(sf::Vector2f const &newView)
{
  (void)newView;
}

void	Display::handleCollision()
{
  _mousePos = sf::Mouse::getPosition(_window);

  for (unsigned int i = 0; i != _map.size(); ++i)
    {  
      if (_map[i]->getBoundingBox().contains(_mousePos.x, _mousePos.y))
	{
	  _mineral.push_back(new Mineral("./ressources/spriteFinal.png", sf::IntRect(0, 64, 17, 32), sf::Vector2f(1120, 550), Mineral::linemate));
	  _mineral.push_back(new Mineral("./ressources/spriteFinal.png", sf::IntRect(17, 64, 17, 32), sf::Vector2f(1120, 590), Mineral::deraumere));
	  _mineral.push_back(new Mineral("./ressources/spriteFinal.png", sf::IntRect(34, 64, 17, 32), sf::Vector2f(1120, 630), Mineral::sibur));
	  _mineral.push_back(new Mineral("./ressources/spriteFinal.png", sf::IntRect(51, 64, 17, 32), sf::Vector2f(1200, 550), Mineral::mendiane));
	  _mineral.push_back(new Mineral("./ressources/spriteFinal.png", sf::IntRect(68, 64, 17, 32), sf::Vector2f(1200, 590), Mineral::phiras));
	  _mineral.push_back(new Mineral("./ressources/spriteFinal.png", sf::IntRect(85, 64, 17, 32), sf::Vector2f(1200, 630), Mineral::thystame));
	  _fond.push_back(new Fond("./ressources/fond3.png", sf::IntRect(0, 0, 200, 200), sf::Vector2f(1080, 520)));
	  _food.push_back(new Food("./ressources/spriteFinal.png", sf::IntRect(102, 64, 32, 32), sf::Vector2f(1115, 670)));
	  _mineral[0]->displayText(_map[i]->getQuantity(1));
	  _mineral[1]->displayText(_map[i]->getQuantity(2));
	  _mineral[2]->displayText(_map[i]->getQuantity(3));
	  _mineral[3]->displayText(_map[i]->getQuantity(4));
	  _mineral[4]->displayText(_map[i]->getQuantity(5));
	  _mineral[5]->displayText(_map[i]->getQuantity(6));
	  _food[0]->displayText(_map[i]->getQuantity(0));
	  break;
	}
      else
	{
	  if (!_fond.empty())
	    {
	      while (!_fond.empty())
		{
		  delete _fond.back();
		  _fond.pop_back();
		}
	    }
	  if (!_food.empty())
	    while (!_food.empty())
	      {
		delete _food.back();
		_food.pop_back();
	      }
	  while (!_mineral.empty())
	    {
	      delete _mineral.back();
	      _mineral.pop_back();
	    }
	}
    }

  _mousePosPerso = sf::Mouse::getPosition(_window);
  for (unsigned int i = 0; i != _persos.size(); ++i)
    {
      if (sf::Mouse::isButtonPressed(sf::Mouse::Left) &&
	  _persos[i]->getBoundingBox().contains(_mousePosPerso.x, _mousePosPerso.y))
	{
	  std::cout << "debut if clic" << std::endl;
	  _mineralPersos.push_back(new Mineral("./ressources/spriteFinal.png", sf::IntRect(0, 64, 17, 32), sf::Vector2f(1120, 350), Mineral::linemate));
	  _mineralPersos.push_back(new Mineral("./ressources/spriteFinal.png", sf::IntRect(17, 64, 17, 32), sf::Vector2f(1120, 390), Mineral::deraumere));
	  _mineralPersos.push_back(new Mineral("./ressources/spriteFinal.png", sf::IntRect(34, 64, 17, 32), sf::Vector2f(1120, 430), Mineral::sibur));
	  _mineralPersos.push_back(new Mineral("./ressources/spriteFinal.png", sf::IntRect(51, 64, 17, 32), sf::Vector2f(1200, 350), Mineral::mendiane));
	  _mineralPersos.push_back(new Mineral("./ressources/spriteFinal.png", sf::IntRect(68, 64, 17, 32), sf::Vector2f(1200, 390), Mineral::phiras));
	  _mineralPersos.push_back(new Mineral("./ressources/spriteFinal.png", sf::IntRect(85, 64, 17, 32), sf::Vector2f(1200, 430), Mineral::thystame));
	  _fondPersos.push_back(new Fond("./ressources/fond3.png", sf::IntRect(0, 0, 200, 200), sf::Vector2f(1080, 320)));
	  _foodPerso.push_back(new Food("./ressources/spriteFinal.png", sf::IntRect(102, 64, 32, 32), sf::Vector2f(1115, 470)));
	  _fondPersos[0]->displayText(_persos[i]->getTeam());
	  std::cout << "fin if clic" << std::endl;
	  _persos[i]->displayText(_persos[i]->getLevel());
	  _mineralPersos[0]->displayText(_persos[i]->getQuantity(1));
	  _mineralPersos[1]->displayText(_persos[i]->getQuantity(2));
	  _mineralPersos[2]->displayText(_persos[i]->getQuantity(3));
	  _mineralPersos[3]->displayText(_persos[i]->getQuantity(4));
	  _mineralPersos[4]->displayText(_persos[i]->getQuantity(5));
	  _mineralPersos[5]->displayText(_persos[i]->getQuantity(6));
	  _foodPerso[0]->displayText(_persos[i]->getQuantity(0));
	  break;
	}
      else
	{
	  if (!_fondPersos.empty())
	    {
	      while (!_fondPersos.empty())
		{
		  delete _fondPersos.back();
		  _fondPersos.pop_back();
		}
	    }
	  if (!_foodPerso.empty())
	    while (!_foodPerso.empty())
	      {
		delete _foodPerso.back();
		_foodPerso.pop_back();
	      }
	  while (!_mineralPersos.empty())
	    {
	      delete _mineralPersos.back();
	      _mineralPersos.pop_back();
	    }
	}
    }
}

void		Display::setQuantity(int i, int food, int m1, int m2, int m3, int m4, int m5, int m6)
{
  _map[i]->setQuantity(0, food);
  _map[i]->setQuantity(1, m1);
  _map[i]->setQuantity(2, m2);
  _map[i]->setQuantity(3, m3);
  _map[i]->setQuantity(4, m4);
  _map[i]->setQuantity(5, m5);
  _map[i]->setQuantity(6, m6);
}

std::vector<Floor *>	Display::getMap() const
{
  return (_map);
}

void			Display::addPerso(std::string imagePath, int numero, sf::Vector2f pos, int orientation, const std::string team, float xMap, float yMap)
{
  _persos.push_back(new Perso(imagePath, numero, pos, orientation, team, xMap, yMap));
}

std::vector<Perso *>	Display::getPersos() const
{
  return (_persos);
}

void			Display::setPosition(int i, int x, int y, int orientation)
{
  _persos[i]->setPosition(x, y);
  _persos[i]->setOrientation(orientation);
  _persos[i]->checkOrientation();
}

void			Display::addEgg(const std::string imagePath, sf::IntRect subRect, sf::Vector2f pos, int numero)
{
  _egg.push_back(new Egg(imagePath, subRect, pos, numero));
}

void			Display::removePersos(int i)
{
  if (!_persos.empty())
    {
      delete _persos[i];
      _persos.erase(_persos.begin() + (i));
    }
}

std::vector<Egg *>	Display::getEgg() const
{
  return (_egg);
}

void			Display::removeEgg(int i)
{
  if (!_egg.empty())
    {
      delete _egg[i];
      _egg.erase(_egg.begin() + (i));
    }
}

void		Display::levelUp(int i)
{
  _persos[i]->setLevel(_persos[i]->getLevel() + 1);
}

void		Display::setQuantityPerso(int i, int type, int nb)
{
  _persos[i]->setQuantity(type, nb);
}

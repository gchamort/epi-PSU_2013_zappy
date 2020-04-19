//
// Display.hpp for Display in /home/genaud_p/SystemeUnix/client_graphique_zappy
// 
// Made by Pierre Genaudeau
// Login   <genaud_p@epitech.net>
// 
// Started on  Mon Jun 23 15:34:19 2014 Pierre Genaudeau
// Last update Sat Jul 12 15:23:27 2014 Pierre Genaudeau
//

#ifndef	DISPLAY_HPP_
#define	DISPLAY_HPP_

#include	<SFML/Graphics.hpp>
#include	<SFML/System.hpp>
#include	<vector>
#include	<iostream>
#include	"Floor.hpp"
#include	"Perso.hpp"
#include	"Mineral.hpp"
#include	"Fond.hpp"
#include	"Food.hpp"
#include	"Egg.hpp"

class	Display
{
public:
  Display();
  ~Display();
  void	initialize(int x, int y);
  void	update();
  void	draw();
  void	moveView();
  void	moveZoom();
  void	setView(sf::Vector2f const &newView);
  void	handleCollision();
  void	setQuantity(int i, int food, int m1, int m2, int m3, int m4, int m5, int m6);
  std::vector<Floor *>	getMap() const;
  void			addPerso(std::string imagePath, int numero, sf::Vector2f pos, int orientation, const std::string team, float xMap, float yMap);
  std::vector<Perso *>	getPersos() const;
  void			setPosition(int i, int x, int y, int orientation);
  void			addEgg(const std::string imagePath, sf::IntRect subRect, sf::Vector2f pos, int numero);
  void			removePersos(int i);
  std::vector<Egg *>	getEgg() const;
  void			removeEgg(int i);
  void			levelUp(int i);
  void			setQuantityPerso(int i, int type, int nb);
private:
  sf::RenderWindow		_window;
  sf::Event			_event;
  std::vector<Floor *>		_map;
  std::vector<Perso *>		_persos;
  std::vector<Mineral *>	_mineral;
  std::vector<Mineral *>	_mineralPersos;
  std::vector<Fond *>		_fond;
  std::vector<Fond *>		_fondPersos;
  std::vector<Food *>		_food;
  std::vector<Food *>		_foodPerso;
  std::vector<Egg *>		_egg;
  int				_size;
  sf::View			_view;
  sf::Vector2f			_sizeView;
  sf::Vector2i			_mousePos;
  sf::Vector2i			_mousePosPerso;
};

int	run_client(int, char *);

#endif

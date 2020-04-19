//
// AMineral.hpp for AMineral in /home/genaud_p/SystemeUnix/client_graphique_zappy
// 
// Made by Pierre Genaudeau
// Login   <genaud_p@epitech.net>
// 
// Started on  Fri Jun 27 17:10:15 2014 Pierre Genaudeau
// Last update Wed Jul  9 16:45:01 2014 Pierre Genaudeau
//

#ifndef	MINERAL_HPP_
#define	MINERAL_HPP_

#include	<string>
#include	<SFML/Graphics.hpp>
#include	<iostream>

class	Mineral
{
public:
  enum	mineralType{linemate, deraumere, sibur, mendiane, phiras, thystame};
  Mineral(const std::string imagePath, sf::IntRect subRect, sf::Vector2f pos, mineralType mineral);
  ~Mineral();
  sf::Sprite	getSprite() const;
  sf::Text	getText() const;
  void		displayText(int nbToDisplay);
protected:
  sf::Texture	_texture;
  sf::Sprite	_sprite;
  sf::Font	_font;
  sf::Text	_text;
  mineralType	_type;
};

#endif

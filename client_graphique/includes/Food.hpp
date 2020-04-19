//
// Food.hpp for Food in /home/genaud_p/SystemeUnix/client_graphique_zappy/zappy_graphic/graphics
// 
// Made by Pierre Genaudeau
// Login   <genaud_p@epitech.net>
// 
// Started on  Tue Jul  1 11:41:11 2014 Pierre Genaudeau
// Last update Fri Jul  4 12:06:18 2014 Pierre Genaudeau
//

#ifndef	FOOD_HPP_
#define	FOOD_HPP_

#include	<SFML/Graphics.hpp>
#include	<sstream>

class	Food
{
public:
  Food(const std::string imagePath, sf::IntRect subRect, sf::Vector2f pos);
  ~Food();
  sf::Sprite	getSprite() const;
  sf::Text	getText() const;
  void		displayText(int nbToDisplay);
private:
  sf::Texture	_texture;
  sf::Sprite	_sprite;
  sf::Font	_font;
  sf::Text	_text;
};

#endif

//
// Food.cpp for Food in /home/genaud_p/SystemeUnix/client_graphique_zappy/zappy_graphic/graphics
// 
// Made by Pierre Genaudeau
// Login   <genaud_p@epitech.net>
// 
// Started on  Tue Jul  1 11:44:02 2014 Pierre Genaudeau
// Last update Sat Jul 12 21:09:31 2014 Pierre Genaudeau
//

#include	"Food.hpp"
#include	<iostream>

Food::Food(const std::string imagePath, sf::IntRect subRect, sf::Vector2f pos)
{
  if (!_texture.loadFromFile(imagePath))
    std::cerr << "Error on laoding image" << std::endl;
  else
    {
      _sprite.setTexture(_texture);
      _sprite.setTextureRect(subRect);
      _sprite.setPosition(pos);
    }
  if(!_font.loadFromFile("./ressources/arial.ttf"))
    std::cerr << "Error on loading the font" << std::endl;
  _text.setFont(_font);
  _text.setColor(sf::Color::White);
  _text.setStyle(sf::Text::Bold);
  _text.setCharacterSize(20);
}

Food::~Food()
{
}

sf::Sprite	Food::getSprite() const
{
  return (_sprite);
}

sf::Text	Food::getText() const
{
  return (_text);
}

void		Food::displayText(int nbToDisplay)
{
  std::ostringstream	oss;

  oss << nbToDisplay;
  _text.setPosition(_sprite.getPosition().x + 35, _sprite.getPosition().y + 5);
  _text.setString(oss.str());
}

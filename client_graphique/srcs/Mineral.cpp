//
// Mineral.cpp for Mineral in /home/genaud_p/SystemeUnix/client_graphique_zappy
// 
// Made by Pierre Genaudeau
// Login   <genaud_p@epitech.net>
// 
// Started on  Mon Jun 30 15:19:14 2014 Pierre Genaudeau
// Last update Wed Jul  9 16:45:13 2014 Pierre Genaudeau
//

#include	"Mineral.hpp"
#include	<sstream>

Mineral::Mineral(const std::string imagePath, sf::IntRect subRect, sf::Vector2f pos, mineralType mineral)
  : _type(mineral)
{
  if (!_texture.loadFromFile(imagePath))
    std::cerr << "Error on loading texture" << std::endl;
  else
    {
      _sprite.setTexture(_texture);
      _sprite.setTextureRect(subRect);
      _sprite.setPosition(pos);
    }
  if (!_font.loadFromFile("ressources/arial.ttf"))
    std::cerr << "Error on loading the font" << std::endl;
  _text.setFont(_font);
  _text.setColor(sf::Color::White);
  _text.setStyle(sf::Text::Bold);
  _text.setString(" ");
  _text.setCharacterSize(20);
}

Mineral::~Mineral()
{

}

sf::Sprite	Mineral::getSprite() const
{
  return (_sprite);
}

sf::Text	Mineral::getText() const
{
  return (_text);
}

void		Mineral::displayText(int nbToDisplay)
{
  std::ostringstream	oss;

  oss << nbToDisplay;
  _text.setPosition(_sprite.getPosition().x + 20, _sprite.getPosition().y + 5);
  _text.setString(oss.str());
}

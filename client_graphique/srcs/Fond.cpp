//
// Fond.cpp for FOnd in /home/genaud_p/SystemeUnix/client_graphique_zappy/zappy_graphic/graphics
// 
// Made by Pierre Genaudeau
// Login   <genaud_p@epitech.net>
// 
// Started on  Mon Jun 30 17:18:31 2014 Pierre Genaudeau
// Last update Sat Jul 12 20:42:12 2014 Pierre Genaudeau
//

#include	"Fond.hpp"
#include	<iostream>

Fond::Fond(const std::string imagePath, sf::IntRect subRect, sf::Vector2f pos)
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
  _text.setCharacterSize(20);
  _text2.setFont(_font);
  _text2.setColor(sf::Color::White);
  _text2.setStyle(sf::Text::Bold);
  _text2.setCharacterSize(20);
}

Fond::~Fond()
{

}

sf::Sprite	Fond::getSprite() const
{
  return (_sprite);
}

sf::Text	Fond::getText() const
{
  return (_text);
}

sf::FloatRect	Fond::getBoundingBox() const
{
  return (_sprite.getGlobalBounds());
}

void		Fond::move(float X, float Y)
{
  _sprite.move(X, Y);
}

void		Fond::displayText(const std::string team)
{
  _text.setPosition(_sprite.getPosition().x + 20, _sprite.getPosition().y + 5);
  _text.setString(team);
}

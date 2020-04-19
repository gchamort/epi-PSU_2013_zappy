//
// Egg.cpp for Egg in /home/genaud_p/SystemeUnix/client_graphique_zappy/zappy_graphic/graphics
// 
// Made by Pierre Genaudeau
// Login   <genaud_p@epitech.net>
// 
// Started on  Fri Jul  4 12:02:41 2014 Pierre Genaudeau
// Last update Fri Jul 11 16:40:38 2014 Pierre Genaudeau
//

#include	"Egg.hpp"
#include	<iostream>

Egg::Egg(const std::string imagePath, sf::IntRect subRect, sf::Vector2f pos, int numero)
: _numero(numero)
{
  if (!_texture.loadFromFile(imagePath))
    std::cerr << "Error on laoding image" << std::endl;
  else
    {
      _sprite.setTexture(_texture);
      _sprite.setTextureRect(subRect);
      _sprite.setPosition(pos);
    }
}

Egg::~Egg()
{
}

sf::Sprite	Egg::getSprite() const
{
  return (_sprite);
}

void		Egg::move(float X, float Y)
{
  _sprite.move(X, Y);
}

int		Egg::getNumero() const
{
  return (_numero);
}

float	Egg::getPosX() const
{
  return (_sprite.getPosition().x);
}

float	Egg::getPosY() const
{
  return (_sprite.getPosition().y);
}

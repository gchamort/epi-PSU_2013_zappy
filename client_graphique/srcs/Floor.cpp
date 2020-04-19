//
// Floo.cpp for Floor in /home/genaud_p/SystemeUnix/client_graphique_zappy
// 
// Made by Pierre Genaudeau
// Login   <genaud_p@epitech.net>
// 
// Started on  Mon Jun 30 15:13:56 2014 Pierre Genaudeau
// Last update Wed Jul  9 16:33:43 2014 Pierre Genaudeau
//

#include	"Floor.hpp"
#include	<iostream>

Floor::Floor(const std::string imagePath, sf::IntRect subRect, sf::Vector2f pos, int xGraph, int yGraph)
{
  _xGraph = xGraph;
  _yGraph = yGraph;
  if (!_texture.loadFromFile(imagePath))
    std::cerr << "Error on loading texture" << std::endl;
  else
    {
      _sprite.setTexture(_texture);
      _sprite.setTextureRect(subRect);
      _sprite.setPosition(pos);
    }
}

Floor::~Floor()
{

}

sf::Sprite	Floor::getSprite() const
{
  return (_sprite);
}

sf::FloatRect	Floor::getBoundingBox() const
{
  return (_sprite.getGlobalBounds());
}

void		Floor::move(float X, float Y)
{
  _sprite.move(X, Y);
}

int		Floor::getQuantity(int type) const
{
  if (type == 0)
    return (nbFood);
  if (type == 1)
    return (nbLinemate);
  if (type == 2)
    return (nbDeraumere);
  if (type == 3)
    return (nbSibur);
  if (type == 4)
    return (nbMendiane);
  if (type == 5)
    return (nbPhiras);
  if (type == 6)
    return (nbThystame);
  return (-1);
}

void		Floor::setQuantity(int type, int nb)
{
  if (type == 0)
    nbFood = nb;
  if (type == 1)
    nbLinemate = nb;
  if (type == 2)
    nbDeraumere = nb;
  if (type == 3)
    nbSibur = nb;
  if (type == 4)
    nbMendiane = nb;
  if (type == 5)
    nbPhiras = nb;
  if (type == 6)
    nbThystame = nb;
}

int		Floor::getXGraph() const
{
  return (_xGraph);
}

int		Floor::getYGraph() const
{
  return (_yGraph);
}

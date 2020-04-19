//
// Perso.cpp for Perso in /home/genaud_p/SystemeUnix/client_graphique_zappy
// 
// Made by Pierre Genaudeau
// Login   <genaud_p@epitech.net>
// 
// Started on  Mon Jun 30 15:21:07 2014 Pierre Genaudeau
// Last update Sun Jul 13 18:17:51 2014 Pierre Genaudeau
//

#include	"Perso.hpp"
#include	<iostream>

Perso::Perso(const std::string imagePath, int numero, sf::Vector2f pos, int orientation, const std::string team, float xMap, float yMap)
  : _orientation(orientation), _team(team), _level(1), _numero(numero), _xMap(xMap), _yMap(yMap)
{
  sf::IntRect	subRect;

  if (orientation == 1)
    subRect = sf::IntRect(34, 96, 34, 59);
  if (orientation == 2)
    subRect = sf::IntRect(102, 96, 34, 59);
  if (orientation == 3)
    subRect = sf::IntRect(0, 96, 34, 59);
  if (orientation == 4)
    subRect = sf::IntRect(68, 96, 34, 59);
  if (!_texture.loadFromFile(imagePath))
    std::cerr << "Error on loading texture" << std::endl;
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
  nbFood = 0;
  nbLinemate = 0;
  nbDeraumere = 0;
  nbSibur = 0;
  nbMendiane = 0;
  nbPhiras = 0;
  nbThystame = 0;
}

Perso::~Perso()
{
}

void		Perso::move(float X, float Y)
{
  _sprite.move(X, Y);
}

sf::Sprite	Perso::getSprite() const
{
  return (_sprite);
}

void	Perso::checkOrientation()
{
  if (_orientation == 1)
    _sprite.setTextureRect(sf::IntRect(34, 96, 34, 59));
  if (_orientation == 2)
    _sprite.setTextureRect(sf::IntRect(102, 96, 34, 59));
  if (_orientation == 3)
    _sprite.setTextureRect(sf::IntRect(0, 96, 34, 59));
  if (_orientation == 4)
    _sprite.setTextureRect(sf::IntRect(68, 96, 34, 59));
}

sf::FloatRect	Perso::getBoundingBox() const
{
  return (_sprite.getGlobalBounds());
}

int	Perso::getOrientation() const
{
  return (_orientation);
}

void		Perso::setOrientation(int newOrientation)
{
  _orientation = newOrientation;
}

const std::string	Perso::getTeam() const
{
  return (_team);
}

int			Perso::getLevel() const
{
  return (_level);
}

void			Perso::setLevel(int level)
{
  _level = level;
}

int			Perso::getNumero() const
{
  std::cout << "fin du getNumero" << std::endl;
  return (_numero);
}

void			Perso::setPosition(float x, float y)
{
  _sprite.setPosition(x, y);
}

float			Perso::getXMap() const
{
  return (_xMap);
}

float			Perso::getYMap() const
{
  return (_yMap);
}

int		Perso::getQuantity(int type) const
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

void		Perso::setQuantity(int type, int nb)
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

sf::Text		Perso::getText() const
{
  return (_text);
}

void			Perso::displayText(int level)
{
  std::ostringstream		oss;

  oss << level;
  _text.setPosition(_sprite.getPosition().x + 11, _sprite.getPosition().y - 20);
  _text.setString(oss.str());
}

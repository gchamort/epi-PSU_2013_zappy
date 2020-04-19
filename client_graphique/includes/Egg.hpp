//
// Egg.hpp for Egg in /home/genaud_p/SystemeUnix/client_graphique_zappy/zappy_graphic/graphics
// 
// Made by Pierre Genaudeau
// Login   <genaud_p@epitech.net>
// 
// Started on  Fri Jul  4 12:02:51 2014 Pierre Genaudeau
// Last update Fri Jul 11 16:41:10 2014 Pierre Genaudeau
//

#ifndef	EGG_HPP_
#define	EGG_HPP_

#include	<SFML/Graphics.hpp>

class	Egg
{
public:
  Egg(const std::string imagePath, sf::IntRect subRect, sf::Vector2f pos, int numero);
  ~Egg();
  sf::Sprite	getSprite() const;
  void		move(float X, float Y);
  int		getNumero() const;
  float		getPosX() const;
  float		getPosY() const;
private:
  sf::Texture	_texture;
  sf::Sprite	_sprite;
  int		_numero;
};

#endif

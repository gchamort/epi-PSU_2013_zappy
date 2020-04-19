//
// fond.hpp for fond in /home/genaud_p/SystemeUnix/client_graphique_zappy/zappy_graphic/graphics
// 
// Made by Pierre Genaudeau
// Login   <genaud_p@epitech.net>
// 
// Started on  Mon Jun 30 17:14:10 2014 Pierre Genaudeau
// Last update Mon Jun 30 17:17:05 2014 Pierre Genaudeau
//

#ifndef	FOND_HPP_
#define	FOND_HPP_

class	Fond
{
  Fond(const std::string imagePath, sf::IntRect subRect, sf::Vector2f pos);
  ~Fond();
  sf::Sprite	getSprite() const;
  sf::FloatRect	getBoundingBox() const;
  void		move(float X, float Y);
private:
  sf::Texture	_texture;
  sf::Sprite	_sprite;
};

#endif

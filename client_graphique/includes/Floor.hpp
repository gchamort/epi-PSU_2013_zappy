//
// Floor.hpp for Floor in /home/genaud_p/SystemeUnix/client_graphique_zappy
// 
// Made by Pierre Genaudeau
// Login   <genaud_p@epitech.net>
// 
// Started on  Mon Jun 23 16:02:49 2014 Pierre Genaudeau
// Last update Tue Jul  8 17:06:38 2014 Pierre Genaudeau
//

#ifndef	FLOOR_HPP_
#define	FLOOR_HPP_

#include	<SFML/Graphics.hpp>

class	Floor
{
public:
  Floor(const std::string imagePath, sf::IntRect subRect, sf::Vector2f pos, int xGraph, int yGraph);
  ~Floor();
  sf::Sprite	getSprite() const;
  sf::FloatRect	getBoundingBox() const;
  void		move(float X, float Y);
  int		getQuantity(int type) const;
  void		setQuantity(int type, int nb);
  int		getXGraph() const;
  int		getYGraph() const;
private:
  sf::Texture	_texture;
  sf::Sprite	_sprite;
  int		nbFood;
  int		nbLinemate;
  int		nbDeraumere;
  int		nbSibur;
  int		nbMendiane;
  int		nbPhiras;
  int		nbThystame;
  int		_xGraph;
  int		_yGraph;
};

#endif

//
// Perso.hpp for Perso in /home/genaud_p/SystemeUnix/client_graphique_zappy
// 
// Made by Pierre Genaudeau
// Login   <genaud_p@epitech.net>
// 
// Started on  Mon Jun 23 16:29:07 2014 Pierre Genaudeau
// Last update Sat Jul 12 20:42:37 2014 Pierre Genaudeau
//

#ifndef	PERSO_HPP_
#define	PERSO_HPP_

#include	<SFML/Graphics.hpp>
#include	<sstream>

class	Perso
{
public:
  enum	Orientation{N = 1, E = 2, S = 3, O = 4};
  Perso(const std::string imagePath, int numero, sf::Vector2f pos, int orientation, const std::string team, float xMap, float yMap);
  ~Perso();
  void		move(float X, float Y);
  sf::Sprite	getSprite() const;
  sf::FloatRect	getBoundingBox() const;
  void	checkOrientation();
  int	getOrientation() const;
  void		setOrientation(int newOrientation);
  const std::string	getTeam() const;
  int			getLevel() const;
  void			setLevel(int level);
  int			getNumero() const;
  void			setPosition(float x, float y);
  float			getXMap() const;
  float			getYMap() const;
  int			getQuantity(int type) const;
  void			setQuantity(int type, int nb);
  sf::Text		getText() const;
  void			displayText(int level);
private:
  sf::Texture	_texture;
  sf::Sprite	_sprite;
  int	_orientation;
  const std::string	_team;
  int			_level;
  int			_numero;
  float			_xMap;
  float			_yMap;
  int			nbFood;
  int			nbLinemate;
  int			nbDeraumere;
  int			nbSibur;
  int			nbMendiane;
  int			nbPhiras;
  int			nbThystame;
  sf::Font		_font;
  sf::Text		_text;
};

#endif

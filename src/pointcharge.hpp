#pragma once

#include <SFML/Graphics.hpp>

class PointCharge {
public:
  PointCharge();
  PointCharge(sf::Vector2i p, double charge);
  void draw(sf::RenderWindow& window);
  double getCharge();
  sf::Vector2i getPoint();
  void setPoint(sf::Vector2i point);
private:
  sf::Vector2i point;
  double charge;
  sf::CircleShape shape;
  void setupColor();
};

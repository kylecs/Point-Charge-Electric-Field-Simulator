#pragma once

#include <vector>
#include <SFML/Graphics.hpp>
#include "./pointcharge.hpp"

class FieldIndicator{
public:
  FieldIndicator(int x = 0, int y = 0);
  int getX();
  int getY();
  int getDX();
  int getDY();
  void update(std::vector<PointCharge>&);
  void draw(sf::RenderWindow& window);
private:
  int x, y;
  int dx, dy;
  sf::Vertex line[2];
  sf::CircleShape baseCircle;
};

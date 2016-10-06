#include "./fieldindicator.hpp"
#include <math.h>
#include "./config.hpp"
#include <iostream>
#include <algorithm>

using namespace std;

FieldIndicator::FieldIndicator(int x, int y) {
  cout << "Calling constructor" << endl;
  this->x = x;
  this->y = y;
  this->dx = 0;
  this->dy = 0;
  line[0] = sf::Vertex(sf::Vector2f(x, y));
  line[1] = sf::Vertex(sf::Vector2f(x + dx, y + dy));
  this->baseCircle.setPosition(x - 2, y - 2);
  this->baseCircle.setRadius(2);
  this->baseCircle.setFillColor(sf::Color::White);
}

int FieldIndicator::getX() {
  return x;
}

int FieldIndicator::getY() {
  return y;
}

int FieldIndicator::getDX() {
  return dx;
}

int FieldIndicator::getDY() {
  return dy;
}

void FieldIndicator::update(std::vector<PointCharge>& charges) {
  cout << "Calling update" << endl;
  double xField = 0;
  double yField = 0;
  for (auto charge : charges) {
    double diffX = this->x - charge.getPoint().x;
    double diffY = this->y - charge.getPoint().y;
    double theta = atan(abs(diffY / diffX));
    double totalField = (K * charge.getCharge()) / sqrt(pow(diffX, 2) + pow(diffY, 2));
    double xFieldMagnitude = totalField * cos(theta);
    double yFieldMagnitude = totalField * sin(theta);
    if(diffY > 0) {
      //top half
      yField += yFieldMagnitude;
    }else {
      //bottom half
      yField -= yFieldMagnitude;
    }
    if(diffX < 0) {
      //right half
      xField -= xFieldMagnitude;
    }else {
      //left half
      xField += xFieldMagnitude;
    }

  }
  this->dx = xField * vectorScale;
  this->dy = yField * vectorScale;
  double length = sqrt((pow(dx, 2) + pow(dy, 2)));
  if(length > 0){
    double scaledLength = min(length, (double) 20);
    this->dx = dx * scaledLength / length;
    this->dy = dy * scaledLength / length;
  }else {
    this->dx = 0;
    this->dy = 0;
  }

  cout << "DX: " << this->dx << " DY: " << this->dy << endl;
  this->line[1].position = sf::Vector2f(x + dx, y + dy);
}

void FieldIndicator::draw(sf::RenderWindow& window) {
  cout << "Calling draw" << endl;
  window.draw(line, 10, sf::Lines);
  window.draw(baseCircle);
}

#include "pointcharge.hpp"
PointCharge::PointCharge() {
  this->charge = 0;
  this->point = sf::Vector2i(100, 100);
  this->shape.setPosition((float)point.x - 8, (float)point.y - 8);
  this->shape.setRadius(16);
  this->setupColor();
}

PointCharge::PointCharge(sf::Vector2i p, double charge){
  this->charge = charge;
  this->point = p;
  this->shape.setPosition((float)point.x - 8, (float)point.y - 8);
  this->shape.setRadius(16);
  this->setupColor();
}

void PointCharge::draw(sf::RenderWindow& window) {
  window.draw(shape);
}

void PointCharge::setupColor() {
  if(this->charge > 0)
  {
    shape.setFillColor(sf::Color::Red);
  }else if(this->charge == 0)
  {
    shape.setFillColor(sf::Color::Green);
  }else
  {
    shape.setFillColor(sf::Color::Blue);
  }
}

double PointCharge::getCharge() {
  return charge;
}

sf::Vector2i PointCharge::getPoint() {
  return this->point;
}

void PointCharge::setPoint(sf::Vector2i point) {
  this->point = point;
  this->shape.setPosition((float)point.x - 8, (float)point.y - 8);

}

#include <iostream>
#include <math.h>
#include <vector>
#include <SFML/Graphics.hpp>
#include "./pointcharge.hpp"
#include "./fieldindicator.hpp"

using namespace std;

int main() {
  sf::Font font;

  if(!font.loadFromFile("Oxygen-Sans.ttf")) {
    cout << "Could not load font!" << endl;
    return -1;
  }

  sf::RenderWindow window(sf::VideoMode(1280, 1024),
    "Charge Simulator");
  window.setFramerateLimit(24);

  vector<PointCharge> charges;
  vector<FieldIndicator> indicators;

  charges.push_back(PointCharge(sf::Vector2i(100, 500), 1));
  charges.push_back(PointCharge(sf::Vector2i(700, 700), -1));


  for(int x = 0; x < 1280; x += 35) {
    for(int y = 0; y < 1024; y += 35) {
      indicators.push_back(FieldIndicator(x, y));
    }
  }

  while (window.isOpen()) {
    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
        window.close();
        break;
      }
    }

    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
    charges[0].setPoint(mousePos);

    //clear screen
    window.clear(sf::Color::Black);

    //draw indicators
    for(unsigned int i = 0; i < indicators.size(); i++) {
      indicators[i].update(charges);
      indicators[i].draw(window);
    }

    //draw charges
    for(unsigned int i = 0; i < charges.size(); i++) {
      charges[i].draw(window);
    }

    //display
    window.display();
  }
  return 0;
}

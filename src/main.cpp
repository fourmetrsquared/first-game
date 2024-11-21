#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;

auto main(int argc, char *argv[]) -> int {
  RenderWindow window(VideoMode(200, 200), "My game", Style::Fullscreen);

  Image image;
  image.loadFromFile(
      "./textures/Factions/Knights/Troops/Warrior/Purple/Warrior_Purple.png");

  Texture texture;
  texture.loadFromImage(image);

  Sprite sprite;
  sprite.setTexture(texture);
  sprite.setTextureRect(IntRect(0, 0, 144, 144));
  while (window.isOpen()) {
    Event event;

    while (window.pollEvent(event)) {
      if (event.type == Event::Closed) {
        window.close();
      }
    }

    window.clear(Color(69, 70, 88));
    window.draw(sprite);
    window.display();
  }

  return 0;
}

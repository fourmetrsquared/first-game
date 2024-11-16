#include <SFML/Graphics.hpp>
using namespace sf;
int main() {
  RenderWindow window(VideoMode(640, 480), "Landscape");
  // земля
  RectangleShape ground(Vector2f(640, 250));
  ground.setFillColor(Color::Yellow);
  ground.setPosition(0, 350);

  // солнце
  CircleShape sun(40);
  sun.setFillColor(Color(217, 55, 26));
  sun.setPosition(50, 30);

  // гора
  CircleShape mountain(200, 3);
  mountain.setFillColor(Color(214, 128, 58));
  mountain.setPosition(350, 50);

  // кактус из 4-х частей
  RectangleShape cactusBody(Vector2f(40, 250));
  cactusBody.setFillColor(Color::Green);
  cactusBody.setPosition(100, 200);

  RectangleShape cactusArms(Vector2f(120, 30));
  cactusArms.setFillColor(Color::Green);
  cactusArms.setPosition(60, 300);

  RectangleShape cactusLeftHand(Vector2f(25, 60));
  cactusLeftHand.setFillColor(Color::Green);
  cactusLeftHand.setPosition(60, 250);

  RectangleShape cactusRightHand(Vector2f(25, 60));
  cactusRightHand.setFillColor(Color::Green);
  cactusRightHand.setPosition(155, 250);

  // скорость и направление солнца
  float speed = 1;
  float direction = 1;

  // загрузка текстуры персонажа
  Image hero_image;
  hero_image.loadFromFile("../images/horse.png");

  Texture hero_texture;
  hero_texture.loadFromImage(hero_image);

  Sprite hero_sprite;
  hero_sprite.setTexture(hero_texture);
  hero_sprite.setPosition(200, 300);
  hero_sprite.setTextureRect(IntRect(0, 160, 80, 80));

  while (window.isOpen()) {
    Event event;

    while (window.pollEvent(event)) {
      if (event.type == Event::Closed) {
        window.close();
      }
    }
    if (sun.getPosition().x > 600) {
      direction = -1;
    }

    if (sun.getPosition().x < 40) {
      direction = 1;
    }

    sun.move(speed * direction, 0);

    window.clear(Color(108, 235, 235));
    window.draw(ground);     // Отрисовываем землю
    window.draw(sun);        // Отрисовываем солнце
    window.draw(mountain);   // Отрисовываем гору
    window.draw(cactusBody); // Отрисовываем кактус
    window.draw(cactusArms);
    window.draw(cactusLeftHand);
    window.draw(cactusRightHand);

    window.draw(hero_sprite); // отрисовываем персонажа

    window.display();
  }

  return 0;
}

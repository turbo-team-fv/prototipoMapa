#include "juego.h"

juego::juego(Vector2i dimension, std::string titulo) {

    fps = 60;

    ventana1 = new RenderWindow(VideoMode(dimension.x, dimension.y), titulo);

    ventana1->setFramerateLimit(fps);

    evento1 = new Event;

    txt1 = new Texture;

    txt1->loadFromFile("assets/mapa.png");

    spr1 = new Sprite(*txt1); // carga del sprite a la cual se le pasa la textura

    spr1->setOrigin(spr1->getTexture()->getSize().x / 2.f, spr1->getTexture()->getSize().y / 2.f);

    spr1->setPosition(400,300);

    spr1->setScale(1.5, 1.5); // lo escala un 50%

    gameLoop();

}

void juego::gameLoop()
{

    while(ventana1->isOpen())
    {
        procesarEventos();
        dibujar();

    }
}

void juego::dibujar() {

    ventana1->clear();

    ventana1->draw(*spr1);

    ventana1->display();
}

void juego::procesarEventos() {

    while(ventana1->pollEvent(*evento1))
    {
        switch(evento1->type) {

            case Event::Closed:

                ventana1->close();
                exit(1);
                break;

            case Event::KeyPressed:

                if(Keyboard::isKeyPressed(Keyboard::W))
                {
                    spr1->setPosition(spr1->getPosition().x, spr1->getPosition().y + 5);
                }

                if(Keyboard::isKeyPressed(Keyboard::S))
                {
                    spr1->setPosition(spr1->getPosition().x, spr1->getPosition().y - 5);
                }

                if(Keyboard::isKeyPressed(Keyboard::A))
                {
                    spr1->setPosition(spr1->getPosition().x + 5, spr1->getPosition().y);
                }

                if(Keyboard::isKeyPressed(Keyboard::D))
                {
                    spr1->setPosition(spr1->getPosition().x - 5, spr1->getPosition().y);
                }

        }
    }

}

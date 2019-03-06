#pragma once
#include "SFML/Graphics.hpp"

using namespace sf;

class juego
{
    public:
        juego(Vector2i dimension, std::string titulo);
        void gameLoop();
        void dibujar();
        void procesarEventos();

    private:

        RenderWindow * ventana1;
        int fps;

        Texture * txt1;
        Sprite * spr1;
        Texture * txt2;
        Sprite * spr2;
        Event * evento1;
};

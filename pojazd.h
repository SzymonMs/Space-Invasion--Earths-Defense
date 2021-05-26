#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include<iostream>
class Pojazd:public sf::Sprite
{

    protected:
    sf::Texture texture_;
    int v_x_=130;
    int v_y_=30;

public:
    Pojazd()=default;
   // void load_texture(const std::string& file_name);
    //void poruszanie();
};

#pragma once
#include <SFML/Window.hpp>
#include<SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include<iostream>

class Bomb: public sf::Sprite
{
public:
    Bomb();
    Bomb(int k);
    void load_texture(const std::string& file_name);
    void poruszanie(sf::Time elapsed);
    void niszczenie(sf::RenderWindow &window,const sf::Event event,int &a);
private:
    sf::Texture texture_;
    int v_x_=0;
    int v_y_=400;
};


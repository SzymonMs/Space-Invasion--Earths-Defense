#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include<iostream>

class Alien : public sf::Sprite
{
private:
    sf::Texture texture_;
    int v_x_=130;
    int v_y_=30;

public:
    void load_texture(const std::string& file_name);
    void niszczenie(sf::RenderWindow &window,const sf::Event event,int &a);
    void poruszanie(sf::Time elapsed,int &a,int &b);
    void set_v(int vx,int vy);
    Alien();
    Alien(int k);




};

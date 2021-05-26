#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include<iostream>
class Button : public sf::RectangleShape
{
public:
    Button(float pos_x,float pos_y, float size_x,float size_y,const std::string &nazwa_pliku);
    void load_texture(const std::string& file_name);
    void zamykanie(sf::RenderWindow &window,const sf::Event &event);
    void instrukcja(sf::RenderWindow &window,const sf::Event &event);
     void startowanie(sf::RenderWindow &window,const sf::Event &event,int &a,int &b);
     void jeszcze_raz(sf::RenderWindow &window, const sf::Event &event,int &a,int &b,int &c);
private:
    sf::Texture texture_;
};


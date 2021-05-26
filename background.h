#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include<iostream>

class Background : public sf::Sprite
{
private:
sf::Texture texture_;
public:
void load_texture(const std::string& file_name);
Background(const std::string &nazwa_pliku);

};

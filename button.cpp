#include "include.h"

Button::Button(float pos_x,float pos_y, float siz_x,float siz_y,const std::string &nazwa_pliku)
{
    setPosition(pos_x,pos_y);
    setSize(sf::Vector2f(siz_x,siz_y));
    load_texture(nazwa_pliku);


}
void Button:: load_texture(const std::string& file_name)
{
    if (!texture_.loadFromFile(file_name)) {
        std::cerr << "Could not load texture" << std::endl;
    }
    else
    {
        setTexture(&texture_);

    }
}

void Button::zamykanie(sf::RenderWindow &window,const sf::Event &event)
{
    if (event.type == sf::Event::MouseButtonPressed) {
        if(event.mouseButton.button == sf::Mouse::Left) {
            sf::Vector2i mouse_pos = sf::Mouse::getPosition(window);
            sf::FloatRect bounds = getGlobalBounds();
            if(bounds.left<=mouse_pos.x && bounds.left+bounds.width>=mouse_pos.x)
            {
                if(bounds.top<=mouse_pos.y && bounds.top+bounds.height>=mouse_pos.y)
                {

window.close();
                }
            }
        }


}
}

void Button::startowanie(sf::RenderWindow &window, const sf::Event &event,int &a,int &b)
{

    if (event.type == sf::Event::MouseButtonPressed) {
        if(event.mouseButton.button == sf::Mouse::Left) {
            sf::Vector2i mouse_pos = sf::Mouse::getPosition(window);
            sf::FloatRect bounds = getGlobalBounds();
            if(bounds.left<=mouse_pos.x && bounds.left+bounds.width>=mouse_pos.x)
            {
                if(bounds.top<=mouse_pos.y && bounds.top+bounds.height>=mouse_pos.y)
                {

a++;
b++;
                }
            }
        }


}
}
void Button::instrukcja(sf::RenderWindow &window, const sf::Event &event)
{
    Background tlo_instrukcji("tlo_instrukcji.png");
   // Button przycisk_start(0,520,200,80,"przycisk_start.png");
    if (event.type == sf::Event::MouseButtonPressed) {
        if(event.mouseButton.button == sf::Mouse::Left) {
            sf::Vector2i mouse_pos = sf::Mouse::getPosition(window);
            sf::FloatRect bounds = getGlobalBounds();
            if(bounds.left<=mouse_pos.x && bounds.left+bounds.width>=mouse_pos.x)
            {
                if(bounds.top<=mouse_pos.y && bounds.top+bounds.height>=mouse_pos.y)
                {
                    window.draw(tlo_instrukcji);


                }
            }
        }


}
}
void Button::jeszcze_raz(sf::RenderWindow &window, const sf::Event &event,int &a, int &b, int &c)
{
    if (event.type == sf::Event::MouseButtonPressed) {
        if(event.mouseButton.button == sf::Mouse::Left) {
            sf::Vector2i mouse_pos = sf::Mouse::getPosition(window);
            sf::FloatRect bounds = getGlobalBounds();
            if(bounds.left<=mouse_pos.x && bounds.left+bounds.width>=mouse_pos.x)
            {
                if(bounds.top<=mouse_pos.y && bounds.top+bounds.height>=mouse_pos.y)
                {

                    a=-1;
                    b=-1;
                    c=0;

                }
            }
        }


}

}


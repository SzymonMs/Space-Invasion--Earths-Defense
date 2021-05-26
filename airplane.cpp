#include "include.h"

void Airplane:: load_texture(const std::string& file_name)
    {
        if (!texture_.loadFromFile(file_name)) {
            std::cerr << "Could not load texture" << std::endl;
        }
        else
        {
            setTexture(texture_);
            setPosition(70,400);
            setScale(0.18,0.2);
        }
    }
void Airplane:: poruszanie(sf::Time elapsed,int &a)
{

     int vx=v_x_*std::abs(a+3);
    sf::FloatRect ufo_bounds = getGlobalBounds();
    move(vx*elapsed.asSeconds(),v_y_*elapsed.asSeconds());

    if(ufo_bounds.left>=810)
    {
       setPosition(-300,int((500+1) * rand()/(RAND_MAX+1.0)));
       move(vx*elapsed.asSeconds(),v_y_*elapsed.asSeconds());

    }
}
void Airplane::niszczenie(sf::RenderWindow &window, const sf::Event event, int &a)
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
                    setPosition(-300,int((500+1) * rand()/(RAND_MAX+1.0)));






                }
            }
        }

    }
}
Airplane::Airplane()
{
        load_texture("samolot.png");
       setPosition(-300,int((500+1) * rand()/(RAND_MAX+1.0)));
}
void Airplane::set_v(int vx, int vy)
{
    v_x_=vx;
    v_y_=vy;
}

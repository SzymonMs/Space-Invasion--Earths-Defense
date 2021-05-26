#include "include.h"

void Alien:: load_texture(const std::string& file_name)
    {
        if (!texture_.loadFromFile(file_name)) {
            std::cerr << "Could not load texture" << std::endl;
        }
        else
        {
            setTexture(texture_);

        }
    }
void Alien:: poruszanie(sf::Time elapsed,int &a,int &b)
{

    int vx=v_x_*std::abs(a+2);
    float vy=v_y_*std::abs(a+2);
    sf::FloatRect ufo_bounds = getGlobalBounds();
    if(a<9)
    {
    move(vx*elapsed.asSeconds(),v_y_*elapsed.asSeconds());
    }
    if(a>=9&&a<12)
    {
        move(vx*elapsed.asSeconds(),vy*elapsed.asSeconds());
    }

    if(ufo_bounds.left>=810)
    {
       setPosition(-300,int((500+1) * rand()/(RAND_MAX+1.0)));
       move(vx*elapsed.asSeconds(),v_y_*elapsed.asSeconds());
      b++;

    }
}

void Alien:: niszczenie(sf::RenderWindow &window, const sf::Event event, int &a)
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
                    setPosition(-300,int((350+1) * rand()/(RAND_MAX+1.0)));





                }
            }
        }
    }
}
Alien ::Alien()
{
    load_texture("ufo.png");
    setPosition(-300,int((500+1) * rand()/(RAND_MAX+1.0)));
    setScale(0.8,0.8);

}
Alien::Alien(int k)
{
    load_texture("ufo.png");
    setPosition(-400,int((400+1) * rand()/(RAND_MAX+1.0)));
    setScale(0.8,0.8);
}
void Alien::set_v(int vx, int vy)
{
    v_x_=vx;
    v_y_=vy;
}


#include "include.h"
void Bomb:: load_texture(const std::string& file_name)
    {
        if (!texture_.loadFromFile(file_name)) {
            std::cerr << "Could not load texture" << std::endl;
        }
        else
        {
            setTexture(texture_);

        }
    }
Bomb::Bomb()
{
    load_texture("nuke.png");
   // setPosition(100,200);
  setPosition(int((500+1) * rand()/(RAND_MAX+1.0)),-300);
}
Bomb::Bomb(int k)
{
   load_texture("nuke.png");
   setPosition(int((700+1) * rand()/(RAND_MAX+1.0)),-500);

}
void Bomb::poruszanie(sf::Time elapsed)
{
    sf::FloatRect bomb_bounds = getGlobalBounds();
    move(v_x_*elapsed.asSeconds(),v_y_*elapsed.asSeconds());
    if(bomb_bounds.top>=610)
    {
       setPosition(int((500+1) * rand()/(RAND_MAX+1.0)),-300);
       move(v_x_*elapsed.asSeconds(),v_y_*elapsed.asSeconds());


    }
}

void Bomb::niszczenie(sf::RenderWindow &window, const sf::Event event, int &a)
{
    sf::Vector2i mouse_pos = sf::Mouse::getPosition(window);
    sf::FloatRect bounds = getGlobalBounds();
    if(bounds.left<=mouse_pos.x && bounds.left+bounds.width>=mouse_pos.x)
    {
        if(bounds.top<=mouse_pos.y && bounds.top+bounds.height>=mouse_pos.y)
        {

            a++;
            setPosition(-300,int((400+1) * rand()/(RAND_MAX+1.0)));



        }
    }
}

#include "include.h"

void Background:: load_texture(const std::string& file_name)
    {
        if (!texture_.loadFromFile(file_name)) {
            std::cerr << "Could not load texture" << std::endl;
        }
        else
        {
            setTexture(texture_);

        }
    }
Background::Background(const std::string &nazwa_pliku)
{
    load_texture(nazwa_pliku);
}

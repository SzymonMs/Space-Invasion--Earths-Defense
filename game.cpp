#include"include.h"

Game::Game()
{
    int licznik_ufo=-1;
    int licznik_samolotow=-1;


    sf::RenderWindow window(sf::VideoMode(800, 600), "Space Invasion- Earth's Defense");
    window.setFramerateLimit(60);
    Background tlo("tlo.png");
    Background tlo_porazki("tlo_porazki.png");
    Background tlo_wygranej("tlo_wygranej.png");
    Background tlo_start("tlo_start.png");
    Alien ufo;

    Airplane samolot;
    Bomb bomba;
    Bomb bomba2(1);

    Button przycisk_start(304,261,200,80,"przycisk_start.png");
    Button przycisk_raz(304,261,200,80,"przycisk_start.png");
    Button przycisk_zamknij(304,321,200,80,"przycisk_zamknij.png");
    Button przycisk_instrukcji(304,401,200,80,"przycisk_instrukcji.png");

    sf::Clock clock;

    sf::Music music;
    if (!music.openFromFile("music.ogg"))
        std::cout<< -1; // error
    music.play();


    sf::Font ttf;
      ttf.loadFromFile("Sansation_Bold.ttf");
      std::string s("");
      sf::Text txt(s,ttf);
      txt.setCharacterSize(20);
      txt.setFillColor(sf::Color::White);
      txt.setPosition(0,0);
      std::stringstream ss;




    while (window.isOpen()) {

        sf::Event event;
        while (window.pollEvent(event)) {

            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::Resized)
                    {
                        window.setSize(sf::Vector2u(800,600));
                    }

            ufo.niszczenie(window,event,licznik_ufo);

            samolot.niszczenie(window,event,licznik_samolotow);
            bomba.niszczenie(window,event,licznik_samolotow);
            bomba2.niszczenie(window,event,licznik_samolotow);
        }
        sf::Time elapsed = clock.restart();
        window.clear(sf::Color::Black);
        if(licznik_ufo==-1&&licznik_samolotow==-1)
        {

            window.draw(tlo);
            window.draw(przycisk_start);
            window.draw(przycisk_zamknij);
            window.draw(przycisk_instrukcji);
            przycisk_instrukcji.instrukcja(window,event);
            przycisk_zamknij.zamykanie(window,event);
            przycisk_start.startowanie(window,event,licznik_ufo,licznik_samolotow);



        }


        if(licznik_samolotow<4&&licznik_samolotow>=0)
        {
            ufo.poruszanie(elapsed,licznik_ufo,licznik_samolotow);
            samolot.poruszanie(elapsed,licznik_samolotow);
            bomba.poruszanie(elapsed);
            bomba2.poruszanie(elapsed);
            window.draw(tlo);
            window.draw(ufo);
            window.draw(samolot);
            window.draw(bomba);
            window.draw(bomba2);
            ss.str("");
                    ss << "Ufo: "<<licznik_ufo<<"                  Pozostale zycia: "<<4-licznik_samolotow;
                    txt.setString(ss.str());
               window.draw(txt);


        }



        if(licznik_ufo==12)
        {

            window.draw(tlo_wygranej);
            Button przycisk(0,520,200,80,"przycisk_zamknij.png");
            window.draw(przycisk);
            przycisk.zamykanie(window,event);
            ufo.set_v(0,0);
            samolot.set_v(0,0);
            ufo.setPosition(-1000,-1000);
            samolot.setPosition(-1000,-1000);
            ss.str("");
                    ss << "Ufo: "<<licznik_ufo<<"                  Pozostale zycia: "<<4-licznik_samolotow;
                    txt.setString(ss.str());
               window.draw(txt);
        }

        if(licznik_samolotow==4)
        {
            window.draw(tlo_porazki);
            Button przycisk(0,520,200,80,"przycisk_zamknij.png");
            samolot.setPosition(-1000,-1000);
            ufo.setPosition(-1000,-1000);
            ufo.set_v(0,0);
            samolot.set_v(0,0);
            window.draw(przycisk);
            przycisk.zamykanie(window,event);
            ss.str("");
                     ss << "Ufo: "<<licznik_ufo<<"                  Pozostale zycia: "<<4-licznik_samolotow;
                    txt.setString(ss.str());
               window.draw(txt);
        }

        window.display();
        std::cout<<licznik_ufo<<" "<<licznik_samolotow<<std::endl;
    }
}

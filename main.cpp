#include <SFML/Graphics.hpp>
#include <iostream>
int main()
{
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "Prototyping");
    sf::CircleShape shape(100.f);
    sf::Text hello;
    sf::Font MyFont;
    MyFont.loadFromFile("C:\\VSC\\ff\\proj\\src\\fonts\\BlackFlag.ttf");
    hello.setFont(MyFont);
    shape.setFillColor(sf::Color::Green);
    shape.setOrigin(100,100);
    sf::Texture charspri;
    if(!charspri.loadFromFile("C:\\VSC\\ff\\proj\\src\\sprites\\wip.png"))
    {
        std::cout << "Error loading sprite" << std::endl;
        system("pause");
    }
    sf::Sprite character;
    character.setTexture(charspri);
    character.setScale(0.2f,0.2f);
    character.setOrigin(1050,1300);
    //character.setOrigin()
    hello.setString("FUCK SCHOOL");
    hello.setCharacterSize(24.f);
    hello.setFillColor(sf::Color::White);
    int xx;
    int yy = 500;
    while (window.isOpen())
    {
        
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                    window.close();
            }
            if (event.type == sf::Event::MouseButtonPressed)
            {
                shape.setFillColor(sf::Color::Red);
            }
             if (event.type == sf::Event::MouseButtonReleased)
            {
                shape.setFillColor(sf::Color::Green);
            }
            if(event.type == sf::Event::KeyPressed)
            {
                if(event.key.code == sf::Keyboard::D)
                {
                    xx++;
                }

            }
        }
        window.clear();
        hello.setPosition(400,400);
        window.draw(shape);
        window.draw(hello);
        window.draw(character);

        character.setPosition(xx,yy);
        window.display();

    }

    return 0;
}
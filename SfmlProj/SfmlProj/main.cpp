#include <SFML/Graphics.hpp>
#include<fstream>
#include<iostream>
#include"spriteManager.h"
using namespace sf;
using namespace std;
int main()
{
    bool isMove = false;
	
	

    sf::RenderWindow window(sf::VideoMode(1280,720), "SFML works!");

    spriteManager a("C:/Users/IGOR/source/repos/SfmlProj/Resorse/goose.jpg",
        Vector2f(0.25,0.25), Vector2f(0, 0));
    a.read();
    
   
    while (window.isOpen())
    {
       
        Vector2i pixelPos = Mouse::getPosition(window);
        Vector2f pos = window.mapPixelToCoords(pixelPos);
		
        sf::Event event;
        while (window.pollEvent(event))
        {
           
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == Event::MouseButtonPressed)
                if (event.key.code == Mouse::Left)
                    if (a.getSprite().getGlobalBounds().contains(pos.x, pos.y)) {

                      
                        isMove = true;
                    }

            if (event.type == Event::MouseButtonReleased)
                if (event.key.code == Mouse::Left) {
                    std::cout << a.getSprite().getPosition().x << " " <<
                        a.getSprite().getPosition().y << std::endl;
                    a.write();
                   
                    isMove = false;

                }
           
		
            if (isMove == true) {
                a.move(Vector2f(pos.x,pos.y));
            }
         

        }
        
        
		window.clear();

		window.draw(a.getSprite());
        
		window.display();

    }

  
}


#pragma once
#include<iostream>
#include<vector>
#include <SFML/Graphics.hpp>
#include<fstream>
#include<string>
using namespace sf;
class spriteManager{
private:
	
	Texture texture;
	Sprite sprite;
	std::ofstream ofstrX;
	std::ofstream ofstrY;
	std::ifstream ifstr;
	int Xvalue;
	int Yvalue;
	
	public:
		std::string PositionX;
		std::string PositionY;
		spriteManager(std::string, Vector2f scale,
			Vector2f position);
	

	Sprite getSprite();

	void write() {
		ofstrX.open("testX.txt");
		ofstrY.open("testY.txt");
		ofstrX << sprite.getPosition().x << std::endl;
		ofstrY << sprite.getPosition().y << std::endl;
		std::cout << "WRITE" << std::endl;
	
		ofstrX.close();
		ofstrY.close();
	}
	void read() {
		ifstr.open("testX.txt");
		while (ifstr) {
			 
			ifstr >> PositionX;
		}
		Xvalue = std::stoi(PositionX);
		ifstr.close();
		ifstr.open("testY.txt");
		while (ifstr) {

			ifstr >> PositionY;
			
		}
		Yvalue = std::stoi(PositionY);
		ifstr.close();

		sprite.setPosition(Xvalue, Yvalue);


	}
	void move(Vector2f pos) {
		sprite.setPosition(pos.x, pos.y);
	}



};


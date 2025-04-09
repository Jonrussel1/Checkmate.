#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window/Event.hpp>

void main2()
{
	unsigned int width = 720;
	unsigned int height = 720;
	sf::RenderWindow* window = new sf::RenderWindow(sf::VideoMode({ width,height }), "Chess Puzzle Game");
	window->setFramerateLimit(60);


	//background music
	sf::SoundBuffer buffer;
	if (!buffer.loadFromFile("media\\background2.wav")) {
		std::cerr << "Error loading sound file" << std::endl;
	}

	sf::Sound sound(buffer);
	sound.setPitch(1.0f);
	sound.setLooping(true);
	sound.setVolume(30.f);
	while (sound.getStatus() == sf::Sound::Status::Playing)
	{
		sf::sleep(sf::milliseconds(100));
	}
	sound.play();




	//load font and title
	sf::Font font("BungeeTint-Regular.ttf");

	sf::Text text1(font);
	text1.setString("Chess Puzzle Game");
	text1.setCharacterSize(175);
	text1.setFillColor(sf::Color::Black);
	text1.setPosition({ 450,400 });

	//load enter text  **add button
	sf::Text text2(font);
	text2.setCharacterSize(100);
	text2.setString("Press Enter To Play");
	text2.setFillColor(sf::Color::Black);
	text2.setPosition({ 650,650 });

	//load quit text **add button
	sf::Text text3(font);
	text3.setCharacterSize(100);
	text3.setString("Quit");
	text3.setFillColor(sf::Color::Black);
	text3.setPosition({ 900,800 });

	//load sprite 
	sf::Texture texture2("Sprites\\queen1.png");

	sf::Sprite spriteb(texture2);
	spriteb.setOrigin({ 32,32 });
	spriteb.setPosition({ 350,200 });
	spriteb.scale(sf::Vector2f(4.0, 4.0));

		
		window->clear(sf::Color(245, 245, 220));
		//Drawing 
		window->draw(text1);
		window->draw(text2);
		window->draw(text3);
		window->draw(spriteb);
		//Display
		window->display();	
}
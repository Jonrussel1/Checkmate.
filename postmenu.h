#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include <optional> 




sf::SoundBuffer buffer;
if (!buffer.loadFromFile("media\\background2.wav")) {
	std::cerr << "Error loading sound file" << std::endl;
	return -1;
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

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include <optional>
#include <SFML/Window/Export.hpp>
#include <SFML/Audio.hpp>

int main()
{
    int choice = 0;

    // Create texture and sprite; load the open screen image.
    sf::Texture texture;
    // Background music setup
    sf::SoundBuffer buffer;
    if (!buffer.loadFromFile("bgm.wav")) {
        std::cerr << "Error loading sound file" << std::endl;
        return -1;
    }

    sf::Sound sound(buffer);
    sound.setPitch(1.0f);
    sound.setLooping(true);
    sound.setVolume(30.f);
    sound.play();
    if (!texture.loadFromFile("openScreen.png")) {
        std::cerr << "Error loading openScreen.png" << std::endl;
        return -1;
    }
    sf::Sprite sprite(texture);

    // Create the window.
    sf::RenderWindow window(sf::VideoMode({ 720, 720 }), "Chess Puzzle Selector");

    // Draw the initial texture.
    window.clear();
    window.draw(sprite);
    window.display();

    // -----------------------------
    // Startup Screen: Mode Selection
    // -----------------------------
    while (window.isOpen() && choice == 0)
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>()) {
                window.close();
            }
            else if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>()) {
                // Use SFML 3.0.0 scancodes for key identification.
                if (keyPressed->scancode == sf::Keyboard::Scancode::Num1)
                    choice = 1;
                else if (keyPressed->scancode == sf::Keyboard::Scancode::Num2)
                    choice = 2;
                else if (keyPressed->scancode == sf::Keyboard::Scancode::Num3)
                    choice = 3;
                else if (keyPressed->scancode == sf::Keyboard::Scancode::Escape)
                    window.close();
            }
        }
    }

    // Load the texture for the selected mode.
    if (choice == 1) {
        if (!texture.loadFromFile("matein1.png")) {
            std::cerr << "Error loading matein1.png" << std::endl;
            return -1;
        }
    }
    else if (choice == 2) {
        if (!texture.loadFromFile("med.png")) {
            std::cerr << "Error loading med.png" << std::endl;
            return -1;
        }
    }
    else if (choice == 3) {
        if (!texture.loadFromFile("hard.png")) {
            std::cerr << "Error loading hard.png" << std::endl;
            return -1;
        }
    }
    else {
        std::cout << "Invalid choice." << std::endl;
        window.close();
    }

    // Update the sprite with the new texture.
    sprite.setTexture(texture, true);
    window.clear();
    window.draw(sprite);
    window.display();

    // ----------------------------------------------------
    // Mode-specific Interaction using Keyboard (No Console I/O)
    // ----------------------------------------------------
    if (choice == 1)
    {
        bool retry = true;
        while (retry && window.isOpen())
        {
            int easyChoice = 0;
            std::cout << "Mode 1 active. Press Num1 for a4, Num2 for b4." << std::endl;

            // Wait for puzzle selection key for mode 1.
            while (window.isOpen() && easyChoice == 0)
            {
                while (const std::optional event = window.pollEvent())
                {
                    if (event->is<sf::Event::Closed>()) {
                        window.close();
                        break;
                    }
                    else if (const auto* keyEv = event->getIf<sf::Event::KeyPressed>()) {
                        if (keyEv->scancode == sf::Keyboard::Scancode::Num1)
                            easyChoice = 1;
                        else if (keyEv->scancode == sf::Keyboard::Scancode::Num2)
                            easyChoice = 2;
                    }
                }
            }

            if (easyChoice == 1) {
                if (!texture.loadFromFile("matein1win.png")) {
                    std::cerr << "Error loading matein1win.png" << std::endl;
                    return -1;
                }
                std::cout << "Good Job!" << std::endl;
            }
            else if (easyChoice == 2) {
                if (!texture.loadFromFile("matein1lose.png")) {
                    std::cerr << "Error loading matein1lose.png" << std::endl;
                    return -1;
                }
                std::cout << "Wrong choice." << std::endl;
            }
            else {
                std::cout << "Invalid choice." << std::endl;
            }

            // Update display.
            sprite.setTexture(texture, true);
            window.clear();
            window.draw(sprite);
            window.display();

            // Wait for retry decision (Y/N).
            bool decisionMade = false;
            while (window.isOpen() && !decisionMade)
            {
                while (const std::optional event = window.pollEvent())
                {
                    if (event->is<sf::Event::Closed>()) {
                        window.close();
                        decisionMade = true;
                        break;
                    }
                    else if (const auto* keyEv = event->getIf<sf::Event::KeyPressed>())
                    {
                        // Assume Y and N keys are used (scancodes for Y and N).
                        if (keyEv->scancode == sf::Keyboard::Scancode::Y) {
                            // Reload the startup texture for mode 1 interaction.
                            if (!texture.loadFromFile("matein1.png")) {
                                std::cerr << "Error reloading matein1.png" << std::endl;
                                return -1;
                            }
                            sprite.setTexture(texture, true);
                            window.clear();
                            window.draw(sprite);
                            window.display();
                            decisionMade = true;
                        }
                        else if (keyEv->scancode == sf::Keyboard::Scancode::N) {
                            std::cout << "Goodbye!" << std::endl;
                            retry = false;
                            decisionMade = true;
                            window.close();
                        }
                    }
                }
            }
        }
    }
    else if (choice == 2)
    {
        bool retry = true;
        while (retry && window.isOpen())
        {
            int medChoice = 0;
            std::cout << "Mode 2 active. Press Num1 for a6, Num2 for b7." << std::endl;

            // Wait for puzzle selection for mode 2.
            while (window.isOpen() && medChoice == 0)
            {
                while (const std::optional event = window.pollEvent())
                {
                    if (event->is<sf::Event::Closed>()) {
                        window.close();
                        break;
                    }
                    else if (const auto* keyEv = event->getIf<sf::Event::KeyPressed>())
                    {
                        if (keyEv->scancode == sf::Keyboard::Scancode::Num1)
                            medChoice = 1;
                        else if (keyEv->scancode == sf::Keyboard::Scancode::Num2)
                            medChoice = 2;
                    }
                }
            }

            if (medChoice == 1) {
                if (!texture.loadFromFile("medwin.png")) {
                    std::cerr << "Error loading med.png" << std::endl;
                    return -1;
                }
                std::cout << "Good Job!" << std::endl;
            }
            else if (medChoice == 2) {
                if (!texture.loadFromFile("medlose.png")) {
                    std::cerr << "Error loading med2.png" << std::endl;
                    return -1;
                }
                std::cout << "Wrong choice." << std::endl;
            }
            else {
                std::cout << "Invalid choice." << std::endl;
            }

            // Update display.
            sprite.setTexture(texture, true);
            window.clear();
            window.draw(sprite);
            window.display();

            // Wait for retry decision (Y/N) for mode 2.
            bool decisionMade = false;
            while (window.isOpen() && !decisionMade)
            {
                while (const std::optional event = window.pollEvent())
                {
                    if (event->is<sf::Event::Closed>()) {
                        window.close();
                        decisionMade = true;
                        break;
                    }
                    else if (const auto* keyEv = event->getIf<sf::Event::KeyPressed>())
                    {
                        if (keyEv->scancode == sf::Keyboard::Scancode::Y) {
                            if (!texture.loadFromFile("med.png")) {
                                std::cerr << "Error reloading med.png" << std::endl;
                                return -1;
                            }
                            sprite.setTexture(texture, true);
                            window.clear();
                            window.draw(sprite);
                            window.display();
                            decisionMade = true;
                        }
                        else if (keyEv->scancode == sf::Keyboard::Scancode::N) {
                            std::cout << "Goodbye!" << std::endl;
                            retry = false;
                            decisionMade = true;
                            window.close();
                        }
                    }
                }
            }
        }
    }
    else if (choice == 3)
    {
        bool retry = true;
        while (retry && window.isOpen())
        {
            int hardStep = 0;
            std::cout << "Mode 3 active. First move: Press Num1 for Queen h4, Num2 for Pawn f5." << std::endl;

            // Load hard puzzle screen
            if (!texture.loadFromFile("hard.png")) {
                std::cerr << "Error loading hard.png" << std::endl;
                return -1;
            }
            sprite.setTexture(texture, true);
            window.clear();
            window.draw(sprite);
            window.display();

            // Wait for first move input
            while (window.isOpen() && hardStep == 0)
            {
                while (const std::optional event = window.pollEvent())
                {
                    if (event->is<sf::Event::Closed>()) {
                        window.close();
                        break;
                    }
                    else if (const auto* keyEv = event->getIf<sf::Event::KeyPressed>())
                    {
                        if (keyEv->scancode == sf::Keyboard::Scancode::Num1)
                            hardStep = 1;
                        else if (keyEv->scancode == sf::Keyboard::Scancode::Num2)
                            hardStep = 2;
                    }
                }
            }

            if (hardStep == 1) {
                // Correct first move
                if (!texture.loadFromFile("hardstep1.png")) {
                    std::cerr << "Error loading hardstep1.png" << std::endl;
                    return -1;
                }
                std::cout << "Nice! Now the second move: Num1 for Bc4, Num2 for Bd3." << std::endl;
                sprite.setTexture(texture, true);
                window.clear();
                window.draw(sprite);
                window.display();

                int secondMove = 0;
                while (window.isOpen() && secondMove == 0)
                {
                    while (const std::optional event = window.pollEvent())
                    {
                        if (event->is<sf::Event::Closed>()) {
                            window.close();
                            break;
                        }
                        else if (const auto* keyEv = event->getIf<sf::Event::KeyPressed>())
                        {
                            if (keyEv->scancode == sf::Keyboard::Scancode::Num1)
                                secondMove = 1;
                            else if (keyEv->scancode == sf::Keyboard::Scancode::Num2)
                                secondMove = 2;
                        }
                    }
                }

                if (secondMove == 1) {
                    if (!texture.loadFromFile("hardwin.png")) {
                        std::cerr << "Error loading hardwin.png" << std::endl;
                        return -1;
                    }
                    std::cout << "Checkmate! Great job!" << std::endl;
                }
                else {
                    if (!texture.loadFromFile("hardlose.png")) {
                        std::cerr << "Error loading hardlose.png" << std::endl;
                        return -1;
                    }
                    std::cout << "Wrong second move." << std::endl;
                }
            }
            else if (hardStep == 2) {
                if (!texture.loadFromFile("hardfail.png")) {
                    std::cerr << "Error loading hardfail.png" << std::endl;
                    return -1;
                }
                std::cout << "Wrong first move." << std::endl;
            }

            sprite.setTexture(texture, true);
            window.clear();
            window.draw(sprite);
            window.display();

            // Retry prompt
            bool decisionMade = false;
            while (window.isOpen() && !decisionMade)
            {
                while (const std::optional event = window.pollEvent())
                {
                    if (event->is<sf::Event::Closed>()) {
                        window.close();
                        decisionMade = true;
                        break;
                    }
                    else if (const auto* keyEv = event->getIf<sf::Event::KeyPressed>())
                    {
                        if (keyEv->scancode == sf::Keyboard::Scancode::Y) {
                            decisionMade = true;
                        }
                        else if (keyEv->scancode == sf::Keyboard::Scancode::N) {
                            std::cout << "Goodbye!" << std::endl;
                            retry = false;
                            decisionMade = true;
                            window.close();
                        }
                    }
                }
            }
        }
        }
    return 0;
}

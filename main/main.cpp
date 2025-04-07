#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include <optional> 

int main()
{
    //load texture
    sf::Texture texture;

    int choice;
    std::cout << "Enter a number (1-3):  1 = EASY  2 = INTERMEDIATE  3 = HARD";
    std::cin >> choice;

    switch (choice)
    {
    case 1:
        texture.loadFromFile("mate-in-1-chess-puzzles.png"); false, sf::IntRect({ 0, 0 }, { 720, 720 });
        break;
    case 2:
        texture.loadFromFile("dynboard.png"); false, sf::IntRect({ 0, 0 }, { 720, 720 });
        break;
    default:
        std::cout << "Invalid choice.";
    }
    // Create the window
    sf::RenderWindow window(sf::VideoMode({ 720, 720 }), "Chess Puzzle Selector");

    // Load sprite

    sf::Sprite sprite(texture);

    // Game loop
    while (window.isOpen())
    {
        // Event handling
        while (std::optional<sf::Event> event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        // Draw frame
        window.clear();
        window.draw(sprite);
        window.display();


        // START OF EASY MODE
        int easy;
        if (choice == 1) {
        startEasy:
            std::cout << "Enter a number (1-2): 1-E4 2-E5";
            std::cin >> easy;


            switch (easy)
            {
            case 1:
                texture.loadFromFile("bald.png"); false, sf::IntRect({ 0, 0 }, { 720, 720 });
                std::cout << "Good Job!.";
                break;
            case 2:
                texture.loadFromFile("w.png"); false, sf::IntRect({ 0, 0 }, { 720, 720 });
                std::cout << "Wrong choice.";
                break;
            default:
                std::cout << "Invalid choice.";
            }
            window.clear();
            window.draw(sprite);
            window.display();

            //RERUN SWITCH
            char rerun;
            std::cout << "Retry the problem? (y/n): ";
            std::cin >> rerun;
            if (rerun == 'y') {
                texture.loadFromFile("mate-in-1-chess-puzzles.png");
                window.clear();
                window.draw(sprite);
                window.display();
                goto startEasy;
            }
            else if (rerun == 'n') {
                std::cout << "Goodbye!";
                window.close();
            }
            else {
                std::cout << "Invalid choice.";

            }
        }
        if (choice == 2) {
            int med;
        startMed:
            std::cout << "Enter a number (1-2): 1-d4 2-a5";
            std::cin >> med;

            //INTERMEDIATE MODE START
            switch (med)
            {
            case 1:
                texture.loadFromFile("med.png"); false, sf::IntRect({ 0, 0 }, { 720, 720 });
                std::cout << "Good Job!.";
                break;
            case 2:
                texture.loadFromFile("med2.png"); false, sf::IntRect({ 0, 0 }, { 720, 720 });
                std::cout << "Wrong choice.";
                break;
            default:
                std::cout << "Invalid choice.";
            }
            window.clear();
            window.draw(sprite);
            window.display();

            //RERUN SWITCH
            char rerun2;
            std::cout << "Retry the problem? (y/n): ";
            std::cin >> rerun2;
            if (rerun2 == 'y') {
                texture.loadFromFile("dynboard.png");
                window.clear();
                window.draw(sprite);
                window.display();
                goto startEasy;
            }
            else if (rerun2 == 'n') {
                std::cout << "Goodbye!";
                window.close();
            }
            else {
                std::cout << "Invalid choice.";



            }
        }
    }
}
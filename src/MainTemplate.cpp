#include <iostream>
#include <SFML/Graphics.hpp>

int main()
{
    // Create a window
    sf::RenderWindow window(sf::VideoMode(1280, 720), "JoacimLordNTI SFML Template");
    std::cout << "New window opened\n";

    // Specifies a specific value for the framerate
    window.setFramerateLimit(60);

    // Circle shape
    sf::CircleShape shape(100.0f);
    shape.setFillColor(sf::Color::Red);
    shape.setPosition(window.getSize().x / 2, window.getSize().y / 2);

    // Viewport
    sf::View view = window.getDefaultView();

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Close Event
            if (event.type == sf::Event::Closed)
            {
                std::cout << "Window closed\n";
                window.close();
            }

            // Resize Event
            else if (event.type == sf::Event::Resized) {
                // resize my view
                view.setSize({
                        static_cast<float>(event.size.width),
                        static_cast<float>(event.size.height)
                    });

                window.setView(view);
                shape.setPosition(window.mapPixelToCoords(sf::Vector2i{ window.getSize() / 2u }));
            }
        }

        window.clear();
        window.draw(shape);
        window.display();
    }

    return 0;
}
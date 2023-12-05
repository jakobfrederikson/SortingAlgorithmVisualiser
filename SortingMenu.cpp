#include "SortingMenu.h"
#include <iostream>

SortingMenu::SortingMenu() {
    if (!font.loadFromFile("./Inter-Regular.ttf")) {
        // Handle font loading error
        std::cout << "Error loading font" << std::endl;
    }

    initialiseMenuItems();
}

void SortingMenu::initialiseMenuItems() {
    menuItems.push_back(sf::Text("Bubble Sort", font, 24));
    menuItems.push_back(sf::Text("Insertion Sort", font, 24));
    menuItems.push_back(sf::Text("Selection Sort", font, 24));
    menuItems.push_back(sf::Text("Merge Sort", font, 24));

    for (size_t i = 0; i < menuItems.size(); ++i)
    {
        menuItems[i].setPosition(10, static_cast<float>(i * 30 + 10));
    }
}

int SortingMenu::run(sf::RenderWindow& window) {
    while (window.isOpen()) {
        int result = handleInput(window);

        if (result != -1) {
            return result;
        }

        window.clear();
        drawMenu(window);
        window.display();
    }

    return -1; // Window closed
}

int SortingMenu::handleInput(sf::RenderWindow& window) {
    sf::Event event;

    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            // Window is closed
            return -1;
        }
        else if (event.type == sf::Event::MouseButtonReleased) {
            sf::Vector2i mousePos = sf::Mouse::getPosition(window);
            for (size_t i = 0; i < menuItems.size(); ++i) {
                if (menuItems[i].getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y))) {
                    std::cout << "Selected: " << menuItems[i].getString().toAnsiString() << std::endl;
                    return static_cast<int>(i);
                }
            }
        }
    }

    return -1;  // No selection made
}

void SortingMenu::drawMenu(sf::RenderWindow& window) {
    for (const auto& menuItem : menuItems) {
        window.draw(menuItem);
    }
}
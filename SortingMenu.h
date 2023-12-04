#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

class SortingMenu
{
public: 
	SortingMenu();

	int run(sf::RenderWindow& window);
private:
	sf::Font font;
	std::vector<sf::Text> menuItems;

	void initialiseMenuItems();
	int handleInput(sf::RenderWindow& window);
	void drawMenu(sf::RenderWindow& window);
};


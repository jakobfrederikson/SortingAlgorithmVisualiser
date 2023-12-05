#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include "Algorithms/SortingAlgorithm.h"
#include "Algorithms/BubbleSort.h"

class SortingAlgorithmManager
{
public:
	SortingAlgorithmManager();

	void Display(int selectedAlgorithm, sf::RenderWindow& window);
private:
	sf::Font font;

	std::vector<int> getArray(sf::RenderWindow& window);
	std::vector<int> generateRandomArray(int size);

	void waitForInput(sf::RenderWindow& window);
};


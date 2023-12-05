#pragma once

#include <SFML/Graphics.hpp>
#include<chrono>
#include<vector>

class SortingAlgorithmDisplay
{
public:
	SortingAlgorithmDisplay();

	void display(int selectedAlgorithm, sf::RenderWindow& window);
private:
	sf::Font font;

	std::vector<int> getArray(sf::RenderWindow& window);
	std::vector<int> generateRandomArray(int size);
	void drawArray(sf::RenderWindow& window, const std::vector<int>& array, std::chrono::steady_clock::time_point& startTime);
	void BubbleSort(sf::RenderWindow& window, std::vector<int>& array);
	void InsertionSort(sf::RenderWindow& window, std::vector<int>& array);
	void waitForInput(sf::RenderWindow& window);
};


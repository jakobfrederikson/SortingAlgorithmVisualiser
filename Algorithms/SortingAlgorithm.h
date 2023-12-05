#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <chrono>

class SortingAlgorithm {
public:
	virtual ~SortingAlgorithm() = default;

	virtual void Sort(sf::RenderWindow& window, std::vector<int>& array) = 0;

	sf::Font font;
protected:
	void drawAdditionalInfo(sf::RenderWindow& window, const std::chrono::steady_clock::time_point& startTime, const std::vector<int>& array);
private:
	virtual void drawAlgorithm(sf::RenderWindow& window, const std::vector<int>& array, std::chrono::steady_clock::time_point& startTime) = 0;
	
};
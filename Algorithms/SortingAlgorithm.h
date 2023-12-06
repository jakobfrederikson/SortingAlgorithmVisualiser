#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>
#include <chrono>

class SortingAlgorithm {
public:
	SortingAlgorithm();
	virtual ~SortingAlgorithm() = default;

	virtual void Sort(sf::RenderWindow& window, std::vector<int>& array) = 0;
	void PlaySound(float height);

	sf::Font font;
	sf::Sound sound;
protected:
	void drawAdditionalInfo(sf::RenderWindow& window, const std::chrono::steady_clock::time_point& startTime, const std::vector<int>& array);
private:
	virtual void drawAlgorithm(sf::RenderWindow& window, const std::vector<int>& array, std::chrono::steady_clock::time_point& startTime) = 0;

	sf::SoundBuffer soundBuffer;
	
};
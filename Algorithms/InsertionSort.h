#pragma once
#include "SortingAlgorithm.h"
#include <SFML/Graphics.hpp>
#include <chrono>

class InsertionSort :
    public SortingAlgorithm
{
public:
    virtual void Sort(sf::RenderWindow& window, std::vector<int>& array) override;
private:
    virtual void drawAlgorithm(sf::RenderWindow& window, const std::vector<int>& array, std::chrono::steady_clock::time_point& startTime) override;
};


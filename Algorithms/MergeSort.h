#pragma once
#include "SortingAlgorithm.h"
#include <chrono>

class MergeSort :
    public SortingAlgorithm
{
public:
    virtual void Sort(sf::RenderWindow& window, std::vector<int>& array) override;
private:
    virtual void drawAlgorithm(sf::RenderWindow& window, const std::vector<int>& array, std::chrono::steady_clock::time_point& startTime) override;

    void drawAlgorithm(sf::RenderWindow& window, const std::vector<int>& array, std::chrono::steady_clock::time_point& startTime, size_t left, size_t right);

    void merge(
        sf::RenderWindow& window, std::vector<int>& array, std::vector<int>& leftArray, 
        std::vector<int>& rightArray, int leftStart, int mid, int rightEnd, 
        std::chrono::steady_clock::time_point startTime);
};


#include "SelectionSort.h"

void SelectionSort::Sort(sf::RenderWindow& window, std::vector<int>& array) {
    std::chrono::steady_clock::time_point clock = std::chrono::high_resolution_clock::now();

    for (size_t i = 0; i < array.size() - 1; ++i) {
        size_t minIndex = i;

        for (size_t j = i + 1; j < array.size(); ++j) {
            if (array[j] < array[minIndex]) {
                minIndex = j;
            }
        }

        std::swap(array[minIndex], array[i]);

        drawAlgorithm(window, array, clock);
    }
}

void SelectionSort::drawAlgorithm(sf::RenderWindow& window, const std::vector<int>& array, std::chrono::steady_clock::time_point& startTime) {
    
    window.clear();

    // Find the maximum value in the array
    int maxElement = *std::max_element(array.begin(), array.end());

    // Calculate the scale factors to fit the elements within the window
    float heightScaleFactor = static_cast<float>(window.getSize().y) / maxElement;
    float widthScaleFactor = static_cast<float>(window.getSize().x) / array.size();

    // Draw the array elements
    for (size_t i = 0; i < array.size(); ++i) {
        sf::RectangleShape rect(sf::Vector2f(widthScaleFactor, array[i] * heightScaleFactor));
        rect.setPosition(i * widthScaleFactor, window.getSize().y - rect.getSize().y);
        window.draw(rect);
    }

    // Draw additional information
    drawAdditionalInfo(window, startTime, array);

    window.display();
}
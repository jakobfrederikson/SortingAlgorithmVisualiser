#include "BubbleSort.h"

void BubbleSort::Sort(sf::RenderWindow& window, std::vector<int>& array) {
    // Implementation of Bubble Sort
    bool swapped;
    std::chrono::steady_clock::time_point clock = std::chrono::high_resolution_clock::now();

    for (size_t i = 0; i < array.size() - 1; ++i) {
        swapped = false;
        for (size_t j = 0; j < array.size() - i - 1; ++j) {
            if (array[j] > array[j + 1]) {
                // Swap elements
                std::swap(array[j], array[j + 1]);
                swapped = true;

                // Visualize the step after swapping
                drawAlgorithm(window, array, clock);
            }
        }

        // If no swapping occurred, the array is already sorted
        if (!swapped) {
            break;
        }
    }
}

void BubbleSort::drawAlgorithm(sf::RenderWindow& window, const std::vector<int>& array, std::chrono::steady_clock::time_point& startTime)
{
    window.clear();

    // Start a clock to count how long the array takes.

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

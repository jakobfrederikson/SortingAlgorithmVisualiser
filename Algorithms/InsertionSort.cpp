#include "InsertionSort.h"

void InsertionSort::Sort(sf::RenderWindow& window, std::vector<int>& array)
{
    std::chrono::steady_clock::time_point clock = std::chrono::high_resolution_clock::now();

    for (size_t i = 1; i < array.size(); ++i) {
        int key = array[i];
        int j = i - 1;

        while (j >= 0 && array[j] > key) {
            array[j + 1] = array[j];
            --j;

            // Visualize the step after swapping
            
        }

        array[j + 1] = key;

        drawAlgorithm(window, array, clock);
    }
}

void InsertionSort::drawAlgorithm(sf::RenderWindow& window, const std::vector<int>& array, std::chrono::steady_clock::time_point& startTime)
{
    window.clear();

    // Find the maximum value in the array
    int maxElement = *std::max_element(array.begin(), array.end());

    // Calculate the scale factors to fit the elements within the window
    float heightScaleFactor = static_cast<float>(window.getSize().y) / maxElement;
    float widthScaleFactor = static_cast<float>(window.getSize().x) / array.size();

    // Draw the array elements
    for (size_t i = 0; i < array.size(); ++i) {
        float height = array[i] * heightScaleFactor;
        sf::RectangleShape rect(sf::Vector2f(widthScaleFactor, height));
        rect.setPosition(i * widthScaleFactor, window.getSize().y - rect.getSize().y);
        window.draw(rect);
        PlaySound(height);
    }

    // Draw additional information
    drawAdditionalInfo(window, startTime, array);

    window.display();
}

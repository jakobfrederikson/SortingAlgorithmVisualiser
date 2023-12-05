#include "SortingAlgorithm.h"

void SortingAlgorithm::drawAdditionalInfo(sf::RenderWindow& window, const std::chrono::steady_clock::time_point& startTime, const std::vector<int>& array) {
    // Draw additional information
    sf::Text infoText;
    infoText.setFont(font);  // Assuming font is a member of ISortingAlgorithm or derived classes
    infoText.setCharacterSize(20);
    infoText.setFillColor(sf::Color::White);

    // Display the time taken
    auto currentTime = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(currentTime - startTime);
    infoText.setString("Time taken: " + std::to_string(duration.count()) + " ms");
    infoText.setPosition(10.f, 10.f);
    window.draw(infoText);

    // Display the length of the array
    infoText.setString("Array length: " + std::to_string(array.size()));
    infoText.setPosition(10.f, 40.f);
    window.draw(infoText);
}

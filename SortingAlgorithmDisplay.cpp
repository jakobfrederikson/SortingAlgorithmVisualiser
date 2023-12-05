#include "SortingAlgorithmDisplay.h"
#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <chrono>

SortingAlgorithmDisplay::SortingAlgorithmDisplay() {
	if (!font.loadFromFile("./Inter-Regular.ttf")) {
		// Handle font loading error
		std::cout << "Error loading font" << std::endl;
	}
}

std::vector<int> SortingAlgorithmDisplay::getArray(sf::RenderWindow& window) {
    std::vector<int> array;

    sf::Text helperText("Insert number here: ", font, 20);
    helperText.setPosition(10.f, 10.f);
    helperText.setFillColor(sf::Color::White);


    sf::Text inputText("", font, 20);

    sf::FloatRect helperBounds = helperText.getGlobalBounds(); // Put the input text after however far helperText extends.

    inputText.setPosition(helperBounds.left + helperBounds.width, 10.f);
    inputText.setFillColor(sf::Color::White);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            else if (event.type == sf::Event::TextEntered) {
                if (event.text.unicode == 13) { // Enter key
                    try {
                        int arraySize = std::stoi(inputText.getString().toAnsiString());
                        array = generateRandomArray(arraySize);
                        std::cout << "Generated array with " << arraySize << " elements." << std::endl;
                        return array;  // Return the generated array
                    }
                    catch (const std::invalid_argument& e) {
                        std::cout << "Invalid input. Please enter a valid integer.";
                        inputText.setString("");
                    }
                }
                else if (event.text.unicode == 8) { // Backspace key pressed
                    // Handle backspace (remove last character)
                    std::string currentString = inputText.getString();
                    if (!currentString.empty()) {
                        currentString.erase(currentString.size() - 1);
                        inputText.setString(currentString);
                    }
                }
                else if (event.text.unicode >= 32 && event.text.unicode <= 126) {
                    inputText.setString(inputText.getString() + static_cast<char>(event.text.unicode));
                }
            }
        }

        window.clear();
        window.draw(helperText);
        window.draw(inputText);
        window.display();
    }

    return array;  // Return an empty array if the window is closed
}

std::vector<int> SortingAlgorithmDisplay::generateRandomArray(int size) {
    std::vector<int> array;

    std::random_device rd;

    std::mt19937 gen(rd());

    std::uniform_int_distribution<int> distribution(0, size - 1);

    for (int i = 0; i < size; ++i) {
        array.push_back(i);
    }

    std::shuffle(array.begin(), array.end(), gen);

    std::cout << "Generated array: ";
    for (int value : array) {
        std::cout << value << " ";
    }
    std::cout << std::endl;

    return array;
}

void SortingAlgorithmDisplay::display(int selectedAlgorithm, sf::RenderWindow& window) {
	std::vector<int> array = getArray(window);

	switch (selectedAlgorithm) {
	case 0:
		BubbleSort(window, array);
		break;
	case 1:
		InsertionSort(window, array);
		break;
	default:
		break;
	}

    waitForInput(window);
}

void SortingAlgorithmDisplay::drawArray(sf::RenderWindow& window, const std::vector<int>& array, std::chrono::steady_clock::time_point& startTime) {
    window.clear();

    // Start a clock to count how long the array takes.

    // Find the maximum value in the array
    int maxElement = *std::max_element(array.begin(), array.end());

    // Calculate the scale factor to fit the elements within the window height
    float scaleFactor = static_cast<float>(window.getSize().y) / maxElement;

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
    sf::Text infoText;
    infoText.setFont(font);
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

    window.display();
}

void SortingAlgorithmDisplay::BubbleSort(sf::RenderWindow& window, std::vector<int>& array) {
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
                drawArray(window, array, clock);
            }
        }

        // If no swapping occurred, the array is already sorted
        if (!swapped) {
            break;
        }
    }
}

void SortingAlgorithmDisplay::InsertionSort(sf::RenderWindow& window, std::vector<int>& array)
{
	sf::CircleShape circle(25);
	circle.setPosition(200, 200);
	circle.setFillColor(sf::Color::Green);

	window.clear();
	window.draw(circle);
	window.display();
}

void SortingAlgorithmDisplay::waitForInput(sf::RenderWindow& window)
{
	sf::Event event;
	while (window.waitEvent(event)) {
		if (event.type == sf::Event::KeyPressed || event.type == sf::Event::MouseButtonPressed) {
			return;  // User input received, exit the function
		}
		else if (event.type == sf::Event::Closed) {
			window.close();
			return;  // Window closed, exit the function
		}
	}
}
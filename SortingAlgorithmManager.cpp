#include "SortingAlgorithmManager.h"
#include "Algorithms/BubbleSort.h"
#include "Algorithms/InsertionSort.h"
#include "Algorithms/SelectionSort.h"
#include "Algorithms/MergeSort.h"
#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <chrono>

SortingAlgorithmManager::SortingAlgorithmManager() {
	if (!font.loadFromFile("./Inter-Regular.ttf")) {
		// Handle font loading error
		std::cout << "Error loading font" << std::endl;
	}
}

void SortingAlgorithmManager::Display(int selectedAlgorithm, sf::RenderWindow& window) {
    std::vector<int> array = getArray(window);

    SortingAlgorithm* sortingAlgorithm = nullptr;

    switch (selectedAlgorithm) {
    case 0:
        sortingAlgorithm = new BubbleSort();
        break;
    case 1:
        sortingAlgorithm = new InsertionSort();
        break;
    case 2:
        sortingAlgorithm = new SelectionSort();
    case 3:
        sortingAlgorithm = new MergeSort();
    default:
        break;
    }

    if (sortingAlgorithm) {
        sortingAlgorithm->Sort(window, array);
        delete sortingAlgorithm;
    }

    waitForInput(window);
}

std::vector<int> SortingAlgorithmManager::getArray(sf::RenderWindow& window) {
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

std::vector<int> SortingAlgorithmManager::generateRandomArray(int size) {
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

void SortingAlgorithmManager::waitForInput(sf::RenderWindow& window)
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
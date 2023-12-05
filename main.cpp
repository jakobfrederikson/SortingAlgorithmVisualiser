#include<SFML/Graphics.hpp>
#include<iostream>
#include "SortingMenu.h"
#include "SortingAlgorithmManager.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(1200, 600), "Sorting Visualiser by Jakob");

	SortingMenu sortingMenu;
	SortingAlgorithmManager algorithmManager;

	int selectedAlgorithm = -1;

	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}
		}

		// If no algorithm is selected, show the sorting menu
		if (selectedAlgorithm == -1) {
			selectedAlgorithm = sortingMenu.run(window);

			if (selectedAlgorithm == -1) {
				window.close();
			}
		}
		else {
			std::cout << "Running algorithm: " << selectedAlgorithm << std::endl;

			algorithmManager.Display(selectedAlgorithm, window);
			selectedAlgorithm = -1;
		}

		window.clear();

		window.display();
	}

	return 0;
}
#include "SortingAlgorithmDisplay.h"
#include <iostream>

SortingAlgorithmDisplay::SortingAlgorithmDisplay() {

}

void SortingAlgorithmDisplay::display(int selectedAlgorithm) {
	switch (selectedAlgorithm) {
	case 0:
		std::cout << "Bubble sort here" << std::endl;
		// Display bubble sort
		break;
	case 1:
		std::cout << "Insertion sort here" << std::endl;
		// Display insertion sort
	default:
		break;
	}
}
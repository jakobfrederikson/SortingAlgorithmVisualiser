#include "MergeSort.h"

void MergeSort::Sort(sf::RenderWindow& window, std::vector<int>& array)
{
	if (array.size() <= 1) return;

    int n = array.size();
    int currSize;

    // Start the clock to measure the time taken for the merge operation
    auto startTime = std::chrono::high_resolution_clock::now();

    for (currSize = 1; currSize <= n - 1; currSize = 2 * currSize) {
        for (int leftStart = 0; leftStart < n - 1; leftStart += 2 * currSize) {
            int mid = std::min(leftStart + currSize - 1, n - 1);
            int rightEnd = std::min(leftStart + 2 * currSize - 1, n - 1);

            std::vector<int> leftArray(array.begin() + leftStart, array.begin() + mid + 1);
            std::vector<int> rightArray(array.begin() + mid + 1, array.begin() + rightEnd + 1);

            merge(window, array, leftArray, rightArray, leftStart, mid, rightEnd, startTime);
        }
    }
}

void MergeSort::drawAlgorithm(sf::RenderWindow& window, const std::vector<int>& array, std::chrono::steady_clock::time_point& startTime)
{
}

void MergeSort::drawAlgorithm(sf::RenderWindow& window, const std::vector<int>& array, std::chrono::steady_clock::time_point& startTime, size_t left, size_t right)
{
	window.clear();

    // Find the maximum value in the array
    int maxElement = *std::max_element(array.begin(), array.end());

    // Calculate the scale factors to fit the elements within the window
    float heightScaleFactor = static_cast<float>(window.getSize().y) / maxElement;
    float widthScaleFactor = static_cast<float>(window.getSize().x) / array.size();

    // Draw the entire array elements
    for (size_t i = 0; i < array.size(); ++i) {
        sf::RectangleShape rect(sf::Vector2f(widthScaleFactor, array[i] * heightScaleFactor));
        rect.setPosition(i * widthScaleFactor, window.getSize().y - rect.getSize().y);
        window.draw(rect);
    }

	// Draw additional information
	drawAdditionalInfo(window, startTime, array);

	window.display();
}

void MergeSort::merge(sf::RenderWindow& window, std::vector<int>& array, std::vector<int>& leftArray, std::vector<int>& rightArray, int leftStart, int mid, int rightStart, std::chrono::steady_clock::time_point startTime)
{
    size_t leftIndex = 0;
    size_t rightIndex = 0;
    size_t mergedIndex = leftStart;

    while (leftIndex < leftArray.size() && rightIndex < rightArray.size()) {
        // Find the lowest value and store it in the original array
        if (leftArray[leftIndex] <= rightArray[rightIndex]) {
            array[mergedIndex++] = leftArray[leftIndex++];
        }
        else {
            array[mergedIndex++] = rightArray[rightIndex++];
        }
    }

    // If there's any left over in the left and right arrays, merge them in the main array.
    while (leftIndex < leftArray.size()) {
        array[mergedIndex++] = leftArray[leftIndex++];
    }
    while (rightIndex < rightArray.size()) {
        array[mergedIndex++] = rightArray[rightIndex++];        
    }    

    // Draw in batches because it takes too long otherwise
    if (mergedIndex % 20 == 0)
        drawAlgorithm(window, array, startTime, leftStart + leftIndex, rightStart + rightIndex);
}

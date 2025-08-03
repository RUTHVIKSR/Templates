#include <iostream>
#include <vector>

// --- Function to perform insertion sort ---
// arr: The vector of integers to be sorted.
void insertionSort(std::vector<int>& arr) {
    // Start from the second element (index 1) as the first element is already "sorted".
    for (int i = 1; i < arr.size(); i++) {
        // The current element to be inserted into the sorted portion.
        int key = arr[i];
        
        // j is the index of the last element in the sorted portion.
        int j = i - 1;

        // Move elements of arr[0..i-1] that are greater than key
        // to one position ahead of their current position.
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j]; // Shift the element to the right.
            j = j - 1;           // Move to the next element on the left.
        }
        
        // Place the key at its correct sorted position.
        arr[j + 1] = key;
    }
}

// --- Helper function to print the vector ---
void printArray(const std::vector<int>& arr) {
    for (int i = 0; i < arr.size(); i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

// --- Main function to test the insertion sort ---
int main() {
    // Create a sample vector of integers.
    std::vector<int> data = {12, 11, 13, 5, 6};

    std::cout << "Original array: \n";
    printArray(data);

    // Call the insertion sort function to sort the vector.
    insertionSort(data);

    std::cout << "\nSorted array: \n";
    printArray(data);

    return 0;
}

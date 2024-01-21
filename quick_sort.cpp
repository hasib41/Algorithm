#include <iostream>

// Function to partition the array into two sub-arrays
int partition(int arr[], int low, int high) {
    int pivot = arr[high]; // Choose the rightmost element as the pivot
    int i = (low - 1); // Index of smaller element

    for (int j = low; j <= high - 1; j++) {
        // If the current element is smaller than or equal to the pivot
        if (arr[j] <= pivot) {
            i++; // Increment index of smaller element
            // Swap arr[i] and arr[j]
            std::swap(arr[i], arr[j]);
        }
    }

    // Swap arr[i+1] and arr[high] (put the pivot in the correct position)
    std::swap(arr[i + 1], arr[high]);
    return (i + 1); // Return the index of the pivot element
}

// Function to perform Quick Sort
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        // Partition the array into two sub-arrays
        int pi = partition(arr, low, high);

        // Recursively sort the sub-arrays
        quickSort(arr, low, pi - 1); // Before the pivot
        quickSort(arr, pi + 1, high); // After the pivot
    }
}

int main() {
    int arr[] = {12, 11, 13, 5, 6, 7};
    int size = sizeof(arr) / sizeof(arr[0]);

    std::cout << "Given array is \n";
    for (int i = 0; i < size; i++)
        std::cout << arr[i] << " ";
    std::cout << std::endl;

    // Perform Quick Sort
    quickSort(arr, 0, size - 1);

    std::cout << "Sorted array is \n";
    for (int i = 0; i < size; i++)
        std::cout << arr[i] << " ";
    std::cout << std::endl;

    return 0;
}


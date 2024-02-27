/*
 * Name: Sam Pupke
 * Date Submitted: 19 Feb 2024
 * Lab Section: 001
 * Assignment Name: Searching and Sorting
 */

#pragma once

#include <vector>

// Merge function to merge two sorted halves
template <class T>
void merge(std::vector<T>& list, int left, int mid, int right) {
    int n1 = mid - left + 1; // Number of entries between left and mid
    int n2 = right - mid; // Number of entries between right and mid

    // Create temporary vectors for the left and right arrays
    std::vector<T> leftArr(n1);
    std::vector<T> rightArr(n2);

    // Copy data to temporary vectors leftArr[] and rightArr[]
    for (int i = 0; i < n1; i++) {
        leftArr[i] = list[left + i];
    }
    for (int j = 0; j < n2; j++) {
        rightArr[j] = list[mid + 1 + j];
    }

    // Merge the temporary vectors back into list[left..right]
    int i = 0;
    int j = 0;
    int k = left;

    while (i < n1 && j < n2) {
        if (leftArr[i] <= rightArr[j]) {
            list[k] = leftArr[i];
            i++;
        } else {
            list[k] = rightArr[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of leftArr[], if there are any
    while (i < n1) {
        list[k] = leftArr[i];
        i++;
        k++;
    }

    // Copy the remaining elements of rightArr[], if there are any
    while (j < n2) {
        list[k] = rightArr[j];
        j++;
        k++;
    }
}

// Merge Sort function
template <class T>
std::vector<T> mergeSort(std::vector<T> list) {

    if (list.size() <= 1) {
        // Base case: already sorted or empty vector
        return list;
    }

    int mid = list.size() / 2;

    // Divide the vector into two halves
    std::vector<T> leftHalf(list.begin(), list.begin() + mid);
    std::vector<T> rightHalf(list.begin() + mid, list.end());

    // Recursively sort each half
    leftHalf = mergeSort(leftHalf);
    rightHalf = mergeSort(rightHalf);

    // Merge the sorted halves
    list.clear();
    size_t leftIndex = 0, rightIndex = 0;
    while (leftIndex < leftHalf.size() && rightIndex < rightHalf.size()) {
        if (leftHalf[leftIndex] < rightHalf[rightIndex]) {
            list.push_back(leftHalf[leftIndex]);
            leftIndex++;
        } else {
            list.push_back(rightHalf[rightIndex]);
            rightIndex++;
        }
    }
    // Copy the remaining elements of leftHalf[], if any
    while (leftIndex < leftHalf.size()) {
        list.push_back(leftHalf[leftIndex]);
        leftIndex++;
    }
    // Copy the remaining elements of rightHalf[], if any
    while (rightIndex < rightHalf.size()) {
        list.push_back(rightHalf[rightIndex]);
        rightIndex++;
    }

    return list;
}



// Partition function for the Quick Sort algorithm
template <class T>
int partition(std::vector<T>& list, int low, int high) {
    T pivot = list[high];
    int i = low - 1;

    for (int j = low; j < high; ++j) {
        if (list[j] < pivot) {
            i++;
            std::swap(list[i], list[j]);
        }
    }

    std::swap(list[i + 1], list[high]);
    return i + 1;
}

// Quick Sort function
template <class T>
void quickSort(std::vector<T>& list, int low, int high) {
    if (low < high) {
        int partitionIndex = partition(list, low, high);

        quickSort(list, low, partitionIndex - 1);
        quickSort(list, partitionIndex + 1, high);
    }
}

// Wrapper function for ease of use
template <class T>
std::vector<T> quickSort(std::vector<T> list) {
    
    if (list.size() <= 1) {
        // Already sorted or empty vector
        return list;
    }

    quickSort(list, 0, list.size() - 1);

    return list;
}

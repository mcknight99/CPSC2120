/*
 * Name: Sam Pupke
 * Date Submitted: 19 Feb 2024
 * Lab Section: 001
 * Assignment Name: Searching and Sorting
 */

#pragma once

#include <vector>

template <class T>
int linearSearch(std::vector<T> data, T target){
    for(size_t i = 0; i<data.size(); i++) {
        if(data[i]==target) {
            return i;
        }
    }
    return -1;
}

template <class T>
int binarySearch(std::vector<T> data, T target) {
    int low = 0;
    int high = data.size() - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (data[mid] == target) {
            return mid; // Target found at index 'mid'
        } else if (data[mid] < target) {
            low = mid + 1; // Discard the left half
        } else {
            high = mid - 1; // Discard the right half
        }
    }

    return -1; // Target not found
}

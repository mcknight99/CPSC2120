/*
 * Name: Sam Pupke
 * Date Submitted: 15 April 2024
 * Assignment Name: Min-Heap Implementation Using a Vector
 */

#include "minHeap.h"
#include <climits> //for INT_MAX

// Function to maintain the heap property by moving a node up the tree as needed
void minHeap::siftUp(int pos) {
    while (pos > 0) {
        int parent = (pos - 1) / 2;
        if (heap[parent] > heap[pos]) {
            swap(heap[parent], heap[pos]);
            pos = parent;
        } else {
            break;
        }
    }
}

// Function to maintain the heap property by moving a node down the tree as needed
void minHeap::siftDown(int pos) {
    int smallest = pos;
    size_t left = 2 * pos + 1;
    size_t right = 2 * pos + 2;

    if (left < heap.size() && heap[left] < heap[smallest]) {
        smallest = left;
    }
    if (right < heap.size() && heap[right] < heap[smallest]) {
        smallest = right;
    }

    if (smallest != pos) {
        swap(heap[pos], heap[smallest]);
        siftDown(smallest);
    }
}

// Parameterized constructor to build the heap from bottom-up
minHeap::minHeap(vector<int> data) {
    heap = data;
    // Start from the last non-leaf node and perform sift down
    for (int i = (heap.size() - 2) / 2; i >= 0; --i) {
        siftDown(i);
    }
}

// Function to insert a value into the heap
void minHeap::insert(int value) {
    heap.push_back(value);
    siftUp(heap.size() - 1);
}

// Function to remove the minimum value from the heap
int minHeap::removeMin() {
    if (heap.empty()) {
        return INT_MAX; // or throw an exception
    }

    int minValue = heap[0];
    heap[0] = heap.back();
    heap.pop_back();
    siftDown(0);

    return minValue;
}

//
//  Functions.cpp
//  Graphics Testing
//
//  Created by Carter Lewis on 2/16/24.
//

#include <stdio.h>
#include "Functions.h"
void displayBar(SDL_Plotter& g, int height, int index, bool erase) {
    for(int i = 0; i < height; i++) {
        if(!erase) {
            g.plotPixel(index    , i + HEIGHT - height, 0, 0, 0);
        }
        if(erase) {
            g.plotPixel(index    , i + HEIGHT - height, 255, 255, 255);
        }
    }
}
void insertionSort(SDL_Plotter& g, int data[WIDTH]) {
    for(int i = 0; i < WIDTH; i++) {
        int j = i;
        while(j > 0 && data[j] < data[j - 1]) {
            displayBar(g, data[j], j, true);
            displayBar(g, data[j-1], j-1, true);
            swap(data[j], data[j-1]);
            displayBar(g, data[j], j);
            displayBar(g, data[j-1], j-1);
            j--;
        }
        g.update();
//        g.Sleep(5);
    }
}
void selectionSort(SDL_Plotter& g, int data[WIDTH]) {
    int min, minIndex;
    for(int i = 0; i < WIDTH; i++) {
        min = data[i];
        minIndex = i;
        for(int j = i; j < WIDTH; j++) {
            if(data[j] < data[minIndex]) {
                min = data[j];
                minIndex = j;
            }
        }
        displayBar(g, data[i], i, true);
        displayBar(g, data[minIndex], minIndex, true);
        swap(data[i], data[minIndex]);
        displayBar(g, data[i], i);
        displayBar(g, data[minIndex], minIndex);
        
        g.update();
//        g.Sleep(5);
    }
}

void bubbleSort(SDL_Plotter& g, int data[WIDTH]) {
    for(int i = 0; i < WIDTH; i++) {
        for(int j = 0; j < WIDTH - 1 - i; j++) {
            if(data[j] > data[j + 1]) {
                displayBar(g, data[j], j, true);
                displayBar(g, data[j+1], j+1, true);
                swap(data[j], data[j+1]);
                displayBar(g, data[j], j);
                displayBar(g, data[j+1], j+1);
            }
            
        }
        g.update();
//      g.Sleep(5);
    }
}
int partition(SDL_Plotter& g, int data[WIDTH], int left, int right) {
    int pivot = data[left];
    int count = 0;
    
    for(int i = left + 1; i < right; i++) {
        if(data[i] <= pivot) count++;
    }
    
    int pivotIndex = left + count;
    displayBar(g, data[pivotIndex], pivotIndex, true);
    displayBar(g, data[left], left, true);
    swap(data[pivotIndex], data[left]);
    displayBar(g, data[pivotIndex], pivotIndex);
    displayBar(g, data[left], left);
    
    int i = left, j = right;

    while(i < pivotIndex && j > pivotIndex) {
        while(data[i] < pivot) {
            i++;
        }
        while(data[j] > pivot) {
            j--;
        }

        if(i < pivotIndex && j > pivotIndex) {
            displayBar(g, data[i], i, true);
            displayBar(g, data[j], j, true);
            swap(data[i], data[j]);
            displayBar(g, data[i], i);
            displayBar(g, data[j], j);
            i++;
            j--;
            g.update();
            g.Sleep(5);
        }
    }
    
    return pivotIndex;
    
    
    
//    int pivotValue = data[left];
//    int index = left + 1;
//    for(size_t i = left + 1; i <= right; ++i) {
//        if(data[i] < pivotValue) {
//            displayBar(g, data[i], i, true);
//            displayBar(g, data[index], index, true);
//            swap(data[i], data[index]);
//            displayBar(g, data[i], i);
//            displayBar(g, data[index], index);
//            ++index;
//            g.update();
//        }
//    }
//    g.update();
//    swap(data[left], data[index-1]);
//    return index;
}
void quickSort    (SDL_Plotter& g, int data[WIDTH], int left, int right) {
    if(left >= right) return;
    int mid = partition(g, data, left, right);
    quickSort(g, data, left, mid - 1);
    quickSort(g, data, mid + 1, right);
}

void Radixsort(SDL_Plotter& g, int data[WIDTH])
{

    // Find the maximum number to
    // know number of digits
    int m = GetMax(data, WIDTH);

    // Do counting sort for every digit.
    // Note that instead of passing digit
    // number, exp is passed. exp is 10^i
    // where i is current digit number
    for (int exp = 1; m / exp > 0; exp *= 10)
        CountSort(g, data, exp);
}
int GetMax(int arr[], int n)
{
    int mx = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > mx)
            mx = arr[i];
    return mx;
}
void CountSort(SDL_Plotter& g, int arr[], int exp, int n)
{
    for(int i = 0; i < n; i++) {
        displayBar(g, arr[i], i, true);
    }

    // Output array
    int output[n];
    int i, count[10] = { 0 };

    // Store count of occurrences
    // in count[]
    for (i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;

    // Change count[i] so that count[i]
    // now contains actual position
    // of this digit in output[]
    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];

    // Build the output array
    for (i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    // Copy the output array to arr[],
    // so that arr[] now contains sorted
    // numbers according to current digit
    for (i = 0; i < n; i++) {
        arr[i] = output[i];
        displayBar(g, arr[i], i);
    }
    g.update();
    g.Sleep(20);
}


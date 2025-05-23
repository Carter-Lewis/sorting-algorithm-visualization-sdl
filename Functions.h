//
//  Functions.h
//  Graphics Testing
//
//  Created by Carter Lewis on 2/16/24.
//

#ifndef Functions_h
#define Functions_h
#include "SDL_Plotter.h"
const int HEIGHT = 1000;
const int WIDTH  = 1000;
void displayBar(SDL_Plotter& g, int height, int index, bool erase = false);
void insertionSort(SDL_Plotter& g, int data[WIDTH]);
void selectionSort(SDL_Plotter& g, int data[WIDTH]);
void bubbleSort   (SDL_Plotter& g, int data[WIDTH]);
int  partition(SDL_Plotter& g, int data[WIDTH], int left, int right);
void quickSort    (SDL_Plotter& g, int data[WIDTH], int left, int right);
void RadixSort    (SDL_Plotter& g, int data[WIDTH]);
void CountSort    (SDL_Plotter& g, int data[WIDTH], int exp, int n = WIDTH);
int  GetMax       (int data[WIDTH],int n= WIDTH);

#endif /* Functions_h */

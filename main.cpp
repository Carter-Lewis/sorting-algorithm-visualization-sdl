//
//  main.cpp
//  Graphics Testing
//
//  Created by Carter Lewis on 11/14/23.
//

#include <iostream>
#include "Functions.h"




int main(int argc, const char * argv[]) {
    SDL_Plotter g(HEIGHT, WIDTH);
    int data[WIDTH];
    char key;
     
    srand(10);
    for(int i = 0; i < WIDTH; i++) {
        data[i] = rand() % HEIGHT;
        displayBar(g, data[i], i);
    }
    g.update();
    while(!g.getQuit()) {
        if(g.kbhit()) {
            key = g.getKey();
        }
        if(key == 'x') g.setQuit(true);
        if(key == 'i') insertionSort(g, data);
        if(key == 's') selectionSort(g, data);
        if(key == 'b') bubbleSort(g, data);
        if(key == 'q') quickSort(g, data, 0, WIDTH);
        if(key == 'c') CountSort(g, data, HEIGHT);
//        if(key == 'r') RadixSort(g, data);
        if(key == 'r') {
            for(int i = 0; i < WIDTH; i++) {
                displayBar(g, data[i], i, true);
                data[i] = rand() % HEIGHT;
                displayBar(g, data[i], i);
            }
            g.update();
            key = 0;
        }
    }
    return 0;
}

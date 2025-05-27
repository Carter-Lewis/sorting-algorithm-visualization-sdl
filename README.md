To run the program, first ensure that SDL is installed. 
Download homebrew, then run:
brew install SDL2
brew install SDL2_mixer

Then, navigate to the directory of the project and enter these lines:
    g++ -std=c++11 main.cpp SDL_Plotter.cpp Functions.cpp -L/opt/homebrew/lib -I/opt/homebrew/include -lSDL2 -lSDL2_mixer
    ./a.out

Once the screen pops up, use these keybinds to run the program:
    r - randomly shuffle data
    b - bubble sort
    i - insertion sort
    

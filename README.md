# Sorting Algorithm Visualization Program

## Usage

1. **Install Dependencies (macOS):**  
   Use Homebrew to install SDL2 and SDL2_mixer:

   ```bash
   brew install SDL2
   brew install SDL2_mixer
   ```

2. **Build the Project:**  
   Navigate to the root directory of the project and compile the code using:

   ```bash
   g++ -std=c++11 main.cpp SDL_Plotter.cpp Functions.cpp -L/opt/homebrew/lib -I/opt/homebrew/include -lSDL2 -lSDL2_mixer
   ```

3. **Run the Program:**

   ```bash
   ./a.out
   ```

## Keybinds

- **r** — Randomly shuffle data  
- **b** — Bubble Sort  
- **i** — Insertion Sort  
- **q** — Quick Sort


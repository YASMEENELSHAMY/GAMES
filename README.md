## 🎮 C++ Console Games Collection

### Overview
This repository contains a collection of classic console-based board games implemented in C++ using object-oriented programming principles. The games feature player-vs-player and player-vs-computer modes with clean game logic separation.

### Games Included
- *X-O (Tic Tac Toe)*
- *Four in a Row*
- *Pyramid Board Game*

### Features
- Turn-based logic for each game
- Human and AI player classes
- Modular and reusable code structure
- Object-oriented design (players, boards, game manager)

### Technologies Used
- C++
- OOP (Object-Oriented Programming)
- Console I/O

### Project Structure
- App.cpp: Main entry point of the application  
- GameManager.cpp: Manages game flow and interactions  
- Player.cpp, RandomPlayer.cpp, RandomPlayer2.cpp: Player types including AI players  
- BoardGame_Classes.hpp: Core classes and game board logic  
- X_O_Board.cpp, Four_in_a_row.cpp, Pyramid_Board.cpp: Game-specific logic and UI  
- Player_Four_in_a_row.cpp: Specialized player class for Four in a Row  

### How to Run
1. Make sure you have a C++ compiler (e.g., g++) installed.
2. Navigate to the project directory.
3. Compile all .cpp files together:
   ```bash
   g++ *.cpp -o games

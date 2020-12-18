# chess_bot
An in development chess bot for the site lichess.org

## Table of Contents
* [Setup](#setup)
* [How it works](#how-it-works)

## Setup
As the projects consists of four subprojects there will be different setup guides depending on the purpose of usage.

### Chess Bot
* Navigate to solution file of the chess_engine (https://github.com/jamadaha/chess_bot/tree/master/chess_engine)
* Compile - The program is made for linux and will *proberly* only work on it
* Move the *.out* file to the same folder as the server file 
* Turn on server with node. See (https://github.com/jamadaha/chess_bot/tree/master/chess_server)

### Chess Bot Tests
These are standard unit test for a Visual Studio solution. Opening the chess_engine solution (https://github.com/jamadaha/chess_bot/tree/master/chess_engine) will display them automatically.

### Data Cleaning
Not working atm. 

## How it works
### Chess engine
There are three primary parts to how this chess engine works: move generation, board evaluation and Minimax. These parts work together to generate a move given PGN input (or other input types).
#### Move generation
This works by going through all pieces for the side whose turn it is, where all pieces gone through is checked for valid moves. A valid move is any move which is legal in a game of chess. 
The moves are generated in a relativly naive manner, as all moves are generated 

#### Board evaluation

#### Minimax
As it stands the algorithm searches a fixed depth, therefore, the time taken to generate increases with the complexity of the position.

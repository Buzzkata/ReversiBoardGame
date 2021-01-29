//Bozhidar Stoyanov, 0353616
#ifndef GAME_H_
#define GAME_H_
#include "Board.h"
#include "Player.h"

// A class that controls the flow of the game
class Game {
public:
	// Default constructor; initializes an empty board and sets player pointers to NULL
	Game();

	// Deconstructor; deallocates any dynamically allocated objects
	~Game();

	// Prompts the user for the type of each player (human or computer)
	// If human, the function asks for the player's name; then creates
	// the objects for the players dynamically
	void selectPlayers();

	// Returns the pointer to the current player
	Player* nextPlayer() const;

	// While isRunning returns true, the function displays the board and invokes
	// the makeMove() function of the player whose move it is
	void play();

	// Announces the end of the game, and the name of the winner or a tie
	void announceWinner();
};

#endif
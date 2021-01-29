//Bozhidar Stoyanov, 0353616
#ifndef HUMAN_PLAYER_H_
#define HUMAN_PLAYER_H_
#include "Player.h"

// A class derived from the class Player
class HumanPlayer : public Player {
	// Prompts the user for the position where they want to place their piece
	void makeMove();
};

#endif
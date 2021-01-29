//Bozhidar Stoyanov, 0353616
#ifndef COMPUTER_PLAYER_H_
#define COMPUTER_PLAYER_H_
#include "Piece.h"
#include "Player.h"

// An abstract base class derived from the class Player
class ComputerPlayer : public Player {
public:
	// Generates the player's name and passes it to the base class constructor
	ComputerPlayer(Piece);
};

#endif
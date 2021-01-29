//Bozhidar Stoyanov, 0353616
#ifndef RANDOM_PLAYER_H_
#define RANDOM_PLAYER_H_
#include "ComputerPlayer.h"

// Class implements ComputerPlayer base class
class RandomPlayer : public ComputerPlayer {
	// This method makes the computer make a random
	// but legal move
	void makeMove();
};

#endif
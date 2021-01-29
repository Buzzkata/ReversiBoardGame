//Bozhidar Stoyanov, 0353616
#include "RandomPlayer.h"
#include "Board.h"
#include "Game.h"
#include "ReversiTester.h"

#include <vector>

using namespace std;
//random player class
class RandomPlayer : public ComputerPlayer {
	
	vector<Move> validMoves;
	
	void makeMove() {
		genValidMoves();
	}

	void genValidMoves() {
		for (int i = 0; i < 64; i++) {

		}
	}
};
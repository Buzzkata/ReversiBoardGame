//Bozhidar Stoyanov, 0353616
#include "Player.h"
#include <iostream>

using namespace std;
//the main player class
class Player {
public:
	string Name;
	Piece PieceColour;
	Player(const string& PlayerName, Piece PlayerPiece) {
		Name = PlayerName;
		PieceColour = PlayerPiece;
	}

	virtual ~Player() {

	}

	virtual void makeMove(Board&) {

	}
};
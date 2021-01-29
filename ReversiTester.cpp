//Bozhidar Stoyanov, 0353616


#include "Board.h"
#include "ComputerPlayer.h"
#include "Game.h"
#include "HumanPlayer.h"
#include "Move.h"
#include "NullMove.h"
#include "Piece.h"
#include "Player.h"
#include "RandomPlayer.h"
#include "ReversiTester.h"

Game* reversiGame;

int main() {
		reversiGame = new Game();
		reversiGame->selectPlayers;
		reversiGame->play;
}

Game* returnGame() {
	return reversiGame;
}
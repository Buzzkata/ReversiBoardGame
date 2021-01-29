//Bozhidar Stoyanov, 0353616
#include "Game.h"
#include "Player.h"
#include "HumanPlayer.h"
#include "Piece.h"
#include <iostream>

using namespace std;

class Game {
public:
	Board* game;
	Player* playerOne;
	Piece* playerOnePiece = new Piece();
	Player* playerTwo;
	Piece* playerTwoPiece = new Piece();

	Game() {
		game = new Board();
		playerOne = NULL;
		playerTwo = NULL;
		playerOnePiece = Piece::LIGHT;
	}

	~Game() {
		delete[] game;
	}

	void selectPlayers() {
		int typeOne;
		int typeTwo;
		cout << "Is Player 1 human or computer? (reply '1' for human, reply '2' for computer)";
		cin >> typeOne;
		cout << "Is Player 2 human or computer? (reply '1' for human, reply '2' for computer)";
		cin >> typeTwo;
		switch (typeOne) {
		case 1:
			string temp;
			cout << "Enter the player's name: ";
			cin >> temp;
			const string& playerNameOne = temp;
			playerOne = new Player(playerNameOne, Piece::LIGHT);
			break;
		}
	}

	Board* returnBoard() {
		return game;
	}

	Player* nextPlayer() const {

	}

	void play() {
		int temp;
		while (isRunning) {
			cin >> temp;
			game->makeMove(Piece::LIGHT, temp);
		}
	}

	void announceWinner() {
		cout << "End of game!\s";
		if (&game->getWinner() == playerOnePiece->getPiece)
			cout << "Player 1 won!";
		else if (&game->getWinner() == playerTwoPiece->getPiece)
			cout << "Player 2 won!";
		else
			cout << "Tie!";

	}

	bool isRunning() {
		if(&board->numMoves()>0){
			return true;
		}
		return false;
	}
};
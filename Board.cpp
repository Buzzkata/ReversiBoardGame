//Bozhidar Stoyanov, 0353616
#include "Board.h"
#include "Piece.h"
#include "Move.h"
#include <iostream>
#include <vector>
using namespace std;

class Board {
public:

	enum Piece { LIGHT, DARK, EMPTY };

	// Create a board using the defined area
	Piece gameBoard[BOARD_AREA];

	// Default constructor that initializes the board by calling the member function reset()
	Board() {
		reset();
	}

	// Erases all pieces from the board and sets up a standard game
	void reset() {
		// Loop through the entire board
		for (int i = 0; i < BOARD_AREA; ++i) {
			// Light pieces start on coordinates d4 and e5, or in this case index 27 and 36
			if (i == 27 || i == 36) {
				gameBoard[i] = LIGHT;
			}
			// Dark pieces start on coordinates e4 and d5, or in this case index 28 and 35
			else if (i == 28 || i == 35) {
				gameBoard[i] = DARK;
			}
			// All other game squares start off empty
			else {
				gameBoard[i] = EMPTY;
			}
		}
	}
	//display the board function
	void display() const {
		for (int i = 0; i < BOARD_Y; ++i) {
			for (int j = 0; j < BOARD_X; ++j) {
				char tempChar;
				switch (gameBoard[j]) {
				case EMPTY:
					tempChar = '-';
					break;
				case LIGHT:
					tempChar = 'L';
					break;
				case DARK:
					tempChar = 'D';
					break;
				}
				cout << tempChar << "\t";
			}
			cout << endl;
		}
	}
	//make a move function that makes a move
	void makeMove(Piece PieceToMove, Move MoveToMake) {
		gameBoard[MoveToMake] = PieceToMove;
	}
	//function to check if move is legal
	bool isLegal(Piece PieceToCheck, Move MoveToCheck) const {
		Piece oppositeColour;

		Piece temp = oppositeColour;

		if (PieceToCheck == LIGHT) oppositeColour = DARK;

		else oppositeColour = LIGHT;

		if (gameBoard[MoveToCheck] != EMPTY) return false;

		//if its left and right: for loop looks in increments of 1 in both directions
		//for same colour. first must be opposite colour and there cannot be
		//a empty spot. legal if same coloured piece is reached.
		for (int i = 1; gameBoard[MoveToCheck - i] != EMPTY; --i) { // To the left of the piece

			if (i == 1 && gameBoard[MoveToCheck - i] != oppositeColour) break; //if the first adjacent piece isn't the oposite colour

			if (gameBoard[MoveToCheck - i] == gameBoard[MoveToCheck]) return true; //the if statement above hasn't borken the loop 
				//yet so there is at least one piece of the opposite colour and following a piece of the same colour.

			if ((MoveToCheck - i) % 8 == 0) break; //if the loop reaches the end of the row

		}

		for (int i = 1; gameBoard[MoveToCheck + i] != EMPTY; ++i) { // To the right of the piece

			if (i == 1 && gameBoard[MoveToCheck + i] != oppositeColour) break; //if the first adjacent piece isn't the oposite colour

			if (gameBoard[MoveToCheck + i] == gameBoard[MoveToCheck]) return true; //the if statement above hasn't borken the loop 
				//yet so there is at least one piece of the opposite colour and following a piece of the same colour.

			if ((MoveToCheck + i) % 8 == 0) break; //if the loop reaches the end of the row

		}

		//if its up and down: position is >0, <65, is 8 positions
		//from the other colour piece and in the same direction there
		//is eventually the same coloured piece without any empty
		//pieces inbetween. looks for the same coloured piece then stops at one.
		for (int i = 8; gameBoard[MoveToCheck - i] != EMPTY; i - 8) { // Above the piece

			if (i == 8 && gameBoard[MoveToCheck - i] != oppositeColour) break; //if the first adjacent piece isn't the oposite colour

			if (gameBoard[MoveToCheck - i] == gameBoard[MoveToCheck]) return true; //the if statement above hasn't borken the loop 
				//yet so there is at least one piece of the opposite colour and following a piece of the same colour.

			if ((MoveToCheck - i) < 1) break; //if the loop reaches the end of the column

		}

		for (int i = 8; gameBoard[MoveToCheck + i] != EMPTY; i + 8) { // Below the piece

			if (i == 8 && gameBoard[MoveToCheck + i] != oppositeColour) break; //if the first adjacent piece isn't the oposite colour

			if (gameBoard[MoveToCheck + i] == gameBoard[MoveToCheck]) return true; //the if statement above hasn't borken the loop 
				//yet so there is at least one piece of the opposite colour and following a piece of the same colour.

			if ((MoveToCheck + i) > 64) break; //if the loop reaches the end of the column

		}

		//if its diagonal: uses tactic from above two. when it goes up or down it also increments over in either direction
		for (int i = 9; gameBoard[MoveToCheck - i] != EMPTY; i - 9) { // The left diagonal above the piece

			if (i == 9 && gameBoard[MoveToCheck - i] != oppositeColour) break; //if the first adjacent piece isn't the oposite colour

			if (gameBoard[MoveToCheck - i] == gameBoard[MoveToCheck]) return true; //the if statement above hasn't borken the loop 
				//yet so there is at least one piece of the opposite colour and following a piece of the same colour.

			if ((MoveToCheck - i) % 8 == 0 || (MoveToCheck - i) < 1) break; //if the loop reaches the end of the row or column

		}

		for (int i = 7; gameBoard[MoveToCheck - i] != EMPTY; i - 7) { // The right diagonal above the piece

			if (i == 7 && gameBoard[MoveToCheck - i] != oppositeColour) break; //if the first adjacent piece isn't the oposite colour

			if (gameBoard[MoveToCheck - i] == gameBoard[MoveToCheck]) return true; //the if statement above hasn't borken the loop 
				//yet so there is at least one piece of the opposite colour and following a piece of the same colour.

			if ((MoveToCheck - i) % 8 == 0 || (MoveToCheck - i) < 1) break; //if the loop reaches the end of the row or column

		}

		for (int i = 7; gameBoard[MoveToCheck + i] != EMPTY; i + 7) { // The left diagonal above the piece

			if (i == 7 && gameBoard[MoveToCheck + i] != oppositeColour) break; //if the first adjacent piece isn't the oposite colour

			if (gameBoard[MoveToCheck + i] == gameBoard[MoveToCheck]) return true; //the if statement above hasn't borken the loop 
				//yet so there is at least one piece of the opposite colour and following a piece of the same colour.

			if ((MoveToCheck + i) % 8 == 0 || (MoveToCheck + i) > 64) break; //if the loop reaches the end of the row or column

		}

		for (int i = 9; gameBoard[MoveToCheck + i] != EMPTY; i + 9) { // The left diagonal above the piece

			if (i == 9 && gameBoard[MoveToCheck + i] != oppositeColour) break; //if the first adjacent piece isn't the oposite colour

			if (gameBoard[MoveToCheck + i] == gameBoard[MoveToCheck]) return true; //the if statement above hasn't borken the loop 
				//yet so there is at least one piece of the opposite colour and following a piece of the same colour.

			if ((MoveToCheck + i) % 8 == 0 || (MoveToCheck + i) > 64) break; //if the loop reaches the end of the row or column

		}

		return false;
	}
	//function that returns the winner
	Piece getWinner() const {
		int count = 0;
		for (int i = 0; i < BOARD_AREA; ++i)
			if (gameBoard[i] == LIGHT)
				++count;
		if (count > 32)
			return LIGHT;
		else if (count < 32)
			return DARK;
		return EMPTY;
	}

	Piece getPlayer() const {
		//getMove();
	}

	void genMoves(Piece PieceToCheck) {

		cout << "Moves available: ";

		for (int i = 0; i < BOARD_AREA; ++i) {

			Move MoveToCheck = i;

			if (isLegal(PieceToCheck, MoveToCheck)) {

				int col = i % 8;

				int row = (i - col + 8) / 8;

				cout << "Column - " << col << "\n Row - " << row << "\n";

			}
		}

		cout << "END";
	}
	//function to return numbero of moves available
	int numMoves() const {
		int count = 0;
		for (int i = 0; i < BOARD_AREA; ++i)
			if (isLegal(gameBoard[i], i))
				++count;
		return count;
	}
	//method that returns the move
	Move getMove(int MoveToReturn) const {
		return gameBoard[MoveToReturn];
	}
};
//Bozhidar Stoyanov, 0353616
#ifndef BOARD_H_
#define BOARD_H_
#include "Piece.h"
#include "Move.h"

// A standard Reversi/Othello board consists of an 8x8 matrix
#define BOARD_X 8
#define BOARD_Y 8
#define BOARD_AREA BOARD_X * BOARD_Y

// This class represents the current state of the board.
class Board {
public:
	// Default constructor that initializes the board by calling the member function reset()
	Board();

	// Erases all pieces from the board and sets up a standard game
	void reset();

	// Displays the board
	void display() const;

	// Executes the move indicated by the function parameters and calls
	void makeMove(Piece, Move);

	// Checks whether it is legal to place the given Piece on the square named by the second parameter
	bool isLegal(Piece, Move) const;

	// Returns the color of the winning side. If nobody has won yet, the function returns EMPTY
	Piece getWinner() const;

	// Returns the color of the Player whose turn it is
	Piece getPlayer() const;

	// Generates a list of moves that are possible in the current position (usually called by the makeMove() function)
	void genMoves();

	// Returns the number of valid moves
	int numMoves() const;

	// Returns the move specified by the integer parameter
	Move getMove(int) const;
};

#endif
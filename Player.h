//Bozhidar Stoyanov, 0353616
#ifndef PLAYER_H_
#define PLAYER_H_
#include "Piece.h"
#include "Board.h"
#include <string>

// Abstract base class for all human and computer players
class Player {
public:
	// Constructor of the Player class which creates a player with
	// a specified name and piece colour
	Player(const std::string&, Piece);

	// Default virtual deconstructor
	virtual ~Player();

	//getPiece gets defined in Piece.h as it is using the base class Piece
	//Piece Piece::getPiece() const;

	// Pure virtual function which makes players move their piece on the board
	virtual void makeMove(Board&);
};

#endif
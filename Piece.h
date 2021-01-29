//Bozhidar Stoyanov, 0353616
#ifndef PIECE_H_
#define PIECE_H_

// The class piece contains an enumerator and a member function
class Piece {
public:
	// An enumerator which represents all possible states of an index on the board
	enum {LIGHT, DARK, EMPTY};

	// A member function which returns the type of piece that the
	// player who called the function has.
	Piece getPiece() const;
};

#endif
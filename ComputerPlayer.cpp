//Bozhidar Stoyanov, 0353616
#include "ComputerPlayer.h"
#include <iostream>;
#include <string>
using namespace std;

class ComputerPlayer : public Player {
public:
	char a = 'A';
	ComputerPlayer(Piece PlayersPiece) {
		string currentComp = "Computer " + a;
		a++;
		Player* currentComp;
	}
};
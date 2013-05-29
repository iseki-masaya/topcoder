#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

class EllysCheckers {
public:
	string getWinner(string board)
	{
		int move = 0;
		int right = static_cast<int>(board.size())-1;
		for (int i=0; i<board.size(); ++i) {
			if (board.at(i)=='o') {
				move += right - i;
			}
		}

		return move%2==0?"NO":"YES";
	}
};
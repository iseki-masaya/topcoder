#include <iostream>
#include <vector>
#include <string>

using namespace std;

class PenguinTiles
{
public:
	int minMoves(vector<string> tiles)
	{
		int maxY = (int)tiles.size();
		int maxX = (int)tiles.at(0).size();
		
		if(tiles.at(maxY-1).at(maxX-1) == '.')
			return 0;
		
		for (int i=0; i<tiles.at(maxY-1).size(); ++i) {
			if (tiles.at(maxY-1).at(i) == '.') {
				return 1;
			}
		}
		for (int i=0; i<tiles.size(); ++i) {
			if (tiles.at(i).at(maxX-1) == '.') {
				return 1;
			}
		}
		return 2;
	}
};
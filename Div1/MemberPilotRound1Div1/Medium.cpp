#include <iostream>
#include <vector>
#include <string>

using namespace std;

class CantorDust
{
public:
	string getPattern(int T)
	{
		if (T == 0) return "X";

		string s = getPattern(T-1);
		return s + string(s.size(), '.') + s;
	}

	int occurrencesNumber(vector <string> pattern, int time)
	{
		int sizeY = static_cast<int>(pattern.size());
		int sizeX = static_cast<int>(pattern.at(0).size());
		bool isBlackX[sizeX];
		bool isBlackY[sizeY];
		for (int x=0; x<sizeX; ++x) isBlackX[x] = false;
		for (int y=0; y<sizeY; ++y) isBlackY[y] = false;
		string linePattern = getPattern(time);
		int sizeFractal = static_cast<int>(linePattern.size());
		int numMatchX = 0,numMatchY = 0;

		bool flag = false;

		for (int x=0; x<sizeX; ++x) {
			for (int y=0; y<sizeY; ++y) {
				if (pattern[y][x] == 'X') {
					isBlackX[x] = isBlackY[y] = flag = true;
				}
			}
		}

		for (int x=0; x<sizeX; ++x) {
			for (int y=0; y<sizeY; ++y) {
				if ((pattern[y][x] == 'X') != (isBlackX[x] && isBlackY[y])) {
					return 0;
				}
			}
		}

		for (int i=0; i+sizeX <= sizeFractal; ++i) {
			int x;
			for (x=0; x<sizeX; ++x) {
				if ((linePattern.at(i+x) == 'X') != isBlackX[x]) {
					break;
				}
			}
			if (x == sizeX) {
				++numMatchX;
			}
		}

		for (int i=0; i+sizeY <= sizeFractal; ++i) {
			int y;
			for (y=0; y<sizeY; ++y) {
				if ((linePattern.at(i+y)=='X') != isBlackY[y]) {
					break;
				}
			}
			if (y == sizeY) {
				++numMatchY;
			}
		}

		if (flag) {
			return numMatchX * numMatchY;
		}
		else {
			return numMatchX*(sizeFractal - sizeY + 1) + numMatchY*(sizeFractal - sizeX + 1) - numMatchX*numMatchY;
		}
	}
};
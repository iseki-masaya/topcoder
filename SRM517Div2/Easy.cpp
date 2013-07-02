#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <bitset>
#include <queue>
#include <algorithm>
#include <functional>
#include <cmath>
#include <cstdio>
#include <sstream>
#include <stack>
#include <fstream>
#include <istream>

using namespace std;

class MonochromaticBoard {
public:
  int theMin(vector <string> board)
	{
		int wy=0;
		for (int y = 0; y < board.size(); ++y) {
			int wcy = 0;
			for (int x = 0; x < board[y].size(); ++x) {
				if (board[y][x] == 'W') {
					++wcy;
				}
			}
			wy = max(wy,wcy);
		}
		int wx=0;
		for (int x = 0; x < board[0].size(); ++x) {
			int wcx = 0;
			for (int y = 0; y < board.size(); ++y) {
				if (board[y][x] == 'W') {
					++wcx;
				}
			}
			wx = max(wx,wcx);
		}

		int ans;
		if (wx == 0 && wy == 0) {
			ans = static_cast<int>(min(board.size(),board[0].size()));
		}
		else {
			ans = static_cast<int>(board.size()-wy + board[0].size()-wx);
		}

		return ans;
	}
};
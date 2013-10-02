#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <bitset>
#include <queue>
#include <algorithm>
#include <functional>

using namespace std;

#define MAX_N 51

bool memo[MAX_N][MAX_N] = {false};

class GogoXCake {
public:
	string solve(vector <string> cake, vector <string> cutter)
	{
		for (int y=0; y<cake.size(); ++y) {
			for (int x=0; x<cake.at(0).size(); ++x) {
				if (cake[y][x]=='X')
					memo[y][x] = true;
			}
		}

		for (int y=0; y<cake.size()-cutter.size()+1; ++y) {
			for (int x=0; x< (cake.at(0).size()-cutter.at(0).size()+1); ++x) {
					bool isMatch = true;
					for (int dy=0; dy<cutter.size(); ++dy) {
						for (int dx=0; dx<cutter.at(0).size(); ++dx) {
							if (cutter[dy][dx] == '.' && (cake[y+dy][x+dx] != '.' || memo[y+dy][x+dx])) {
								isMatch = false;
								dy = static_cast<int>(cutter.size()); // for break;
								break;
							}
						}
					}

					if (isMatch)
						for (int dy = 0; dy < cutter.size(); ++dy)
							for (int dx = 0; dx < cutter.at(0).size(); ++dx)
								if (cutter[dy][dx] == '.')
									memo[y+dy][x+dx] = true;
			}
		}

		for (int y=0; y<cake.size(); ++y) {
			for (int x=0; x<cake.at(0).size(); ++x) {
				if (!memo[y][x])
					return "NO";
			}
		}

		return "YES";
	}
};
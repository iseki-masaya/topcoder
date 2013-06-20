#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <bitset>
#include <queue>
#include <algorithm>
#include <functional>
#include <cmath>
#include <cstdio>
#include <sstream>

using namespace std;

int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};

class AlphabetPath {
	struct point {
		int x,y;
	};

	point
	searchA(vector<string> &letterMAze)
	{
		point p;
		for (int y=0; y<letterMAze.size(); ++y) {
			for (int x=0; x<letterMAze[0].size(); ++x) {
				if (letterMAze[y][x]=='A') {
					p.x = x;
					p.y = y;
					return p;
				}
			}
		}

		p.x = -1; p.y = -1;
		return p;
	}
public:
	string doesItExist(vector <string> letterMaze)
	{
		point p = searchA(letterMaze);

		char L = 'A';
		for (int i=0; i<26; ++i) {
			for (int j=0; j<4; ++j) {
				int x = p.x + dx[j];
				int y = p.y + dy[j];
				if (x < 0 || x >= letterMaze[0].size() || y < 0 || y >= letterMaze.size()) {
					continue;
				}

				if (letterMaze[y][x] == (L+1)) {
					L = L + 1;
					p.x = x;
					p.y = y;
					break;
				}
			}
		}

		return L=='Z'?"YES":"NO";
	}
};
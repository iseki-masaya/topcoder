#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <list>
#include <algorithm>
#include <sstream>
#include <set>
#include <cmath>
#include <map>
#include <stack>
#include <queue>
#include <stdio.h>
#include <string.h>

using namespace std;

bool usedV[53][53];
bool usedH[53][53];

class ColoredStrokes {
public:
	void
	fill_vertical(int y,int x,vector<string> &p)
	{
		while (y<p.size()&&(p[y][x] == 'B' || p[y][x] == 'G')) {
			usedV[y++][x] = true;
		}
	}

	void
	fill_horizontal(int y,int x,vector<string> &p)
	{
		while (x<p[0].size() && (p[y][x] == 'R' || p[y][x] == 'G')) {
			usedH[y][x++] = true;
		}
	}

	int
	getLeast(vector <string> picture)
	{
		int ans=0;
		memset(usedV, false, sizeof(usedV));
		memset(usedH, false, sizeof(usedH));
		for (int y=0; y<picture.size(); ++y) {
			for (int x=0; x<picture[0].size(); ++x) {
				if (!usedV[y][x] && (picture[y][x] == 'B' || picture[y][x] == 'G')) {
					++ans;
					fill_vertical(y,x,picture);
				}
				if(!usedH[y][x] && (picture[y][x] == 'R' || picture[y][x] == 'G')) {
					++ans;
					fill_horizontal(y,x,picture);
				}
			}
		}
		for (int y=0; y<picture.size(); ++y) {
			for (int x=0; x<picture[0].size(); ++x) {
				if (picture[y][x]=='G' && !usedH[y][x] && !usedV[y][x]) {
					ans += 2;
				}
				else if (picture[y][x]=='G' && (!usedH[y][x] || !usedV[y][x]) ) {
					++ans;
				}
			}
		}
		return ans;
	}
};
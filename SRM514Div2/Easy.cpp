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

#define INF (1<<20)
#define MAX 101

using namespace std;

class MagicalGirlLevelOneDivTwo {
public:
	double calcDist(int x,int y) {
		return sqrt(x*x+y*y);
	}

	double theMinDistance(int d, int x, int y)
	{
		double ans = calcDist(x, y);
		for (int dx=-d; dx<=d; ++dx) {
			for (int dy=-d; dy<=d; ++dy) {
				ans = min(ans,calcDist(x+dx, y+dy));
			}
		}
		return ans;
	}
};
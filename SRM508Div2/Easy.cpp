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

#define MAX_V (10000001)
#define MAX_N (100001)
#define MOD 1000000007

using namespace std;

int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};

class CandyShop {
public:
	bool
	isIn(int cx,int cy,int px,int py,int r)
	{
		return r>=abs(cx-px)+abs(cy-py);
	}

  int
	countProbablePlaces(vector <int> X, vector <int> Y, vector <int> R)
	{
		int ans = 0;
		for (int y = -205; y <= 205; ++y) {
			for (int x = -205; x <= 205; ++x) {
				bool isAllIn = true;
				for (int i=0; i<X.size(); ++i) {
					if (!isIn(X[i], Y[i], x, y, R[i])) {
						isAllIn = false;
						break;
					}
				}
				if (isAllIn) {
					++ans;
				}
			}
		}
		return ans;
	}
};
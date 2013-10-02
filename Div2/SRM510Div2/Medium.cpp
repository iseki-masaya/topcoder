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

#define I_INF (1<<20)
#define F_INF 1e7
#define MAX 41

using namespace std;

class TheLuckyGameDivTwo {
public:
	bool isLuck(int a)
	{
		while (a > 0) {
			if (a%10!=7 && a%10!=4) {
				return false;
			}
			a /= 10;
		}
		return true;
	}

	int find(int a, int b, int jLen, int bLen)
	{
		vector<int> x(b+2);
		x[0] = 0;
		for (int i=1; i<=b; ++i) {
			x[i+1] = x[i] + isLuck(i);
		}
		int ans=0;
		for (int js=a; js+jLen-1<=b; ++js) {
			int mn = I_INF;
			for (int bs=js; bs+bLen-1<=js+jLen-1; ++bs) {
				int c = x[bs+bLen] - x[bs];
				mn = min(mn,c);
			}
			ans = max(ans,mn);
		}
		return ans;
	}
};
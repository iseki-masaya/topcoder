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

class TheAlmostLuckyNumbersDivTwo {
public:
	bool isAlmostLuck(int a)
	{
		int cnt=0;
		while (a > 0) {
			if (a%10!=7 && a%10!=4) {
				++cnt;
			}
			a /= 10;
		}
		return cnt<2?true:false;
	}

	int find(int a, int b)
	{
		int ans = 0;
		for (int i=a; i<=b; ++i) {
			if (isAlmostLuck(i)) {
				++ans;
			}
		}
		return ans;
	}
};
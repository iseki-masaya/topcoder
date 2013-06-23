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

#define INF (1<<26)

class RedAndGreen {
public:
	int calcCost(string &row,int bound)
	{
		int cost = 0;
		for (int i=0; i<bound; ++i) {
			if (row[i] == 'G') {
				++cost;
			}
		}
		for (int i=bound; i<row.size(); ++i) {
			if (row[i] == 'R') {
				++cost;
			}
		}

		return cost;
	}

	int minPaints(string row)
	{
		int ans = INF;
		for (int i=0; i<=row.size(); ++i) {
			ans = min(ans,calcCost(row, i));
		}
		return ans;
	}
};
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
#include <stack>

using namespace std;

#define INF (1<<26)

int decrease[3] = {2,4,8};

class SRMCodingPhase {
public:
	int countScore(vector <int> points, vector <int> skills, int luck)
	{
		int ans = 0;
		int per[] = {0,1,2};
		int S = 3;

		do {
			int ret = 0;
			int rest = 75;
			int l = luck;
			for (int i=0; i<3; ++i) {
				if (skills[per[i]]-l <= rest) {
					if (l - skills[per[i]] >= 0) {
						ret += points[per[i]] - decrease[per[i]];
						l -= skills[per[i]]-1;
						--rest;
					}
					else {
						ret += points[per[i]] - decrease[per[i]]*(skills[per[i]]-l);
						rest -= (skills[per[i]]- l);
						l = 0;
					}
				}
			}
			ans = max(ans,ret);
		} while (next_permutation(per, per + S));

		return ans;
	}
};
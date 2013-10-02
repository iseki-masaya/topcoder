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

class TheProgrammingContestDivTwo {
public:
	vector <int>
	find(int T, vector <int> requiredTime)
	{
		sort(requiredTime.begin(), requiredTime.end());
		int now=0,sum=0,solve=0;
		for (int i=0; i<requiredTime.size(); ++i) {
			if (now+requiredTime[i]<=T) {
				++solve;
				now += requiredTime[i];
				sum += now;
			}
			else {
				break;
			}
		}

		vector<int> ans(2);
		ans[0] = solve; ans[1] = sum;
		return ans;
	}
};

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

class PointErasingTwo {
public:
  int getMaximum(vector <int> y)
	{
		int ans = 0;
		for (int i=0; i<y.size(); ++i) {
			for (int j=i+1; j<y.size(); ++j) {
				int cnt = 0;
				for (int k=i+1; k<j; ++k) {
					if (min(y[i],y[j]) < y[k] && y[k] < max(y[i],y[j])) {
						++cnt;
					}
				}
				ans = max(ans,cnt);
			}
		}

		return ans;
	}
};
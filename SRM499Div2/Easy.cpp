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

class SimpleGuess {
public:
  int
	getMaximum(vector <int> hints)
	{
		sort(hints.begin(), hints.end(), greater<int>());
		int ans = 0;
		for (int i=0; i<hints.size(); ++i) {
			int sum = hints[i];
			for (int X=sum-1,Y=1; X>=Y; --X,++Y) {
				if (find(hints.begin(), hints.end(), X-Y) != hints.end()) {
					ans = max(ans,X*Y);
				}
			}
		}
		return ans;
	}
};
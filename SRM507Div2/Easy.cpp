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

class CubeAnts {
public:
	int
	getMinimumSteps(vector <int> pos)
	{
		int ans = 0;
		for (int i=0; i<pos.size(); ++i) {
			if (pos[i]==1 || pos[i] == 4 || pos[i] ==3) {
				ans = max(ans,1);
			}
			else if (pos[i]==2 || pos[i]==5 || pos[i]==7)	{
				ans = max(ans,2);
			}
			else if (pos[i] == 6) {
				ans = max(ans,3);
			}
		}
		return ans;
	}
};
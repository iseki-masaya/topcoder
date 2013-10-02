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

class SlimeXSlimeRancher2 {
public:
  int
	train(vector <int> attributes)
	{
		sort(attributes.begin(), attributes.end(), greater<int>());
		int res = 0;
		for (int i=1; i<attributes.size(); ++i) {
			res += attributes[0] -attributes[i];
		}
		return res;
	}
};
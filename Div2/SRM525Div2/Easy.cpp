#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <bitset>
#include <queue>
#include <algorithm>
#include <functional>
#include <cmath>

using namespace std;

class RainyRoad {
public:
  string isReachable(vector <string> road)
	{
		if (road[0][road[0].size()-1] == 'W')
			return "NO";

		for (int i=0; i<road[0].size(); ++i) {
			if (road[0][i] == 'W' && road[1][i] == 'W')
				return "NO";
		}

		return "YES";
	}
};
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <bitset>
#include <queue>
#include <algorithm>
#include <functional>
#include <cstdio>

using namespace std;

class PairingPawns {
public:
  int savedPawnCount(vector <int> start)
	{
		double ans = start.at(0);
		for (int i=1; i<start.size(); ++i) {
			ans += start.at(i)/static_cast<double>((1<<i));
		}

		return static_cast<int>(ans);
	}
};
#include <vector>
#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

#define MAX 1000000

class DengklekTryingToSleep {
public:
  int minDucks(vector <int> ducks)
	{
		int mx = 0;
		int mn = MAX;
		for (int i=0; i<ducks.size(); ++i) {
			mx = max(mx,ducks.at(i));
			mn = min(mn,ducks.at(i));
		}

		return (mx-mn+1)-static_cast<int>(ducks.size());
	}
};
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <bitset>
#include <queue>
#include <algorithm>
#include <functional>

using namespace std;

class GogoXBallsAndBinsEasy {
public:
  int solve(vector <int> T)
	{
		vector<int> S(T);
		sort(S.begin(), S.end(), greater<int>());

		int ans = 0;
		int i=0;
		while (S.at(i) > T.at(i)) {
			ans += S.at(i) - T.at(i);
			++i;
		}

		return ans;
	}
};
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <cmath>

using namespace std;

class DeerInZooDivTwo
{
public:
	vector <int> getminmax(int N, int K)
	{
		vector<int> ans;
		int small;
		if (N >= K) {
			small = N - K;
		}
		else {
			small = 0;
		}

		int large = N - (K+1)/2;

		ans.push_back(small);
		ans.push_back(large);

		return ans;
	}
};
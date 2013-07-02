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

#define INF (1<<20)
#define MAX 101

using namespace std;

class YetAnotherIncredibleMachine {
public:
	int countWays(vector <int> platformMount, vector <int> platformLength, vector <int> balls)
	{
		long long ans = 1;
		for (int i=0; i<platformLength.size(); ++i) {
			int left=-1;
			for (int j=0; j<=platformLength[i]; ++j) {
				left = platformMount[i]-j;
				if (find(balls.begin(), balls.end(), left) != balls.end()) {
					++left;
					break;
				}
			}
			int right=-1;
			for (int j=0; j<=platformLength[i]; ++j) {
				right = platformMount[i]+j;
				if (find(balls.begin(), balls.end(), right) != balls.end()) {
					--right;
					break;
				}
			}

			int ways = (right-left) - platformLength[i] + 1;
			if (ways < 1) {
				return 0;
			}
			ans = (ans*ways)%1000000009;

		}
		return (int)ans;
	}
};
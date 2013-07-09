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

class SlimeXSlimesCity {
public:
	int
	merge(vector <int> population)
	{
		int res = 0;
		for (int i=0; i<population.size(); ++i) {
			vector<int> p(population);
			long long sum = p[i];
			p[i] = -1;
			sort(p.begin(), p.end());

			bool isOk = true;
			for (int j=1; j<p.size(); ++j) {
				if (sum >= p[j]) {
					sum += p[j];
				}
				else {
					isOk = false;
					break;
				}
			}

			if (isOk) {
				++res;
			}
		}

		return res;
	}
};
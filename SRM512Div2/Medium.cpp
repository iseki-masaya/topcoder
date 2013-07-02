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

#define INF (1<<20)
#define MAX 101

using namespace std;

char l[] =
{'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};

class MysteriousRestaurant {
public:
	int maxDays(vector <string> prices, int budget)
	{
		map<char, int> conv;
		for (int i=1; i<sizeof(l)+1; ++i) {
			conv[l[i]] = i;
		}

		int ans=0;
		for (int mxday = 1; mxday<=prices.size(); ++mxday) {
			vector<int> cost(7,0);
			for (int d=0; d<min(7,mxday); ++d) {
				int mn = INF;
				for (int t=0; t<prices[0].size(); ++t) {
					int work=0;
					int dd = d;
					while (dd < mxday) {
						work += conv[prices[dd][t]];
						dd += 7;
					}
					mn = min(mn,work);
				}
				cost[d] = mn;
			}
			int sum = 0;
			for (int i=0; i<7; ++i) {
				sum+=cost[i];
			}
			if (sum > budget) {
				break;
			}
			else {
				ans = mxday;
			}
		}
		return ans;
	}
};
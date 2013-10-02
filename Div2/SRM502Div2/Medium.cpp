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
#include <stdio.h>
#include <string.h>

using namespace std;

class TheLotteryBothDivs {
public:
	static
	bool
	comp(const string &lhs,const string &rhs)
	{
		return lhs.size() < rhs.size();
	}

	double
	find(vector <string> goodSuffixes)
	{
		sort(goodSuffixes.begin(), goodSuffixes.end(),comp);
		vector<bool> used(goodSuffixes.size());
		vector<string> uni;
		for (int i=0; i<goodSuffixes.size(); ++i) {
			if (used[i]) {
				continue;
			}
			string str = goodSuffixes[i];
			uni.push_back(str);

			for (int j=i+1; j<goodSuffixes.size(); ++j) {
				string bstr = goodSuffixes[j].substr(goodSuffixes[j].size()-str.size(),str.size());
				if (str == bstr) {
					used[j] = true;
				}
			}
		}
		double ans = 0;
		for (int i=0; i<uni.size(); ++i) {
			double comb = 1;
			for (int n=0; n<uni[i].size(); ++n) {
				comb /= 10.0;
			}
			ans += comb;
		}
		return ans;
	}
};
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

class Filtering {
public:
	static
	bool
	comp(const pair<int, string> &lhs , const pair<int , string> &rhs)
	{
		return lhs.first < rhs.first;
	}

  vector <int>
	designFilter(vector <int> sizes, string outcome)
	{
		vector<pair<int, string> > p(outcome.size());
		for (int i=0; i<p.size(); ++i) {
			p[i] = make_pair(sizes[i], outcome[i]);
		}
		sort(p.begin(), p.end(), comp);
		int l=-1,r=p[p.size()-1].first;
		for (int i=0; i<p.size(); ++i) {
			if (p[i].second == "A" && l==-1) {
				l = p[i].first;
			}
			else if (p[i].second == "R" && l!=-1 && r==p[p.size()-1].first) {
				r = p[i-1].first;
			}
			else if (p[i].second == "A" && l!=-1 && r!=p[p.size()-1].first) {
				return vector<int>();
			}
		}
		vector<int> ans = {l,r};
		return ans;
	}
};
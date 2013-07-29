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

class PermutationSignature {
public:
	int
	getmin(vector<bool> &s,int pop)
	{
		int cnt = 0;
		for (int i=0; i<s.size(); ++i) {
			if (!s[i]) {
				if (cnt == pop) {
					return i+1;
				}
				++cnt;
			}
		}
		return -1;
	}

	vector <int>
	reconstruct(string signature)
	{
		int n = (int)signature.size()+1;
		vector<bool> s(n);
		vector<int> ans;
		for (int i=0; i<n-1; ++i) {
			int p = getmin(s,0);
			if (signature[i]=='D') {
				int pop = 1;
				for (int j=i+1; j<n-1; ++j) {
					if (signature[j]=='D') ++pop;
					else break;
				}
				p = getmin(s, pop);
				if (p==-1) return vector<int>();
			}
			ans.push_back(p);
			s[p-1]=true;
		}
		ans.push_back(getmin(s, 0));
		return ans;
	}
};
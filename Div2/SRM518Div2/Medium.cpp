#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <bitset>
#include <queue>
#include <algorithm>
#include <functional>
#include <cmath>
#include <cstdio>
#include <sstream>
#include <stack>
#include <istream>

using namespace std;

class LargestSubsequence {
public:
	string getLargest(string s)
	{
		string ans = "";
		int pos = 0;
		while (true) {
			int mxPos = pos;
			char mx = s[mxPos];
			for (int i=mxPos+1; i<s.size(); ++i) {
				if (mx < s[i]) {
					mxPos = i;
					mx = s[mxPos];
				}
			}
			pos = mxPos+1;
			ans += mx;
			if (pos == s.size()) {
				break;
			}
		}
		return ans;
	}
};
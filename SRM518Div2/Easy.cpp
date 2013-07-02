#include <iostream>
#include <vector>
#include <map>
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

class TwiceString {
public:
  string getShortest(string s)
	{
		string ans = s+s;
		for (int i=1; i<s.size(); ++i) {
			string left = s.substr(0,i);
			string right = s.substr(s.size()-i,i);
			if (left == right) {
				string rest = s.substr(i,s.size()-i);
				ans = s+rest;
			}
		}
		return ans;
	}
};
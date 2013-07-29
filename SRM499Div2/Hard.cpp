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

class PalindromeGame {
public:
	bool
	isPalindrome(string s)
	{
		for (int b=0,e=(int)s.size()-1; b <= e; ++b,--e) {
			if (s[b] != s[e]) {
				return false;
			}
		}
		return true;
	}

	struct state {
		string front;
		int back;
	};

	static bool
	comp(const state &lhs,const state &rhs)
	{
		return lhs.back > rhs.back;
	}

	int
	getMaximum(vector <string> front, vector <int> back)
	{
		bool used[51] = {false};
		vector<state> cs(front.size());
		for (int i=0; i<front.size(); ++i) {
			state s;
			s.front = front[i];
			s.back = back[i];
			cs[i] = s;
		}
		sort(cs.begin(), cs.end(), comp);

		int ans = 0;
		for (int i=0; i<cs.size(); ++i) {
			for (int j=i+1; j<cs.size(); ++j) {
				if (isPalindrome(cs[i].front+cs[j].front) && !used[i] && !used[j]) {
					used[i] = true;
					used[j] = true;
					ans += cs[i].back + cs[j].back;
				}
			}
		}

		for (int i=0; i<cs.size(); ++i) {
			if (!used[i] && isPalindrome(cs[i].front)) {
				ans += cs[i].back;
				break;
			}
		}

		return ans;
	}
};
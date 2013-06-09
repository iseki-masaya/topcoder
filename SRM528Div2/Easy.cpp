#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <bitset>
#include <queue>
#include <algorithm>
#include <functional>
#include <cstdio>

using namespace std;

class MinCostPalindrome {
public:
  int getMinimum(string s, int oCost, int xCost)
	{
		size_t left=0,right=s.size()-1;
		int ans = 0;
		while (left < right) {
			if (s[left] == s[right] && s[left] == '?' && s[right] == '?') {
				if (oCost>xCost)
					ans += xCost*2;
				else
					ans += oCost*2;
			}
			else {
				if (s[left] != s[right] && s[left] != '?' && s[right] != '?') {
					return -1;
				}
				else if (s[left] != s[right] && s[left] == '?') {
					if (s[right] == 'o')
						ans += oCost;
					else
						ans += xCost;
				}
				else if (s[left] != s[right] && s[right] == '?') {
					if (s[left] == 'o')
						ans += oCost;
					else
						ans += xCost;
				}
			}
			++left;
			--right;
		}

		return ans;
	}
};
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

#define INF (1<<20)
#define PI 3.14159265

string alpha = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};

class StrIIRec {
public:
	int
	calc_inv(string str)
	{
		int ans = 0;
		for (int i=0; i<str.size(); ++i) {
			for (int j=i; j<str.size(); ++j) {
				if (str[i] > str[j]) {
					++ans;
				}
			}
		}
		return ans;
	}

	string
	next(string s)
	{
		for (int left = (int)s.size()-2; left >= 0; --left) {
			for (int right = (int)s.size()-1; right > left; --right) {
				if (s[left] < s[right]) {
					swap(s[left], s[right]);
					return s;
				}
			}
		}
		return s;
	}

	string
	recovstr(int n, int minInv, string minStr)
	{
		int pos = 0;
		while (minStr.size() < n) {
			if (minStr.find(alpha[pos]) == string::npos) {
				minStr.push_back(alpha[pos]);
			}
			++pos;
		}

		while (calc_inv(minStr) < minInv) {
			minStr = next(minStr);
		}

		return minStr;
	}
};
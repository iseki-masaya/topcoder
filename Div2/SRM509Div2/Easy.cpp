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

using namespace std;

class PalindromizationDiv2 {
public:
	bool isPalindrome(int n)
	{
		stringstream ss;
		string str;
		ss << n;
		ss >> str;
		for (size_t i=0,j=str.size()-1; i<str.size(); ++i,--j) {
			if (str[i]!=str[j]) {
				return false;
			}
		}
		return true;
	}

  int getMinimumCost(int X)
	{
		for (int i=0; i<100000; ++i) {
			if (isPalindrome(X-i) || isPalindrome(X+i)) {
				return i;
			}
		}
		return -1;
	}
};
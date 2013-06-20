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

using namespace std;

class SwappingDigits {
public:
  string minNumber(string num)
	{
		string ans = num;
		for (int i=1; i<num.size(); ++i) {
			for (int j=0; j<i; ++j) {
				string str = num;
				swap(str[i],str[j]);
				if (str[0]!='0' && str < ans) {
					ans = str;
				}
			}
		}
		return ans;
	}
};
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

using namespace std;

#define MAX_N 10000000

string str[] =
{"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

class WhichDay {
public:
  string getDay(vector <string> notOnThisDay)
	{
		string ans = "";
		for (int i=0; i<7; ++i) {
			ans = str[i];
			for (int j=0; j<notOnThisDay.size(); ++j) {
				if (ans == notOnThisDay[j]) {
					break;
				}
				if (j == notOnThisDay.size()-1) {
					return ans;
				}
			}
		}
		return ans;
	}
};

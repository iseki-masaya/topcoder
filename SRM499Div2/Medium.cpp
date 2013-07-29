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

class ColorfulRabbits {
public:
	int
	getMinimum(vector <int> replies)
	{
		map<int , int> cnt;
		for (int i=0; i<replies.size(); ++i) {
			cnt[replies[i]]++;
		}
		int ans = 0;
		for (map<int, int>::iterator s=cnt.begin(),e=cnt.end(); s!=e; ++s) {
			int num = ( (*s).second-1 ) / ( (*s).first+1 ) + 1;
			ans += num * ((*s).first+1);
		}
		return ans;
	}
};
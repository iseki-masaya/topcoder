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
#define MOD 1000000007

using namespace std;

class CubeStickers {
public:
	string
	isPossible(vector <string> sticker)
	{
		map<string, int> count;
		for (int i=0; i<sticker.size(); ++i) {
			count[sticker[i]]++;
		}
		int dup_cnt = 0;
		for (map<string,int>::iterator it=count.begin(),end=count.end(); it!=end ; ++it) {
			if ((*it).second>=2) {
				++dup_cnt;
			}
		}
		if (dup_cnt>=3 || (dup_cnt>=2&&count.size()>=4) || count.size()>=5 ) {
			return "YES";
		}
		return "NO";
	}
};
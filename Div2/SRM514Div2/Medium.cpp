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

#define INF (1<<20)
#define MAX 101

using namespace std;

class MagicalGirlLevelTwoDivTwo {
public:
	string isReachable(vector <int> jumpTypes, int x, int y)
	{
		if (x==0 && y==0) {
			return "YES";
		}
		for (int i=0; i<jumpTypes.size(); ++i) {
			if ((jumpTypes[i]&1) == 0) {
				return "YES";
			}
			else if(jumpTypes[i] == 1) {
				if (x==y) {
					return "YES";
				}
			}
		}

		if (((x&1)==1 && (y&1)==0) || ((x&1)==0 && (y&1)==1) ) {
			return "NO";
		}
		return "YES";
	}
};
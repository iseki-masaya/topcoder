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

class DivideAndShift {
public:
	int
	getLeast(int N, int M)
	{
		--M;
		int res = N;
		for (int y=1; y<=N; ++y) {
			if (N%y==0) {
				int x = N/y;
				int c = 0;
				for (int p=2; p <= x/p; ++p) {
					while (x%p==0) {
						++c;
						x /= p;
					}
				}
				c += (x!=1)?1:0;
				int s = min(M%y,y-M%y);
				res = min(res,s+c);
			}
		}
		return res;
	}
};
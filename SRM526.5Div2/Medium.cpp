#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <bitset>
#include <queue>
#include <algorithm>
#include <functional>
#include <cmath>

using namespace std;

class MagicCandy {
public:
	long long f(long long x)
	{
		long long t = static_cast<long long>(sqrt(x));
		return x - t;
	}

	long long f_inv(long long x)
	{
		long long L = x;
		long long R = 2*x+100; //((x+1)^2-x^2 )< L
		while (R-L>1) {
			long long M =(R+L)/2;
			if (f(M) < x) {
				L = M;
			}
			else {
				R = M;
			}
		}

		return R;
	}

	int getCnt(int x)
	{
		int ret = 0;
		while (x>1) {
			x = x - static_cast<int>(sqrt(x));
			++ret;
		}

		return ret;
	}

  int whichOne(int n)
	{
		int cnt = getCnt(n);
		long long ret = 1;
		for (int i=0; i<cnt; ++i) {
			ret = f_inv(ret);
		}
		return static_cast<int>(ret);
	}
};
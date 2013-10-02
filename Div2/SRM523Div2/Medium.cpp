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

#define INF 1000000000

class CountingSeries {
public:
	long long countYnX(long long a,long long b,long long c,long long d,long long u)
	{
		long long r = 0;
		long long y = c;
		while (y <= u) {
			bool add = true;

			if (y >= a) {
				if ((y-a)%b==0) {
					add = false;
				}
			}

			r += add ? 1 : 0;

			y *= d;
			if (d == 1) {
				break;
			}
		}

		return r;
	}

	long long countX(long long a,long long b,long long u)
	{
		if (a <= u) {
			return 1 + (u-a)/b;
		}
		return 0;
	}

	long long countThem(long long a, long long b, long long c, long long d, long long upperBound)
	{
		long long x = countX(a, b, upperBound);
		long long y = countYnX(a, b, c, d, upperBound);

		return x+y;
	}
};
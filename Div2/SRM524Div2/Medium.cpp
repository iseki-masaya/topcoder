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

using namespace std;

class MagicDiamonds {
	bool isPrime(long long x)
	{
		if (x == 1) {
			return false;
		}
		if (x == 2) {
			return true;
		}
		if (x%2 == 0) {
			return false;
		}

		for (long long i=3; i*i<=x; ++i) {
			if (x%i==0) {
				return false;
			}
		}

		return true;
	}
public:
	long long minimalTransfer(long long n)
	{
		if (n == 3) {
			return 3;
		}
		if (isPrime(n)) {
			return 2;
		}
		else {
			return 1;
		}
	}
};
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

class ShippingCubes {
public:
	int minimalCost(int N)
	{
		int ans = 1000;
		for (int a=1; a<200; ++a) {
			for (int b=1; b<200; ++b) {
				for (int c=1; c<200; ++c) {
					if (N == a*b*c) {
						ans = min(ans,a+b+c);
					}
				}
			}
		}

		return ans;
	}
};

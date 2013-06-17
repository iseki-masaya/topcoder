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

class SemiPerfectSquare {
public:
	string check(int N)
	{
		for (int b=1; b<34; ++b) {
			for (int a=0; a<b; ++a) {
				if ((a*b*b)==N) {
					return "Yes";
				}
			}
		}
		return "No";
	}
};
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

#define MAX_NA 53
#define MAX_NB 53

class FoxPlayingGame {
public:
	double
	theMax(int nA, int nB, int paramA, int paramB)
	{
		double mx[MAX_NB][MAX_NA],mn[MAX_NB][MAX_NA];
		memset(mx, 0, MAX_NA*MAX_NB);
		memset(mn, 0, MAX_NA*MAX_NB);

		double sa = paramA/1000.0;
		double sb = paramB/1000.0;
		for (int a=1; a<=nA; ++a) {
			mx[0][a] = mx[0][a-1] + sa;
			mn[0][a] = mn[0][a-1] + sa;
		}
		for (int a=1; a<=nA; ++a) {
			for (int b=1; b<=nB; ++b) {
				mx[b][a] = max(max(mx[b-1][a]*sb,mx[b][a-1]+sa),max(mn[b-1][a]*sb, mn[b][a-1]+sa));
				mn[b][a] = min(min(mx[b-1][a]*sb,mx[b][a-1]+sa),min(mn[b-1][a]*sb, mn[b][a-1]+sa));
			}
		}

		return mx[nB][nA];
	}
};
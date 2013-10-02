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

#define MAX 50000 // 5133
#define SIZE 10000
#define INF (1<<30)

using namespace std;

class MathContest {
public:
	int
	countBlack(string ballSequence, int repetitions)
	{
		int bn=0,wn=0;
		int left=0,right=(int)ballSequence.size()*repetitions-1;
		for (int i=0; i<ballSequence.size()*repetitions; ++i) {
			int p;
			if (wn&1) {
				p = right%ballSequence.size();
				--right;
			} else {
				p = left%ballSequence.size();
				++left;
			}
			if ((ballSequence[p] == 'B' && (bn&1)==0) || (ballSequence[p] == 'W' && (bn&1)==1)) {
				++bn;
			} else {
				++wn;
			}
		}
		return bn;
	}
};
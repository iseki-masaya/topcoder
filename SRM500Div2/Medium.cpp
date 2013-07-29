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

class
MafiaGame {
public:
	double
	probabilityToLose(int N, vector <int> decisions)
	{
		sort(decisions.begin(), decisions.end());
		int mxCnt = 0;
		int cnt = 0;
		int mxCntPlayer = 1;
		for (int i=0; i<decisions.size(); ++i) {
			if (i == 0 || decisions[i]==decisions[i-1]) {
				++cnt;
			}
			else {
				cnt = 1;
			}

			if (cnt > mxCnt) {
				mxCnt = cnt;
				mxCntPlayer = 1;
			}
			else if (cnt == mxCnt) {
				++mxCntPlayer;
			}
		}

		int c = mxCntPlayer;
		if (c == decisions.size()) {
			return 0;
		}
		while (true) {
			if (c == 0) {
				return 0;
			}
			else if (c == 1) {
				return (1.0/mxCntPlayer);
			}
			c = N%c;
		}
	}
};
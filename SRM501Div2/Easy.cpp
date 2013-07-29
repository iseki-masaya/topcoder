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

#define INF (1<<30)

class FoxProgression {
public:
  int theCount(vector <int> seq)
	{
		if (seq.size() <= 1) {
			return -1;
		}

		int r = seq[0]==0?INF:(seq[1]/seq[0]);
		int rb = seq[0] * r;
		int s = seq[1] - seq[0];
		int sb = seq[0] + s;
		for (int i=1; i<seq.size(); ++i) {
			if (seq[i]%seq[i-1] != 0 || rb != seq[i]) {
				rb = INF;
			}
			if (sb != seq[i]) {
				sb = INF;
			}
			rb = rb!=INF?seq[i] * r:INF;
			sb = sb!=INF?seq[i] + s:INF;
		}

		if (rb != INF && sb != INF && rb != sb) {
			return 2;
		}
		else if (rb != INF || sb != INF) {
			return 1;
		}
		else {
			return 0;
		}
	}
};
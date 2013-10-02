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
#include <stack>

using namespace std;

#define INF (1<<26)

class SRMRoomAssignmentPhase {
public:
	int countCompetitors(vector <int> ratings, int K)
	{
		int yourR = ratings[0];
		sort(ratings.begin(), ratings.end(),greater<int>());
		int pos = -1;
		for (int i=0; i<ratings.size(); ++i) {
			if (ratings[i] == yourR) {
				pos = i;
				break;
			}
		}
		return pos/K;
	}
};
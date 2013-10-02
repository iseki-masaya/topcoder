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
SRMCards {
public:
  int
	maxTurns(vector <int> cards)
	{
		sort(cards.begin(), cards.end());
		int prev = -100;
		int ans = 0;
		for (int i=0; i<cards.size(); ++i) {
			if (cards[i]!=prev+1) {
				++ans;
				prev = cards[i];
			}
		}
		return ans;
	}
};
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

class AnagramFree {
public:
  int
	getMaximumSubset(vector <string> S)
	{
		set<string> w;
		for (int i=0; i<S.size(); ++i) {
			sort(S[i].begin(), S[i].end());
			w.insert(S[i]);
		}
		return (int)w.size();
	}
};
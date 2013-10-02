#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <bitset>
#include <queue>
#include <algorithm>
#include <functional>
#include <cstdio>

using namespace std;

class Cut {
public:
	int getMaximum(vector <int> eelLengths, int maxCuts)
	{
		sort(eelLengths.begin(), eelLengths.end());
		int ans = 0;
		for (int i=0; i<eelLengths.size(); ++i) {
			if (eelLengths[i] == 10) {
				++ans;
				eelLengths[i] = 0;
			}
		}

		//Divided by 10
		int work;
		for (int i=0; i<eelLengths.size(); ++i) {
			if (eelLengths[i]%10 == 0 && eelLengths[i] >= 10) {
				work = (eelLengths[i]/10)-1;
				if (work <= maxCuts) {
					eelLengths[i] = 0;
					maxCuts -= work;
					ans += work+1;
				}
			}
		}

		//Other
		for (int i=0; i<eelLengths.size(); ++i) {
			if (eelLengths[i] > 10) {
				work = eelLengths[i]/10;
				if (work <= maxCuts) {
					eelLengths[i] = 0;
					maxCuts -= work;
					ans += work;
				}
				else {
					ans += maxCuts;
					maxCuts = 0;
					return ans;
				}
			}
		}

		return ans;
	}
};
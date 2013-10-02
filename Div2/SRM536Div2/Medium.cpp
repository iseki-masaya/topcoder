#include <vector>
#include <iostream>
#include <memory>

using namespace std;

class RollingDiceDivTwo {
public:
	int minimumFaces(vector <string> rolls)
	{
		vector<vector<int> > roll(rolls.size());
		vector<int> tmp(rolls.at(0).size());
		for (int i=0; i<rolls.size(); ++i) {
			for (int j=0; j<rolls.at(i).size(); ++j) {
				tmp[j] = rolls.at(i).at(j)-'0';
			}
			sort(tmp.begin(), tmp.end());
			roll[i] = tmp;
		}

		int mx = 0, ans = 0;
		for (int i=0; i<roll.at(0).size(); ++i) {
			mx = 0;
			for (int j=0; j<roll.size(); ++j) {
				mx = max(mx,roll.at(j).at(i));
			}
			ans += mx;
		}

		return ans;
	}
};
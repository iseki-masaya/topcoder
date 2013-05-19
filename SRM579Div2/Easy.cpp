#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>

using namespace std;

class PrimalUnlicensedCreatures
{
public:
	int maxWins(int initialLevel, vector <int> grezPower)
	{
		sort(grezPower.begin(), grezPower.end());
		int cnt = 0;
		int lv = initialLevel;
		for (int i=0; i<grezPower.size(); ++i) {
			if (lv > grezPower.at(i)) {
				++cnt;
				lv += grezPower.at(i)/2;
			}
			else {
				break;
			}
		}

		return cnt;
	}
};
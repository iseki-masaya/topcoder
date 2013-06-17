#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <bitset>
#include <queue>
#include <algorithm>
#include <functional>
#include <cmath>

using namespace std;

class SpaceWarDiv2 {
	struct Enemy {
		int strength,count;
	};
	static
	bool compS(const Enemy &lhs,const Enemy &rhs)
	{
		return lhs.strength > rhs.strength;
	}
public:
	int minimalFatigue(vector <int> magicalGirlStrength, vector <int> enemyStrength, vector <int> enemyCount)
	{
		vector<Enemy> e(enemyStrength.size());
		for (int i=0; i<enemyStrength.size(); ++i) {
			e[i].strength = enemyStrength[i];
			e[i].count = enemyCount[i];
		}

		sort(e.begin(), e.end(), compS);
		sort(magicalGirlStrength.begin(), magicalGirlStrength.end(),greater<int>());

		if (magicalGirlStrength[0] < e[0].strength) {
			return -1;
		}

		int ans = 0;
		bool stillFight = true;
		while (stillFight) {
			++ans;
			for (int i=0; i<magicalGirlStrength.size(); ++i) {
				int pos=0;
				for (int j=0; j<e.size(); ++j) {
					if (magicalGirlStrength[i]>=e[j].strength && e[j].count>0) {
						pos = j;
						--e[pos].count;
						break;
					}
				}
			}

			stillFight = false;
			for (int i=0; i<e.size(); ++i) {
				if (e[i].count>0) {
					stillFight = true;
					break;
				}
			}
		}

		return ans;
	}
};
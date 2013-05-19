#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

class KiwiJuiceEasy
{
public:
	vector <int> thePouring(vector <int> capacities, vector <int> bottles, vector <int> fromId, vector <int> toId)
	{
		for (int i=0; i<fromId.size(); ++i) {
			int src = fromId.at(i);
			int dst = toId.at(i);
			if (bottles.at(src)+bottles.at(dst) <= capacities.at(dst)) {
				bottles[dst] += bottles.at(src);
				bottles[src] = 0;
			}
			else {
				bottles[src] = bottles.at(src) - (capacities.at(dst) - bottles.at(dst));
				bottles[dst] = capacities.at(dst);
			}
		}
		return bottles;
	}
};
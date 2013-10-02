#include <vector>

using namespace std;

class SkiResortsEasy
{
public:
	int minCost(vector<int> altitude)
	{
		int cost=0;
		int previos = altitude.at(0);
		for (vector<int>::iterator it = altitude.begin(); it != altitude.end(); ++it) {
			if (*it > previos) {
				cost += *it - previos;
				*it = previos;
			}
			previos = *it;
		}
		return cost;
	}
};
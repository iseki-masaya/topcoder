#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

class KingdomAndDucks
{
public:
	int minDucks(vector <int> duckTypes)
	{
		map<int, int> duck;
		for (vector<int>::const_iterator it = duckTypes.begin(), end = duckTypes.end(); it != end; ++it) {
			duck[*it]++;
		}

		int max = 0;
		for (map<int, int>::const_iterator it = duck.begin(),end = duck.end(); it != end; ++it) {
			if (max < (*it).second) {
				max = (*it).second;
			}
		}

		return max*static_cast<int>(duck.size());
	}
};
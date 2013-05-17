#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

class ContestWinner
{
public:
	int getWinner(vector <int> events)
	{
		map<int,int> point;
		int max = 0;
		int winner = -1;
		for (vector<int>::const_iterator it = events.begin(),end = events.end(); it != end; ++it) {
			point[*it]++;
			if (point[*it]>max) {
				max = point[*it];
				winner = *it;
			}
		}
		return winner;
	}
};
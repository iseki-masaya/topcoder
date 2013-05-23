#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <errno.h>
#include <sstream>

using namespace std;

class EllysRoomAssignmentsDiv2
{
public:
	double getProbability(vector <string> ratings)
	{
		string str;
		for (int i=0; i<ratings.size(); ++i) {
			str += ratings.at(i);
		}

		vector<int> concat;
		stringstream ss(str);
		int rate;
		while(ss >> rate) {
			concat.push_back(rate);
		}

		int Elly = concat.at(0);
		sort(concat.begin(), concat.end(),greater<int>());
		concat.erase(unique(concat.begin(), concat.end()),concat.end());

		if (Elly == concat.at(0))
			return 1.0;

		int S = static_cast<int>(concat.size());
		int R = S/20 + (S%20==0 ? 0 : 1);

		if (R > 1 && Elly > concat.at(R))
			return 0;

		return 1.0/R;
	}
};
#include <string>
#include <vector>
#include <set>
#include <iostream>
#include <bitset>

using namespace std;

class Over9000Rocks
{
private:
	struct S {
		int upper;
		int lower;
	};

	struct comp {
		bool operator()(const S& lhs,const S& rhs) const
		{
			return lhs.lower < rhs.lower;
		}
	};
public:
	int countPossibilities(vector <int> lowerBound, vector <int> upperBound)
	{
		vector<S> list;
		// bit calculation
		for (int comb = 1; comb < 1<<lowerBound.size() ; ++comb) {
			S s;
			s.upper = 0;
			s.lower = 0;
			for (int i=0; i<lowerBound.size(); ++i) {
				if (((comb>>i)&1) == 1) {
					s.upper += upperBound.at(i);
					s.lower += lowerBound.at(i);
				}
			}

			if (s.upper > 9000) {
				if (s.lower > 9000) {
					list.push_back(s);
				}
				else {
					s.lower = 9001;
					list.push_back(s);
				}
			}
		}
		comp c;
		sort(list.begin(), list.end(), c);
		int cnt = 0,now = 0;
		for (int i=0; i<list.size(); ++i) {
			if (list.at(i).upper > now) {
				if (list.at(i).lower > now) {
					cnt += list.at(i).upper - list.at(i).lower + 1;
					now = list.at(i).upper;
				}
				else {
					cnt += list.at(i).upper - now;
					now = list.at(i).upper;
				}
			}
		}
		return cnt;
	}
};
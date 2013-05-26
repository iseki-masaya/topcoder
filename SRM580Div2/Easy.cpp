#include <vector>
#include <iostream>
#include <memory>

using namespace std;

class ShoutterDiv2 {
public:
	struct state {
		int start;
		int end;
	};
	struct comp {
		bool operator()(const state &lhs,const state &rhs)
		{
			return lhs.start < rhs.start;
		}
	};

	int count(vector <int> s, vector <int> t)
	{
		vector<state> info(s.size());
		state tmp;
		for (int i=0; i<s.size(); ++i) {
			tmp.start = s.at(i);
			tmp.end = t.at(i);
			info.at(i) = tmp;
		}

		comp c;
		sort(info.begin(), info.end(), c);

		int cnt = 0;
		for (int i=0; i<s.size(); ++i)
			for (int j=i+1; j<s.size(); ++j)
				if (info.at(i).end >= info.at(j).start)
					++cnt;

		return cnt;
	}
};
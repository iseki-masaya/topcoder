#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <bitset>
#include <queue>
#include <algorithm>
#include <functional>
#include <cstdio>

using namespace std;

class KingSort {
	struct Rome {
		string rank;
		int num;
	};

	struct comp {
		bool operator()(const Rome &lhs,const Rome &rhs)
		{
			return lhs.num < rhs.num;
		}
	};

	int convertNum(string str)
	{
		bool isOne = false;
		bool isTen = false;

		int ans = 0;
		for (int i=0; i<str.size(); ++i) {
			if (str.at(i) == 'I') {
				isOne = true;
				ans += 1;
			}
			else if (str.at(i) == 'V') {
				if (isOne)
					ans += 5 - 2;
				else
					ans += 5;
			}
			else if (str.at(i) == 'X') {
				isTen = true;
				if (isOne)
					ans += 10 - 2;
				else
					ans += 10;
			}
			else if (str.at(i) == 'L') {
				if (isTen)
					ans += 50 - 20;
				else
					ans += 50;
			}
		}

		return ans;
	}
public:
	vector <string> getSortedList(vector <string> kings)
	{
		sort(kings.begin(), kings.end());
		kings.push_back("for gurd");
		string name = "";

		vector<Rome> rank;
		vector<string> ans;
		Rome rWork;
		comp c;
		string sWork;
		for (int i=0; i<kings.size(); ++i) {
			size_t pos = kings.at(i).find(" ");
			if (name != kings.at(i).substr(0,pos+1)) {
				sort(rank.begin(), rank.end(), c);
				for (int j=0; j<rank.size(); ++j) {
					sWork = name + rank.at(j).rank;
					ans.push_back(sWork);
				}
				rank.clear();
				name = kings.at(i).substr(0,pos+1);
			}
			rWork.rank = kings.at(i).substr(pos+1,kings.at(i).size());
			rWork.num = convertNum(rWork.rank);
			rank.push_back(rWork);
		}

		return ans;
	}
};
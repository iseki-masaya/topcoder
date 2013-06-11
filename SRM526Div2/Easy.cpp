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

class CheatingQuiz {
public:
	vector <int> howMany(string answers)
	{
		vector<int> ans(answers.size());
		vector<char> stock;
		int upper = static_cast<int>(answers.size()-1);

		for (int i=upper; i>=0; --i) {
			if (find(stock.begin(), stock.end(), answers[i]) == stock.end()) {
				stock.push_back(answers[i]);
			}
			ans[i] = static_cast<int>(stock.size());
		}

		return ans;
	}
};
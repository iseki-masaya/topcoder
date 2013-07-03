#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <list>
#include <algorithm>
#include <sstream>
#include <set>
#include <cmath>
#include <map>
#include <stack>
#include <queue>

#define I_INF (1<<20)
#define F_INF 1e7
#define MAX 101

using namespace std;

class Zoo {
public:
	long long theCount(vector <int> answers)
	{
		sort(answers.begin(), answers.end());
		queue<int> r,c;
		for (int i=0; i<answers.size(); ++i) {
			r.push(i);
			c.push(i);
		}

		for (int i=0; i<answers.size(); ++i) {
			if (answers[i] == r.front()) {
				r.pop();
			}
			else if (answers[i] == c.front()) {
				c.pop();
			}
			else {
				return 0;
			}
		}

		int pow = answers.size()-c.size() + (c.size()==r.size()?0:1);


		return 1<<pow;
	}
};
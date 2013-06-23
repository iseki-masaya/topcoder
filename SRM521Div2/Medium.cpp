#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <bitset>
#include <queue>
#include <algorithm>
#include <functional>
#include <cmath>
#include <cstdio>
#include <sstream>
#include <stack>

using namespace std;

#define INF (1<<26)

class MissingParentheses {
public:
	int countCorrections(string par)
	{
		stack<char> buff;
		buff.push(par[0]);
		for (int i=1; i<par.size(); ++i) {
			if (!buff.empty() && buff.top() == '(' && par[i] == ')') {
				buff.pop();
			}
			else {
				buff.push(par[i]);
			}
		}
		return static_cast<int>(buff.size());
	}
};
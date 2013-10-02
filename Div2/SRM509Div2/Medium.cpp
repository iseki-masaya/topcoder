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

#define MAX_V (10000001)
#define MAX_N (100001)

using namespace std;

class LuckyRemainder {
public:
	int getLuckyRemainder(string X)
	{
		unsigned long long ans = 0;
		for (int i=0; i<X.size(); ++i) {
			ans += static_cast<unsigned long long>((X[i]-'0'))<<X.size()-1;
			ans = ans%9;
		}
		return static_cast<int>(ans);
	}
};
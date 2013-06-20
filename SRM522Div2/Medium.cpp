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

using namespace std;

class RowAndManyCoins {
public:
	string getWinner(string cells)
	{
		if (cells[0]=='A' || cells[cells.size()-1]=='A') {
			return "Alice";
		}
		return "Bob";
	}
};
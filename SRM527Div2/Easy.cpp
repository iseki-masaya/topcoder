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

class P8XMatrixTransformation {
public:
  string solve(vector <string> original, vector <string> target)
	{
		int oriNum=0,tarNum=0;
		for (int y=0; y<original.size(); ++y) {
			for (int x=0; x<original.at(0).size(); ++x) {
				if (original.at(y).at(x) == '0') {
					++oriNum;
				}
				if (target.at(y).at(x) == '0') {
					++tarNum;
				}
			}
		}

		if (tarNum==oriNum) {
			return "YES";
		}
		else {
			return "NO";
		}
	}
};
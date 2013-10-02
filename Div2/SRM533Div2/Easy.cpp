#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

class PikachuEasy {
public:
  string check(string word)
	{
		string p[3] = {"pi","ka","chu"};
		bool isDivide = false;
		while (!word.empty()) {
			isDivide = true;
			for (int i=0; i<3; ++i) {
				if (word.find(p[i]) == 0) {
					isDivide = false;
					word = word.substr(p[i].size(),word.size());
					break;
				}
			}
			if (isDivide) {
				return "NO";
			}
		}

		return "YES";
	}
};
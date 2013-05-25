#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

char vowel[5] = {'a','i','u','e','o'};

class KingXNewBaby {
public:
  string isValid(string name)
	{
		if (name.size() != 8) {
			return "NO";
		}

		map<char,int> cnt;
		for (int i=0; i<name.size(); ++i) {
			++cnt[name[i]];
		}

		bool isValid = false;

		for (int i=0; i<5; ++i) {
			if (cnt[vowel[i]] == 2 && !isValid) {
				isValid = true;
			}
			else if(cnt[vowel[i]] != 0 ) {
				isValid = false;
				break;
			}
		}
		if (isValid) {
			return "YES";
		}
		else {
			return "NO";
		}
	}
};
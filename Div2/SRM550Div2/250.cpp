#include <iostream>
#include <string>

using namespace std;

class EasyConversionMachine
{
public:
	string isItPossible(string originalWord, string finalWord, int k)
	{
		int diff = 0;
		for (int i=0; i<originalWord.size(); ++i) {
			if (originalWord.at(i) != finalWord.at(i)) {
				++diff;
			}
		}

		if (k-diff<0) {
			return "IMPOSSIBLE";
		}

		if ((k-diff) % 2 == 0) {
			return "POSSIBLE";
		}

		return "IMPOSSIBLE";
	}
};
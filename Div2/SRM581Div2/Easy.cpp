#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;

class BlackAndWhiteSolitaire {
public:
	int minimumTurns(string cardFront)
	{
		int bcnt = 0;
		char f = 'B';
		for (int i=1; i<cardFront.size(); i+=2) {
			if (f == cardFront.at(i)) {
				++bcnt;
			}
		}
		for (int i=0; i<cardFront.size(); i+=2) {
			if (f != cardFront.at(i)) {
				++bcnt;
			}
		}

		int wcnt = 0;
		f = 'W';
		for (int i=1; i<cardFront.size(); i+=2) {
			if (f == cardFront.at(i)) {
				++wcnt;
			}
		}
		for (int i=0; i<cardFront.size(); i+=2) {
			if (f != cardFront.at(i)) {
				++wcnt;
			}
		}

		int cnt = min(wcnt,bcnt);

		return cnt;
	}
};
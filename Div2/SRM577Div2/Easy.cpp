#include <iostream>
#include <map>
#include <string>

using namespace std;

class EllysNewNickname
{
public:
	int getLength(string nickname)
	{
		int cnt = 0;
		char w;
		bool isConsecutive = false;
		for (int i=0; i<nickname.size(); ++i) {
			w = nickname.at(i);
			if (w == 'a' || w == 'i' || w== 'u' || w== 'e' || w=='o' || w=='y') {
				if (isConsecutive)
					continue;
				isConsecutive = true;
			}
			else {
				isConsecutive = false;
			}
			++cnt;
		}

		return cnt;
	}
};
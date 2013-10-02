#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

class ColorfulBricks
{
public:
	int countLayouts(string bricks)
	{
		map<char, int> eachCnt;
		for (int i=0; i<bricks.size(); ++i) {
			eachCnt[bricks[i]] = 0;
		}
		for (int i=0; i<bricks.size(); ++i) {
			++eachCnt[bricks[i]];
		}
		
		if (eachCnt.size()>2) {
			return 0;
		}
		else if (eachCnt.size() == 1) {
			return 1;
		}
		else {
			return 2;
		}
	}
};
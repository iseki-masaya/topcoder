#include <iostream>
#include <cmath>

using namespace std;

class TheBrickTowerEasyDivTwo
{
public:
	int find(int redCount, int redHeight, int blueCount, int blueHeight)
	{
		int cnt = min(redCount, blueCount);
		
		if (redHeight == blueHeight) {
			cnt = 2 * cnt;
		}
		else {
			cnt = 2 * cnt + cnt;
		}
		
		if (redCount != blueCount) {
			++cnt;
		}
		
		return cnt;
	}
};
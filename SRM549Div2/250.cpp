#include <iostream>
#include <string>

using namespace std;

class BallAndHats
{
public:
	int getHat(string hats, int numSwaps)
	{
		int startPoint = static_cast<int>(hats.find('o'));
		if (numSwaps == 0) {
			return startPoint;
		}

		if ((numSwaps%2!=0 && startPoint%2!=0) ||(numSwaps%2==0 && startPoint%2==0)  ) {
			return 0;
		}
		return 1;
	}
};
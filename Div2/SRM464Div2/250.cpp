#include <iostream>
#include <vector>
#include <string>

class ColorfulBoxesAndBalls
{
public:
	int getMaximum(int numRed, int numBlue, int onlyRed, int onlyBlue, int bothColors)
	{
		int max;
		
		int sub = (bothColors - onlyRed) + (bothColors - onlyBlue);
		if (sub > 0) {
			if (numRed > numBlue) {
				numRed -= numBlue;
				max = numRed * onlyRed + bothColors * numBlue * 2;
			}
			else {
				numBlue -= numRed;
				max = numBlue * onlyBlue + bothColors * numRed * 2;
			}
		}
		else {
			max = numRed * onlyRed + numBlue * onlyBlue;
		}
		
		return max;
	}
};
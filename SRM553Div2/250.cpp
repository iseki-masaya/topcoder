#include <iostream>

using namespace std;

class PlatypusDuckAndBeaver
{
public:
	int minimumAnimals(int webbedFeet, int duckBills, int beaverTails)
	{
		int maxWebbedFeet = duckBills*2 + beaverTails*4;
		int platypusCnt = (maxWebbedFeet - webbedFeet)/2;
		return (duckBills+beaverTails)-platypusCnt;
	}
};
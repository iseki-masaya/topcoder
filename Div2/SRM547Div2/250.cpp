#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <map>

using namespace std;

class MinimalTriangle
{
public:
	double maximalArea(int length)
	{
		double rootThree = sqrt(3.0);
		double ans = length*rootThree/4.0;
		return ans * length;
	}
};
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class WorkingRabbits
{
public:
	int calcProfitSum(vector <string> profit)
	{
		int size = static_cast<int>(profit.size());
		int sum=0;
		int i,j;
		for (i=0; i<size; ++i) {
			for (j=i+1; j<size; ++j) {
				sum += static_cast<int>(profit[i][j] - '0');
			}
		}
		return sum;
	}
	int calcPair(int x)
	{
		return x*(x-1)/2;
	}

	double getEfficiency(vector <string> profit)
	{

		double profitSum = static_cast<double>(calcProfitSum(profit));
		double pair = static_cast<double>(calcPair(static_cast<int>(profit.size())));
		double efficiency = profitSum/pair;
		return efficiency;
	}
};
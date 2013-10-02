#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

class ElectionFraudDiv2
{
public:
	string IsFraudulent(vector <int> percentages)
	{
		double minSize=0;
		for (vector<int>::const_iterator it=percentages.begin(),end=percentages.end(); it!=end; ++it) {
			if (*it != 0) {
				++minSize;
			}
		}
		int size = static_cast<int>(percentages.size());
		int min = static_cast<int>(100.0-0.49*(size-1.0)+0.5);
		int max = static_cast<int>(100.0-0.50*(minSize-1.0)+0.5+(minSize-1.0));
		int sum = 0;
		for (vector<int>::const_iterator it=percentages.begin(),end=percentages.end(); it!=end; ++it) {
			sum += *it;
		}
		if (min <= sum && sum <= max) {
			return "NO";
		}
		return "YES";
	}
};
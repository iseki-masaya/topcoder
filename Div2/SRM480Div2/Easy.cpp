#include <iostream>
#include <vector>

using namespace std;

class Cryptography {
public:
	long long encrypt(vector <int> numbers)
	{
		sort(numbers.begin(), numbers.end());
		++numbers.at(0);
		long long sum = 1;
		for (int i=0; i<numbers.size(); ++i) {
			sum *= numbers.at(i);
		}

		return sum;
	}
};
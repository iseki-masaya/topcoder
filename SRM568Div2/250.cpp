#include <iostream>
#include <vector>
#include <string>

using namespace std;

class TheSimilarNumbers {
		
public:
  int find(int lower,int upper)
	{
		int count = 0;
		int countFromUpper = 0;
		int countFromLower = 0;
		int work = upper;
		while (work > lower) {
			++countFromUpper;
			work /= 10;
		}
		work = lower;
		while (work <= upper) {
			++countFromLower;
			work *= 10;
			++work;
		}
		if (countFromLower > countFromUpper) {
			count = countFromLower;
		}
		else {
			count = countFromUpper;
		}
		return count;
	}
};
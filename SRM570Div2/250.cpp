#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Chopsticks
{
public:
	int getmax(vector <int> length)
	{
		int count = 0;
		sort(length.begin(), length.end());
		int previous = -1;
		for (vector<int>::iterator it = length.begin(); it != length.end(); ++it) {
			if (previous == *it) {
				++count;
				previous = -1;
			}
			else{
				previous = *it;
			}
		}
		
		return count;
	}
};
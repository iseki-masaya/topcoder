#include <vector>
#include <string>

using namespace std;

class FoxAndGame
{
public:
	int countStars(vector <string> result)
	{
		int count = 0;
		for (vector<string>::iterator it = result.begin(); it != result.end(); ++it) {
			for (int i=0; i<(*it).size(); ++i) {
				if ((*it)[i] == 'o') {
					++count;
				}
			}
		}
		return count;
	}
};
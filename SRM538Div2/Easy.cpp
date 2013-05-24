#include <string>
#include <iostream>

using namespace std;

class LeftOrRight
{
private:
	int count(const string &program,char W)
	{
		int num = 0;
		int ans = 0;
		for (int i=0; i<program.size(); ++i) {
			if (program.at(i) == W) {
				--num;
			}
			else {
				++num;
			}
			ans = max(ans,abs(num));
		}
		return ans;
	}
public:
	int maxDistance(string program)
	{
		return max(count(program, 'L'),count(program, 'R'));
	}
};

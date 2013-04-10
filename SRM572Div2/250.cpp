#include <vector>
#include <string>

using namespace std;

class EasyHomework
{
public:
	string determineSign(vector<int> A)
	{
		string sign;
		int countNegative=0;
		for (vector<int>::iterator it = A.begin(); it != A.end(); ++it) {
			if (*it == 0) {
				sign = "ZERO";
				break;
			}
			else if(*it < 0){
				++countNegative;
			}
		}
		if (sign == "") {
			if (countNegative%2 == 0) {
				sign = "POSITIVE";
			}
			else {
				sign = "NEGATIVE";
			}
		}
		return sign;
	}
};
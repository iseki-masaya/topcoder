#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

class AkariDaisukiDiv2
{
public:
	int countTuples(string S)
	{
		int size = static_cast<int>(S.size());
    int cnt = 0;
		for (int pos1 = 1; pos1<size-3; ++pos1) {
			for (int length1 = 1; length1<size; ++length1) {
				for (int pos2 = pos1+length1+1; pos2<size-length1; ++pos2) {
					if (S.substr(pos1,length1) == S.substr(pos2,length1)) {
						++cnt;
					}
				}
			}
		}
    return cnt;
	}
};
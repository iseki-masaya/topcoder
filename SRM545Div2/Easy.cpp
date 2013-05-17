#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

class ANDEquation
{
public:
	int restoreY(vector <int> A)
	{
		int pos,dst=0,work=0;
		for (pos=0;pos<A.size(); ++pos) {
			dst = A.at(pos);
			work = 2097151;
			for (int i=0; i<A.size(); ++i) {
				if (pos == i) continue;
				work = work & A.at(i);
			}
			if (dst == work) {
				return dst;
			}
		}

		return -1;
	}
};
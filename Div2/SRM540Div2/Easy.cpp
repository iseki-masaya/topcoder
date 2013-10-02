#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <errno.h>
#include <sstream>

using namespace std;

class RandomColoringDiv2
{
public:
	int getCount(int maxR, int maxG, int maxB, int startR, int startG, int startB, int d1, int d2)
	{
		int subR,subG,subB;
		int cnt = 0;
		for (int R=0; R<maxR; ++R) {
			for (int G=0; G<maxG; ++G) {
				for (int B=0; B<maxB; ++B) {
					subR = abs(R-startR);
					subG = abs(G-startG);
					subB = abs(B-startB);
					if (subR <= d2 && subG <= d2 && subB <= d2) {
						if (d1 <= subR || d1 <= subG || d1 <= subB) {
							++cnt;
						}
					}
				}
			}
		}

		return cnt;
	}
};
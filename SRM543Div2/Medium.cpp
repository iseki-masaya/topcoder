#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <time.h>
#include <bitset>

using namespace std;

class EllysXors
{
public:
	long long getVal(long long i)
	{
		long long ret = 0;
		switch ((i)%4) {
			case 0:
				ret = i;
				break;
			case 1:
				ret = 1;
				break;
			case 2:
				ret = i+1;
				break;
			case 3:
				ret = 0;
				break;

			default:
				break;
		}
		return ret;
	}

	long long getXor(long long L, long long R)
	{
		long long int left = getVal(L-1);
		long long int right = getVal(R);
		return left^right;
	}
};
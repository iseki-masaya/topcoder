#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

class BinaryFlips
{
public:
	int minimalMoves(int A, int B, int K)
	{
		for (long long int i=0 ; i<A+B+1; ++i) {
			long long int rest = i*K - A;
			long long int use = ((i/2)*B+((i-1)/2)*A)*2;
			if (rest>=0 && rest%2 == 0 && use >= rest) {
				return static_cast<int>(i);
			}
		}

		return -1;
	}
};
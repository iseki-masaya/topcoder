#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

class FoxAndGCDLCM
{
	long long gcd (long long a,long long b )
	{
		long long c;
		while ( a != 0 ) {
			c = a;
			a = b%a;
			b = c;
		}
		return b;
	}
public:
	long long get(long long G, long long L)
	{
		if (L%G!=0) {
			return -1;
		}
		long long ab = L/G;
		long long ans = -1;
		for (long long a=1; a*a<=ab; ++a) {
			if (ab%a==0) {
				long long b = ab/a;
				if (gcd(a, b) == 1) {
					long long res = (a+b)*G;
					if (ans == -1) {
						ans = res;
					}
					else {
						ans = min(ans,res);
					}
				}
			}
		}

		return ans;
	}
};
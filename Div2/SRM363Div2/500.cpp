#include <iostream>
#include <vector>
#include <string>

using namespace std;

long long int comb[51] = {0};

class HandsShaking
{
public:
	long long countPerfect(int n)
	{
		n = n/2;
		comb[0] = 1; comb[1] = 1;
		for (int k=2; k<=n; ++k) {
			for (int l=0; l<k; ++l) {
				comb[k] += comb[l]*comb[k-1-l];
			}
		}
		return comb[n];
	}
};
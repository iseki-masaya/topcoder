#include <iostream>
#include <map>

using namespace std;

#define MAX 1000000

class InfiniteSequence2
{
private:
	long long memo[MAX];
	int p,q,x,y;

	long long getNum(long long n)
	{
		if (n <= 0) return 1;

		if (n < MAX){
			if (memo[n] != 0) return memo[n];
			memo[n] = getNum(n/p - x) + getNum(n/q - y);
			return memo[n];
		}
		return getNum(n/p - x) + getNum(n/q - y);
	}
public:
	long long calc(long long n, int p, int q, int x, int y)
	{
		this->p = p;
		this->q = q;
		this->x = x;
		this->y = y;

		return getNum(n);
	}
};
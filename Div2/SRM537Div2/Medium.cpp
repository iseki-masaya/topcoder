#include <iostream>

using namespace std;


class KingXNewCurrency {
private:
	bool isComb(int num,int X,int Y)
	{
		for(int n=0;n*X<=num;++n)
			if((num-X*n)%Y == 0)
				return true;
		return false;
	}
public:
	int howMany(int A, int B, int X)
	{
		if(A%X==0 && B%X ==0)
			return -1;

		int ret = 0;
		for(int y=1;y<=max(A,B);++y)
			if(y!=X && isComb(A, X, y) && isComb(B, X, y))
				++ret;

		return ret;
	}
};
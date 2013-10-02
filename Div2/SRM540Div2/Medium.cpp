#include <string>
#include <vector>
#include <iostream>

using namespace std;

class ImportantSequence{public:
	int getCount( vector <int> B, string operators )
	{
    int N = (int)B.size()+1;

    long long mn = 1;
    long long mx = 1LL<<60;
		long long tmn = mn;
		long long tmx = mx;
		bool isAllMinus = true;

    for ( int i=0; i<N-1; i++ )
    {
			if ( operators[i]=='-' )
			{
				tmn = tmn - B[i];
				tmx = tmx - B[i];
			}
			else
			{
				isAllMinus = false;
				tmn = B[i] - tmn;
				tmx = B[i] - tmx;
			}

			if (tmn <= 0) {
				mn -= (tmn-1);
				tmn = 1;
			}
			if (tmx <= 0) {
				mx += (tmx-1);
				tmx = 1;
			}
    }
		if(isAllMinus)
			return -1;
		if(mx < mn)
			return 0;

    return static_cast<int>(mx-mn+1);
	}
};
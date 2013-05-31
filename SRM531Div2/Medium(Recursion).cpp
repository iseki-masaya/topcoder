#include <iostream>
#include <vector>

using namespace std;

#define MAX 111

int gP,gM;
long long dp[MAX][MAX];

class NoRepeatPlaylist {
public:
	long long countPlaylists(int XS,int YS,int position)
	{
		if(position==gP)
			return YS==0?1:0;

		if (dp[XS][position] != -1 ) {
			return dp[XS][position];
		}

		long long result = 0;
		if (YS>0) {
			result += countPlaylists(XS+1, YS-1, position+1)*YS;
		}
		if (XS>gM) {
			result += countPlaylists(XS, YS, position+1)*(XS-gM);
		}

		return (dp[XS][position] = result%1000000007);
	}

	int numPlaylists(int N, int M, int P)
	{
		gP = P; gM = M;
		memset(dp, -1, sizeof(dp));
		return static_cast<int>(countPlaylists(0, N, 0));
	}
};
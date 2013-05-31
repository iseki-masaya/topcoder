#include <iostream>
#include <vector>

using namespace std;

#define MAX 111
#define MOD 1000000007

long long dp[MAX][MAX];

class NoRepeatPlaylist {
public:
	int numPlaylists(int N, int M, int P)
	{
		memset(dp, 0, sizeof(dp));

		dp[0][0]=1;
		for (int i=0; i<P; ++i) {
			for (int j=0; j<N+1; ++j) {
				if (dp[i][j])
				{
					if (j<N)
					{
						dp[i+1][j+1] += dp[i][j]*(N-j);
						dp[i+1][j+1] %= MOD;
					}
					if (i>M && j>M)
					{
						dp[i+1][j] += dp[i][j]*(j-M);
						dp[i+1][j] %= MOD;
					}
				}
			}
		}
		return static_cast<int>(dp[P][N]);
	}
};
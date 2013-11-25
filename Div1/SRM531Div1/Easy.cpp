#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <list>
#include <algorithm>
#include <sstream>
#include <set>
#include <cmath>
#include <map>
#include <stack>
#include <queue>
#include <numeric>
#include <stdio.h>
#include <string.h>

#define INF (1<<30)
#define LINF (5e18)

using namespace std;

const int mod = 1000000007;

class NoRepeatPlaylist {
    int _P,_M;
    int dp[105][105][105];

public:
    long long countPlayList(int position,int XS,int YS) {
        if (position == _P)
            return YS == 0 ? 1 : 0;

        if (dp[position][XS][YS] != -1)
            return dp[position][XS][YS];

        long long result = 0;
        if (YS > 0)
            result += countPlayList(position+1, XS+1, YS-1)*YS;
        if (XS > _M)
            result += countPlayList(position+1, XS, YS)*(XS-_M);

        return dp[position][XS][YS] = result%mod;
    }

    int numPlaylists(int N, int M, int P) {
        _P = P;
        _M = M;
        memset(dp, -1, sizeof(dp));
        return (int)countPlayList(0, 0, N);
    }




};





// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor

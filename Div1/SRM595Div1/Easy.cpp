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
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <numeric>
#include <bitset>
#include <deque>

const long long LINF = (1e15);
const int INF = (1<<27);
#define EPS 1e-6
const int MOD = 1000000007;

using namespace std;

class LittleElephantAndIntervalsDiv1 {

public:

    long long getNumber(int M, vector <int> L, vector <int> R) {
        int N = (int)L.size();
        vector<int> balls(M+1,-1);
        for (int i=0; i<N; ++i) {
            for (int j=L[i]; j<=R[i]; ++j) {
                balls[j] = i;
            }
        }
        set<int> appear;
        for (int i=0; i<=M; ++i)
            if (balls[i] >= 0)
                appear.insert(balls[i]);

        return 1LL<<appear.size();
    }




};





// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor

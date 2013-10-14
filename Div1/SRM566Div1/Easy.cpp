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

#define INF (1<<30)
#define EPS 1e-6

using namespace std;

#define MAX_N 55

class PenguinSledding {

public:
    long long
    countDesigns(int numCheckpoints, vector <int> checkpoint1, vector <int> checkpoint2)
    {
        bool conn[MAX_N][MAX_N];
        memset(conn, false, sizeof(conn));
        int N = (int)checkpoint1.size();
        for (int i=0; i<N; ++i) {
            int s = checkpoint1[i]-1;
            int t = checkpoint2[i]-1;
            conn[s][t] = true;
            conn[t][s] = true;
        }

        long long res = 1;
        res += N;
        for (int i=0; i<numCheckpoints; ++i) {
            int n = 0;
            for (int k=0; k<numCheckpoints; ++k) {
                if (conn[i][k]) {
                    ++n;
                }
            }
            res += (1LL<<n) - n - 1;
        }

        for (int i=0; i<numCheckpoints; ++i) {
            for (int j=i+1; j<numCheckpoints; ++j) {
                for (int k=j+1; k<numCheckpoints; ++k) {
                    if (conn[i][j] && conn[j][k] && conn[k][i]) {
                        ++res;
                    }
                }
            }
        }

        return res;
    }




};





// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor

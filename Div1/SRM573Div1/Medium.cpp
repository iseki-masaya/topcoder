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
#include <stdio.h>
#include <string.h>
#include <numeric>

#define L_INF (100000000000000)
#define INF (100000000000000)
#define EPS 1e-6

using namespace std;

class SkiResorts {

public:

    long long
    minCost(vector <string> road, vector <int> h)
    {
        vector<int> e[55];
        int N = (int)road.size();
        long long dp[55][55];
        bool used[55][55];
        memset(used, false, sizeof(used));

        for (int i=0; i<N; ++i) {
            for (int j=0; j<N; ++j) {
                if (road[i][j] == 'Y') {
                    e[i].push_back(j);
                }
            }
        }

        for (int i=0; i<N; ++i) {
            fill(dp[i], dp[i]+N, INF);
        }

        for (int i=0; i<N; ++i) {
            dp[0][i] = abs(h[0]-h[i]);
        }

        queue<int> q;
        for (int i=0; i<N; ++i) {
            q.push(i);
            used[0][i] = true;
        }

        while (!q.empty()) {
            int c = q.front()/50 , he = q.front()%50;
            q.pop();
            used[c][he] = false;

            for (int i=0; i<e[c].size(); ++i) {
                for (int j=0; j<N; ++j) {
                    if (h[he] >= h[j]) {
                        int to = e[c][i];

                        long long nxt = dp[c][he] + abs(h[j] - h[to]);
                        if (nxt < dp[to][j]) {
                            dp[to][j] = nxt;
                            if (!used[to][j]) {
                                q.push(to*50 + j);
                                used[to][j] = true;
                            }
                        }
                    }
                }
            }
        }

        long long ans = INF;
        for (int i=0; i<N; ++i) {
            ans = min(ans , dp[N-1][i]);
        }
        return ans == INF ? -1 : ans;
    }




};





// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor

#include <string>
#include <cmath>
#include <fstream>
#include <iostream>
#include <sstream>
#include <list>
#include <algorithm>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <numeric>
#include <bitset>
#include <deque>
//#include <random>
#include <string.h>
#include <stdlib.h>
#include <vector>
#include <unordered_map>
#include <thread>

const long long LINF = (1e18);
const int INF = (1<<28);
const int sINF = (1<<23);
const int MOD = 1000000009;
const double EPS = 1e-6;

using namespace std;

class DrivingPlans {

public:
    struct edge {
        int to, cost;
        edge(int t, int c) : to(t), cost(c) {}
    };

    vector<vector<edge> > G;
    vector<vector<int> > dist;
    vector<int> memo;
    int N;
    typedef pair<int, int> P;

    void dijkstra(vector<int> &d, int s) {
        priority_queue<P,vector<P>,greater<P> > que;
        que.push(P(0, s));
        while (!que.empty()) {
            P p = que.top();
            que.pop();

            int c = p.first;
            int v = p.second;

            if (d[v] < c)
                continue;

            for (int u=0; u<G[v].size(); ++u) {
                edge e = G[v][u];
                if (d[e.to] > c + e.cost) {
                    d[e.to] = c + e.cost;
                    que.push(P(d[e.to], e.to));
                }
            }
        }
    }

    long long dfs(int v) {
        if (v == N-1)
            return 1;
        if (memo[v] != -1)
            return memo[v];
        long long c = 0;
        for (int i=0; i<G[v].size(); ++i) {
            edge e = G[v][i];
            int u = e.to;
            if (dist[0][N-1] == dist[0][v] + e.cost + dist[u][N-1] ) {
                if (e.cost == 0)
                    return -1;
                long long way = dfs(u);
                if (way < 0)
                    return -1;

                c = (c + way)%MOD;
            }
        }

        return memo[v] = (int)c;
    }

    int count(int N, vector <int> A, vector <int> B, vector <int> C) {
        this->N = N;
        int M = (int)A.size();
        G.clear();
        G.resize(N);
        for (int i=0; i<M; ++i) {
            G[A[i]-1].push_back(edge(B[i]-1, C[i]));
            G[B[i]-1].push_back(edge(A[i]-1, C[i]));
        }

        dist.clear();
        for (int i=0; i<N; ++i) {
            vector<int> d(N, INF);
            dijkstra(d, i);
            dist.push_back(d);
        }
        for (int i=0; i<N; ++i)
            dist[i][i] = 0;

        for (int i=0; i<G[N-1].size(); ++i) {
            if (G[N-1][i].cost == 0) {
                return -1;
            }
        }

        memo.clear();
        memo.resize(N, -1);
        return (int)dfs(0);
    }


    // BEGIN CUT HERE
public:
    void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
private:
    template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
    void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
    void test_case_0() { int Arg0 = 4; int Arr1[] = {1,1,2,3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {2,3,4,4}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {1,1,1,1}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 2; verify_case(0, Arg4, count(Arg0, Arg1, Arg2, Arg3)); }
    void test_case_1() { int Arg0 = 4; int Arr1[] = {1,1,2,3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {2,3,4,4}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {1,1,1,0}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = -1; verify_case(1, Arg4, count(Arg0, Arg1, Arg2, Arg3)); }
    void test_case_2() { int Arg0 = 7; int Arr1[] = {1,1,2,3,4,4,5,6}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {2,3,4,4,5,6,7,7}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {1,1,2,2,3,3,4,4}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 4; verify_case(2, Arg4, count(Arg0, Arg1, Arg2, Arg3)); }



    // END CUT HERE


};



// BEGIN CUT HERE

int main() {

    DrivingPlans ___test;

    ___test.run_test(-1);

}

// END CUT HERE

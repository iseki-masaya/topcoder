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

const long long LINF = (5e18);
const int INF = (1<<30);
const int sINF = (1<<23);
const int MOD = 1000000009;
const double EPS = 1e-6;

using namespace std;

class Ethernet {

public:

    vector<int> dist;
    vector<vector<int> > g, dp;
    int maxDist;

    int f(int x, int maxDepth) {
        if (dp[x][maxDepth] != -1)
            return dp[x][maxDepth];
        int res = 1;
        for (int y: g[x])
            res += f(y, maxDist);
        for (int y: g[x]) {
            for (int m=dist[y-1]; m <= maxDepth; ++m) {
                int r = min(maxDist - m, m);
                int tem = f(y, m - dist[y-1]);
                for (int z: g[x]) {
                    if (y == z)
                        continue;
                    int cut = f(z, maxDist);
                    if (dist[z-1] > r) {
                        tem += cut;
                    } else {
                        int with = f(z, r - dist[z-1]) - 1;
                        tem += min(cut, with);
                    }
                }
                res = min(res, tem);
            }
        }
        return dp[x][maxDepth] = res;
    }

    int connect(vector <int> parent, vector <int> dist, int maxDist) {
        int N = (int)parent.size() + 1;
        this->dist = dist;
        this->maxDist = maxDist;
        dp.clear();
        dp.resize(N+1, vector<int>(maxDist+1, -1));
        g.clear();
        g.resize(N);
        for (int i=1; i<N; ++i)
            g[parent[i-1]].push_back(i);
        return f(0, maxDist);
    }


    // BEGIN CUT HERE
public:
    void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
private:
    template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
    void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
    void test_case_0() { int Arr0[] = {0,0,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,1,1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; int Arg3 = 1; verify_case(0, Arg3, connect(Arg0, Arg1, Arg2)); }
    void test_case_1() { int Arr0[] = {0,0,0,0,0,0,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,2,3,4,5,6,7}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 8; int Arg3 = 4; verify_case(1, Arg3, connect(Arg0, Arg1, Arg2)); }
    void test_case_2() { int Arr0[] = {0,1,2,3,4,5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,2,3,4,5,6}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 6; int Arg3 = 3; verify_case(2, Arg3, connect(Arg0, Arg1, Arg2)); }
    void test_case_3() { int Arr0[] = {0,0,0,1,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,1,1,1,1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; int Arg3 = 2; verify_case(3, Arg3, connect(Arg0, Arg1, Arg2)); }
    void test_case_4() { int Arr0[] = {0,1,0,3,0,5,0,6,0,6,0,6,4,6,9,4,5,5,2,5,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {93,42,104,105,59,73,161,130,30,81,62,93,131,133,139,5,13,34,25,111,4}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 162; int Arg3 = 11; verify_case(4, Arg3, connect(Arg0, Arg1, Arg2)); }

    // END CUT HERE


};



// BEGIN CUT HERE

int main() {

    Ethernet ___test;

    ___test.run_test(-1);

}

// END CUT HERE

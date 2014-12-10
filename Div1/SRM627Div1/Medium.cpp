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
const int MOD = 1000000007;
const double EPS = 1e-6;

using namespace std;

class GraphInversions {

public:
    int K,N;
    vector<vector<int> > G;
    vector<int> V;
    vector<bool> visited;
    int bit[1005];

    int sum(int i) {
        int r = 0;
        while (i > 0) {
            r += bit[i];
            i -= i & -i;
        }
        return r;
    }

    void add(int i, int v) {
        while (i < 1005) {
            bit[i] += v;
            i += i&-i;
        }
    }

    int backtrack(int x, vector<int> &path, int inv) {
        path.push_back(x);
        inv += sum(V[x]-1);
        add(V[x], 1);
        visited[x] = true;

        int res = INF;
        if (path.size() >= K)
            res = min(res, inv);
        for (int i=0; i<G[x].size(); ++i) {
            int v = G[x][i];
            if (!visited[v])
                res = min(res, backtrack(v, path, inv));
        }
        path.pop_back();
        visited[x] = false;
        add(V[x], -1);
        return res;
    }

    int getMinimumInversions(vector <int> A, vector <int> B, vector <int> V, int K) {
        this->K = K;
        this->V = V;
        this->N = (int)A.size();
        G.clear();
        G.resize(N);
        visited.clear();
        visited.resize(N, false);
        for (int i=0; i<N; ++i) {
            G[A[i]].push_back(B[i]);
            G[B[i]].push_back(A[i]);
        }

        int ans = INF;
        for (int i=0; i<N; ++i) {
            memset(bit, 0, sizeof(bit));
            vector<int> trace;
            vector<int> S;
            ans = min(ans, backtrack(i, trace, 0));
        }

        return ans == INF ? -1 : ans;
    }


    // BEGIN CUT HERE
public:
    void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
private:
    template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
    void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
    void test_case_0() { int Arr0[] = {0,1,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,2,0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {40,50,60}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 3; int Arg4 = 0; verify_case(0, Arg4, getMinimumInversions(Arg0, Arg1, Arg2, Arg3)); }
    void test_case_1() { int Arr0[] = {0,1,2,3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,2,3,0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {60,40,50,30}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 3; int Arg4 = 1; verify_case(1, Arg4, getMinimumInversions(Arg0, Arg1, Arg2, Arg3)); }
    void test_case_2() { int Arr0[] = {0,1,2,3,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,2,3,0,4}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {10,10,10,5,5}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 5; int Arg4 = 1; verify_case(2, Arg4, getMinimumInversions(Arg0, Arg1, Arg2, Arg3)); }
    void test_case_3() { int Arr0[] = {0,1,2,3,0,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,2,3,0,4,5}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {10,2,5,3,7,1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 6; int Arg4 = -1; verify_case(3, Arg4, getMinimumInversions(Arg0, Arg1, Arg2, Arg3)); }
    void test_case_4() { int Arr0[] = {5,7,7,5,5,7,6,4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2,0,2,0,1,4,7,3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {15,10,5,30,22,10,5,2}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 6; int Arg4 = 3; verify_case(4, Arg4, getMinimumInversions(Arg0, Arg1, Arg2, Arg3)); }

    // END CUT HERE


};



// BEGIN CUT HERE

int main() {

    GraphInversions ___test;

    ___test.run_test(-1);

}

// END CUT HERE

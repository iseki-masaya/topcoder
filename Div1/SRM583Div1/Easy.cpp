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

class TravelOnMars {

public:
    vector<int> dp, r;
    int N;

    void rec(int n, int c) {
        if (dp[n] <= c) {
            return;
        }
        dp[n] = c;
        int d = r[n];
        for (int i=-d; i<=d; ++i) {
            int p = (50*N + n + i)%N;
            rec(p, c+1);
        }
    }

    int minTimes(vector <int> range, int startCity, int endCity) {
        N = (int)range.size();
        dp.clear();
        dp.resize(N,INF);
        r = range;
        rec(startCity, 0);
        return dp[endCity];
    }


    // BEGIN CUT HERE
public:
    void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
private:
    template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
    void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
    void test_case_0() { int Arr0[] = {2,1,1,1,1,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = 4; int Arg3 = 2; verify_case(0, Arg3, minTimes(Arg0, Arg1, Arg2)); }
    void test_case_1() { int Arr0[] = {2,1,1,1,1,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; int Arg2 = 1; int Arg3 = 3; verify_case(1, Arg3, minTimes(Arg0, Arg1, Arg2)); }
    void test_case_2() { int Arr0[] = {2,1,1,2,1,2,1,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; int Arg2 = 6; int Arg3 = 3; verify_case(2, Arg3, minTimes(Arg0, Arg1, Arg2)); }
    void test_case_3() { int Arr0[] = {2, 2, 1, 4, 5, 1, 5, 1, 5, 2, 3, 1, 4, 5, 5, 4, 4, 4, 1, 2, 4, 4, 2, 3, 4, 2, 1, 3, 2, 3, 5, 3, 3, 3, 2, 3, 2, 1, 3, 2, 5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; int Arg2 = 23; int Arg3 = 6; verify_case(3, Arg3, minTimes(Arg0, Arg1, Arg2)); }

    // END CUT HERE


};



// BEGIN CUT HERE

int main() {

    TravelOnMars ___test;

    ___test.run_test(-1);

}

// END CUT HERE

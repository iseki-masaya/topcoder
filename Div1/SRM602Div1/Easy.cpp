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

class TypoCoderDiv1 {

public:

    int getmax(vector <int> D, int X) {
        int dp[55][2205];
        memset(dp, -1, sizeof(dp));
        const int BROWN = 2200;
        int N = (int)D.size();
        for (int i=N; i>=0; --i) {
            for (int x=0; x<BROWN; ++x) {
                int &res = dp[i][x];
                if (i == N) {
                    res = 0;
                }
                else {
                    if (x + D[i] >= BROWN) {
                        if (i + 1 < N) {
                            if (x + D[i] - D[i+1] < BROWN) {
                                res = max(res, 2 + dp[i+2][max(0, x + D[i] - D[i+1])]);
                            }
                        }
                        else {
                            res = 1;
                        }
                    }
                    else {
                        res = max(res, dp[i+1][x + D[i]]);
                    }
                    res = max(res, dp[i+1][max(0, x - D[i])]);
                }
            }
        }
        return dp[0][X];
    }


    // BEGIN CUT HERE
public:
    void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
private:
    template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
    void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
    void test_case_0() { int Arr0[] = {100,200,100,1,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2000; int Arg2 = 3; verify_case(0, Arg2, getmax(Arg0, Arg1)); }
    void test_case_1() { int Arr0[] = {0,0,0,0,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2199; int Arg2 = 0; verify_case(1, Arg2, getmax(Arg0, Arg1)); }
    void test_case_2() { int Arr0[] = {90000,80000,70000,60000,50000,40000,30000,20000,10000}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; int Arg2 = 1; verify_case(2, Arg2, getmax(Arg0, Arg1)); }
    void test_case_3() { int Arr0[] = {1000000000,1000000000,10000,100000,2202,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1000; int Arg2 = 4; verify_case(3, Arg2, getmax(Arg0, Arg1)); }
    void test_case_4() { int Arr0[] = {2048,1024,5012,256,128,64,32,16,8,4,2,1,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2199; int Arg2 = 0; verify_case(4, Arg2, getmax(Arg0, Arg1)); }
    void test_case_5() { int Arr0[] = {61,666,512,229,618,419,757,217,458,883,23,932,547,679,565,767,513,798,870,31,379,294,929,892,173,127,796,353,913,115,802,803,948,592,959,127,501,319,140,694,851,189,924,590,790,3,669,541,342,272}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1223; int Arg2 = 29; verify_case(5, Arg2, getmax(Arg0, Arg1)); }
    void test_case_6() { int Arr0[] = {34,64,43,14,58,30,2,16,90,58,35,55,46,24,14,73,96,13,9,42,64,36,89,42,42,64,52,68,53,76,52,54,23,88,32,52,28,96,70,32,26,3,23,78,47,23,54,30,86,32}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1328; int Arg2 = 20; verify_case(6, Arg2, getmax(Arg0, Arg1)); }

    // END CUT HERE


};



// BEGIN CUT HERE

int main() {

    TypoCoderDiv1 ___test;

    ___test.run_test(-1);

}

// END CUT HERE

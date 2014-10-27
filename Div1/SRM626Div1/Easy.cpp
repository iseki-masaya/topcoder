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

const long long LINF = (1e18);
const int INF = (1<<28);
const int sINF = (1<<23);
const int MOD = 1000000007;
const double EPS = 1e-6;

using namespace std;

class FixedDiceGameDiv1 {

public:

    vector<double> make(int A, int b) {
        double dp[51][2501];
        memset(dp, 0, sizeof(dp));
        dp[0][0] = 1.0;

        for (int a=1; a<=A; ++a) {
            for (int x=1; x<=a*b; ++x) {
                dp[a][x] = 0.0;
                for (int y=1; y<=b && y<=x; ++y) {
                    dp[a][x] += dp[a-1][x-y] / b;
                }
            }
        }

        vector<double> ret(A*b+1, 0.0);
        for (int x=0; x<=A*b; x++)
            ret[x] = dp[A][x];
        return ret;
    }

    double getExpectation(int a, int b, int c, int d) {
        vector<double> Pa(make(a, b));
        vector<double> Pb(make(c, d));
        double pw = 0.0;
        for (int A=a; A<=a*b; ++A) {
            for (int B=c; B<=c*d; ++B) {
                if (A > B)
                    pw += Pa[A] * Pb[B];
            }
        }
        if (pw <= 0.0)
            return -1.0;
        double ans = 0.0;
        for (int A=a; A<=a*b; ++A) {
            for (int B=c; B<=c*d; ++B) {
                if (A > B) {
                    double p = Pa[A] * Pb[B];
                    ans += A * (p / pw);
                }
            }
        }
        return ans;
    }


    // BEGIN CUT HERE
public:
    void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
private:
    template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
    void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
    void test_case_0() { int Arg0 = 1; int Arg1 = 2; int Arg2 = 1; int Arg3 = 5; double Arg4 = 2.0; verify_case(0, Arg4, getExpectation(Arg0, Arg1, Arg2, Arg3)); }
    void test_case_1() { int Arg0 = 3; int Arg1 = 1; int Arg2 = 1; int Arg3 = 3; double Arg4 = 3.0; verify_case(1, Arg4, getExpectation(Arg0, Arg1, Arg2, Arg3)); }
    void test_case_2() { int Arg0 = 1; int Arg1 = 5; int Arg2 = 1; int Arg3 = 1; double Arg4 = 3.4999999999999996; verify_case(2, Arg4, getExpectation(Arg0, Arg1, Arg2, Arg3)); }
    void test_case_3() { int Arg0 = 2; int Arg1 = 6; int Arg2 = 50; int Arg3 = 30; double Arg4 = -1.0; verify_case(3, Arg4, getExpectation(Arg0, Arg1, Arg2, Arg3)); }
    void test_case_4() { int Arg0 = 50; int Arg1 = 11; int Arg2 = 50; int Arg3 = 50; double Arg4 = 369.8865999182022; verify_case(4, Arg4, getExpectation(Arg0, Arg1, Arg2, Arg3)); }

    // END CUT HERE


};



// BEGIN CUT HERE

int main() {

    FixedDiceGameDiv1 ___test;

    ___test.run_test(-1);

}

// END CUT HERE

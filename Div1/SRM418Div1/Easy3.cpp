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



const long long LINF = (5e18);
const int INF = (1<<29);
#define EPS 1e-6
const int MOD = 1000000007;

using namespace std;

class TwoLotteryGames {

public:

    double factorial(int n) {
        double v = 1;
        for (int i=1; i<=n; ++i) {
            v *= i;
        }
        return v;
    }

    double combination(double n, double r) {
        double numerator = factorial(n);
        double denominator = factorial(n-r)*factorial(r);
        return numerator / denominator;
    }

    double getHigherChanceGame(int n, int m, int k) {
        double numerator = 0;
        for (int i=m; i>=max(k, 2*m-n); --i)
            numerator += combination(m, i) * combination(n-m, m-i);
        double denominator = combination(n, m);
        return numerator / denominator;
    }


    // BEGIN CUT HERE
public:
    void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
private:
    template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
    void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
    void test_case_0() { int Arg0 = 3; int Arg1 = 2; int Arg2 = 1; double Arg3 = 1.0; verify_case(0, Arg3, getHigherChanceGame(Arg0, Arg1, Arg2)); }
    void test_case_1() { int Arg0 = 3; int Arg1 = 1; int Arg2 = 1; double Arg3 = 0.3333333333333333; verify_case(1, Arg3, getHigherChanceGame(Arg0, Arg1, Arg2)); }
    void test_case_2() { int Arg0 = 8; int Arg1 = 2; int Arg2 = 1; double Arg3 = 0.4642857142857143; verify_case(2, Arg3, getHigherChanceGame(Arg0, Arg1, Arg2)); }
    void test_case_3() { int Arg0 = 4; int Arg1 = 3; int Arg2 = 1; double Arg3 = 0.7571428571428571; verify_case(3, Arg3, getHigherChanceGame(Arg0, Arg1, Arg2)); }

    // END CUT HERE


};



// BEGIN CUT HERE

int main() {

    TwoLotteryGames ___test;

    ___test.run_test(3);

}

// END CUT HERE

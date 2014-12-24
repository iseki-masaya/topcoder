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
const int MOD = 1000000007;
const double EPS = 1e-6;

using namespace std;

class LongWordsDiv1 {

public:

    long long dp[5001];

    int mod_factorial(int n) {
        long long res = 1;
        for (int i=1; i<=n; ++i)
            res = (res * i)%MOD;
        return (int)res;
    }

    int count(int n) {
        dp[0] = 1;
        for (int i=1; i<=n; ++i) {
            dp[i] = dp[i-1];
            for (int p=1; p<i-1; ++p)
                dp[i] += (dp[p]*dp[i-1-p])%MOD;
            dp[i] %= MOD;
        }
        return ((long long)mod_factorial(n)*dp[n])%MOD;
    }


    // BEGIN CUT HERE
public:
    void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
private:
    template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
    void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
    void test_case_0() { int Arg0 = 1; int Arg1 = 1; verify_case(0, Arg1, count(Arg0)); }
    void test_case_1() { int Arg0 = 2; int Arg1 = 2; verify_case(1, Arg1, count(Arg0)); }
    void test_case_2() { int Arg0 = 5; int Arg1 = 1080; verify_case(2, Arg1, count(Arg0)); }
    void test_case_3() { int Arg0 = 100; int Arg1 = 486425238; verify_case(3, Arg1, count(Arg0)); }

    // END CUT HERE


};



// BEGIN CUT HERE

int main() {

    LongWordsDiv1 ___test;

    ___test.run_test(-1);

}

// END CUT HERE

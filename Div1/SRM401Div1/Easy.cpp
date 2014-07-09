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
const int INF = (1<<28);
#define EPS 1e-6
const int MOD = 1000000007;

using namespace std;

class FIELDDiagrams {

public:
    long long dp[55][55];
    int fieldOrder;

    long long dfs(int p, int v) {
        if (p == fieldOrder)
            return 0;
        if (dp[p][v] != -1)
            return dp[p][v];
        long long res = 0;
        for (int i=1; i<=min(v, fieldOrder-p); ++i) {
            res += 1 + dfs(p+1, i);
        }
        return dp[p][v] = res;
    }

    long long countDiagrams(int fieldOrder) {
        this->fieldOrder = fieldOrder;
        memset(dp, -1, sizeof(dp));
        return dfs(0, fieldOrder);
    }


    // BEGIN CUT HERE
public:
    void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
private:
    template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
    void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
    void test_case_0() { int Arg0 = 2; long long Arg1 = 4LL; verify_case(0, Arg1, countDiagrams(Arg0)); }
    void test_case_1() { int Arg0 = 3; long long Arg1 = 13LL; verify_case(1, Arg1, countDiagrams(Arg0)); }
    void test_case_2() { int Arg0 = 5; long long Arg1 = 131LL; verify_case(2, Arg1, countDiagrams(Arg0)); }
    void test_case_3() { int Arg0 = 30; long long Arg1 = 131LL; verify_case(2, Arg1, countDiagrams(Arg0)); }

    // END CUT HERE


};



// BEGIN CUT HERE

int main() {

    FIELDDiagrams ___test;

    ___test.run_test(-1);

}

// END CUT HERE

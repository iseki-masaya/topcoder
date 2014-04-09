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

class DoubleXor {

public:
    int calc(int A, int B) {
        int res = 0;
        int p = 1;
        while (A >= p || B >= p) {
            int a = (A/p)%10;
            int b = (B/p)%10;
            int d = (a^b)%10;
            res += d*p;
            p *= 10;
        }
        return res;
    }

    int calculate(int N) {
        int ans = N;
        for (int i=N-1; i>=1; --i) {
            ans = calc(ans, i);
        }
        return ans;
    }


    // BEGIN CUT HERE
public:
    void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4();if ((Case == -1) || (Case == 5)) test_case_5(); }
private:
    template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
    void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
    void test_case_0() { int Arg0 = 1; int Arg1 = 1; verify_case(0, Arg1, calculate(Arg0)); }
    void test_case_1() { int Arg0 = 2; int Arg1 = 3; verify_case(1, Arg1, calculate(Arg0)); }
    void test_case_2() { int Arg0 = 7; int Arg1 = 0; verify_case(2, Arg1, calculate(Arg0)); }
    void test_case_3() { int Arg0 = 10; int Arg1 = 11; verify_case(3, Arg1, calculate(Arg0)); }
    void test_case_4() { int Arg0 = 102; int Arg1 = 103; verify_case(4, Arg1, calculate(Arg0)); }
    void test_case_5() { int Arg0 = 654321; int Arg1 = 1; verify_case(5, Arg1, calculate(Arg0)); }

    // END CUT HERE


};



// BEGIN CUT HERE

int main() {

    DoubleXor ___test;

    ___test.run_test(-1);

}

// END CUT HERE

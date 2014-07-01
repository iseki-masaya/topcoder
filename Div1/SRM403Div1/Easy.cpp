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

class TheLuckyNumbers {

public:
    int calculate(int b, int N) {
        int res = 0;
        int p = 1;
        for (int i=0; i<N; ++i) {
            if (b & (1<<i))
                res += p*4;
            else
                res += p*7;
            p *= 10;
        }
        return res;
    }

    int simulate(int u) {
        int res = 0;
        for (int shift=1; shift<10; ++shift) {
            int lim = 1<<shift;
            for (int b=0; b<lim; ++b) {
                int v = calculate(b, shift);
                if (0 <= v && v <= u) {
                    ++res;
                }
            }
        }
        return res;
    }

    int count(int a, int b) {
        return simulate(b) - simulate(a-1);
    }


    // BEGIN CUT HERE
public:
    void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
private:
    template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
    void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
    void test_case_0() { int Arg0 = 1; int Arg1 = 10; int Arg2 = 2; verify_case(0, Arg2, count(Arg0, Arg1)); }
    void test_case_1() { int Arg0 = 11; int Arg1 = 20; int Arg2 = 0; verify_case(1, Arg2, count(Arg0, Arg1)); }
    void test_case_2() { int Arg0 = 74; int Arg1 = 77; int Arg2 = 2; verify_case(2, Arg2, count(Arg0, Arg1)); }
    void test_case_3() { int Arg0 = 1000000; int Arg1 = 5000000; int Arg2 = 64; verify_case(3, Arg2, count(Arg0, Arg1)); }

    // END CUT HERE


};



// BEGIN CUT HERE

int main() {

    TheLuckyNumbers ___test;

    ___test.run_test(-1);

}

// END CUT HERE

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

class MagicalSource {

public:

    long long calculate(long long x) {
        long long ans = x;
        long long t = 1;
        while (x >= t) {
            if (x%t == 0) {
                ans = x / t;
            }
            t = t*10 + 1;
        }
        return ans;
    }


    // BEGIN CUT HERE
public:
    void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
private:
    template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
    void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
    void test_case_0() { long long Arg0 = 1371110974LL; long long Arg1 = 1234LL; verify_case(0, Arg1, calculate(Arg0)); }
    void test_case_1() { long long Arg0 = 111111LL; long long Arg1 = 1LL; verify_case(1, Arg1, calculate(Arg0)); }
    void test_case_2() { long long Arg0 = 10989LL; long long Arg1 = 99LL; verify_case(2, Arg1, calculate(Arg0)); }
    void test_case_3() { long long Arg0 = 120LL; long long Arg1 = 120LL; verify_case(3, Arg1, calculate(Arg0)); }
    void test_case_4() { long long Arg0 = 109999999989LL; long long Arg1 = 99LL; verify_case(4, Arg1, calculate(Arg0)); }

    // END CUT HERE


};



// BEGIN CUT HERE

int main() {

    MagicalSource ___test;

    ___test.run_test(-1);

}

// END CUT HERE

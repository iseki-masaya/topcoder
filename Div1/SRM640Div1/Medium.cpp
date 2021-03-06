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
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <queue>
#include <cstdio>
//#include <cstdlib>
#include <cstring>
#include <numeric>
#include <bitset>
#include <deque>
#include <memory>

const long long LINF = (5e17);
const int INF = 1000000000;
#define EPS 1e-7
const int MOD = 1000000007;

using namespace std;

class MaximumBipartiteMatchingProblem {

public:

    long long a,b,c,d;

    long long calc(long long v) {
        if (v < d || c-v < d)
            return -1;
        return a*v + (c-v)*(b-v);
    }

    long long solve(int n1, int n2, int ansc, long long d) {
        this->a = max(n1, n2);
        this->b = min(n1, n2);
        this->c = ansc;
        this->d = d;
        if (b == c)
            return a*b;
        if (c < 2*d)
            return -1;
        return max(calc(0), calc(c-d));
    }


    // BEGIN CUT HERE
public:
    void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
private:
    template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
    void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
    void test_case_0() { int Arg0 = 3; int Arg1 = 3; int Arg2 = 2; int Arg3 = 1; long long Arg4 = 5LL; verify_case(0, Arg4, solve(Arg0, Arg1, Arg2, Arg3)); }
    void test_case_1() { int Arg0 = 3; int Arg1 = 3; int Arg2 = 1; int Arg3 = 1; long long Arg4 = -1LL; verify_case(1, Arg4, solve(Arg0, Arg1, Arg2, Arg3)); }
    void test_case_2() { int Arg0 = 5; int Arg1 = 10; int Arg2 = 5; int Arg3 = 2; long long Arg4 = 50LL; verify_case(2, Arg4, solve(Arg0, Arg1, Arg2, Arg3)); }
    void test_case_3() { int Arg0 = 100000000; int Arg1 = 87654321; int Arg2 = 12345678; int Arg3 = 54321; long long Arg4 = 1233229491567444LL; verify_case(3, Arg4, solve(Arg0, Arg1, Arg2, Arg3)); }
    void test_case_4() { int Arg0 = 1000000000; int Arg1 = 1000000000; int Arg2 = 1000000000; int Arg3 = 1000000000; long long Arg4 = 1000000000000000000LL; verify_case(4, Arg4, solve(Arg0, Arg1, Arg2, Arg3)); }

    // END CUT HERE


};



// BEGIN CUT HERE

int main() {

    MaximumBipartiteMatchingProblem ___test;

    ___test.run_test(-1);

}

// END CUT HERE

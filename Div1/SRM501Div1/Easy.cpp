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

const long long LINF = (1e15);
const int INF = (1<<27);
#define EPS 1e-6
const int MOD = 1000000009;

using namespace std;

class FoxPlayingGame {

public:
    double exp(int nB, double pB) {
        double res = 1;
        for (int i=0; i<nB; ++i)
            res *= pB;

        return res;
    }

    double theMax(int nA, int nB, int paramA, int paramB) {
        double A = nA * paramA / 1000.0;
        double b = paramB / 1000.0;
        double B = exp(nB, b);
        double B_ = exp(nB-1, b);

        return nB == 0 ? A : max(A*B, max(A*b, max(A, A*B_)));
    }


    // BEGIN CUT HERE
public:
    void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
private:
    template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
    void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
    void test_case_0() { int Arg0 = 5; int Arg1 = 4; int Arg2 = 3000; int Arg3 = 2000; double Arg4 = 240.0; verify_case(0, Arg4, theMax(Arg0, Arg1, Arg2, Arg3)); }
    void test_case_1() { int Arg0 = 3; int Arg1 = 3; int Arg2 = 2000; int Arg3 = 100; double Arg4 = 6.0; verify_case(1, Arg4, theMax(Arg0, Arg1, Arg2, Arg3)); }
    void test_case_2() { int Arg0 = 4; int Arg1 = 3; int Arg2 = -2000; int Arg3 = 2000; double Arg4 = -8.0; verify_case(2, Arg4, theMax(Arg0, Arg1, Arg2, Arg3)); }
    void test_case_3() { int Arg0 = 5; int Arg1 = 5; int Arg2 = 2000; int Arg3 = -2000; double Arg4 = 160.0; verify_case(3, Arg4, theMax(Arg0, Arg1, Arg2, Arg3)); }
    void test_case_4() { int Arg0 = 50; int Arg1 = 50; int Arg2 = 10000; int Arg3 = 2000; double Arg4 = 5.62949953421312E17; verify_case(4, Arg4, theMax(Arg0, Arg1, Arg2, Arg3)); }
    void test_case_5() { int Arg0 = 1; int Arg1 = 0; int Arg2 = -5153; int Arg3 = 31; double Arg4 = -5.153; verify_case(5, Arg4, theMax(Arg0, Arg1, Arg2, Arg3)); }
    // END CUT HERE


};



// BEGIN CUT HERE

int main() {

    FoxPlayingGame ___test;

    ___test.run_test(5);

}

// END CUT HERE

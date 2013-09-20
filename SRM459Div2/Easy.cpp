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
#include <stdio.h>
#include <string.h>
#include <numeric>

#define L_INF (1)
#define INF (1<<29)
#define EPS 1e-6

using namespace std;

class RecursiveFigures {

public:

    double
    getArea(int sideLength, int K)
    {
        double ans = 0.0;
        double L = sideLength;
        double sq = 0.0;
        for (int i=0; i<K; ++i) {
            ans -= sq;
            ans += L*L*M_PI/4.0;
            L = L/sqrt(2.0);
            sq = L*L;
        }
        return ans;
    }


    // BEGIN CUT HERE
public:
    void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
private:
    template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
    void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
    void test_case_0() { int Arg0 = 10; int Arg1 = 1; double Arg2 = 78.53981633974483; verify_case(0, Arg2, getArea(Arg0, Arg1)); }
    void test_case_1() { int Arg0 = 10; int Arg1 = 2; double Arg2 = 67.80972450961724; verify_case(1, Arg2, getArea(Arg0, Arg1)); }
    void test_case_2() { int Arg0 = 10; int Arg1 = 3; double Arg2 = 62.444678594553444; verify_case(2, Arg2, getArea(Arg0, Arg1)); }

    // END CUT HERE


};



// BEGIN CUT HERE

int main() {

    RecursiveFigures ___test;

    ___test.run_test(-1);

}

// END CUT HERE

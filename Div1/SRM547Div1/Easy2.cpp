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
#include <numeric>
#include <stdio.h>
#include <string.h>

#define INF (1<<28)
#define LINF (1e17)

using namespace std;

class Pillars {

public:

    double
    getExpectedLength(int w, int x, int y)
    {
        int N = max(x,y);

        double ans = 0.0;
        long long X = x , Y = y;
        for (long long i=0; i<N; ++i) {
            long long c = i == 0 ? min(X, Y) : max(0LL,min(X,Y-i)) + max(0LL,min(Y,X-i));
            ans += c*sqrt(w*w+i*i);
        }
        return ans/double(X*Y);
    }


    // BEGIN CUT HERE
public:
    void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3();if ((Case == -1) || (Case == 4)) test_case_4(); }
private:
    template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
    void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
    void test_case_0() { int Arg0 = 1; int Arg1 = 1; int Arg2 = 1; double Arg3 = 1.0; verify_case(0, Arg3, getExpectedLength(Arg0, Arg1, Arg2)); }
    void test_case_1() { int Arg0 = 1; int Arg1 = 5; int Arg2 = 1; double Arg3 = 2.387132965131785; verify_case(1, Arg3, getExpectedLength(Arg0, Arg1, Arg2)); }
    void test_case_2() { int Arg0 = 2; int Arg1 = 3; int Arg2 = 15; double Arg3 = 6.737191281760445; verify_case(2, Arg3, getExpectedLength(Arg0, Arg1, Arg2)); }
    void test_case_3() { int Arg0 = 10; int Arg1 = 15; int Arg2 = 23; double Arg3 = 12.988608956320535; verify_case(3, Arg3, getExpectedLength(Arg0, Arg1, Arg2)); }

    // END CUT HERE


};



// BEGIN CUT HERE

int main() {

    Pillars ___test;

    ___test.run_test(-1);

}

// END CUT HERE

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

class TheBoredomDivOne {

public:

    double find(int n, int m) {
        int t = n+m;
        vector<double> F(t+2,0.0);
        for (int x=t-1; x>=n; --x) {
            double cnt = 0, c0 = 0, c1 = 0, c2 = 0;
            for (int a=1; a<=t; ++a) {
                for (int b=a+1; b<=t; ++b) {
                    ++cnt;
                    if (a > x && b > x)
                        ++c2;
                    else if (a > x || b > x)
                        ++c1;
                    else
                        ++c0;
                }
            }
            double p0 = c0/cnt , p1 = c1/cnt , p2 = c2/cnt;
            F[x] = (1 + p1*F[x+1] + p2*F[x+2] ) / (1.0 - p0);
        }

        return F[n];
    }


    // BEGIN CUT HERE
public:
    void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
private:
    template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
    void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
    void test_case_0() { int Arg0 = 1; int Arg1 = 1; double Arg2 = 1.0; verify_case(0, Arg2, find(Arg0, Arg1)); }
    void test_case_1() { int Arg0 = 2; int Arg1 = 1; double Arg2 = 1.5; verify_case(1, Arg2, find(Arg0, Arg1)); }
    void test_case_2() { int Arg0 = 1; int Arg1 = 2; double Arg2 = 2.0; verify_case(2, Arg2, find(Arg0, Arg1)); }
    void test_case_3() { int Arg0 = 4; int Arg1 = 7; double Arg2 = 13.831068977298521; verify_case(3, Arg2, find(Arg0, Arg1)); }

    // END CUT HERE


};



// BEGIN CUT HERE

int main() {

    TheBoredomDivOne ___test;

    ___test.run_test(-1);

}

// END CUT HERE

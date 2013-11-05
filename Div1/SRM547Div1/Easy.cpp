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

const long long LINF = (1e11);
const int INF = (1<<30);
#define EPS 1e-6
const int MOD = 10007;

using namespace std;

class Pillars {

public:

    double
    getExpectedLength(int w, int x, int y)
    {
        int mn = min(x,y);
        int mx = max(x,y);
        vector<int> cnt(mx,0);
        vector<double> l(mx);
        cnt[0] = min(x,y);

        l[0] = w;
        double sqw = w*w;
        for (long long i=1; i<mx; ++i) {
            l[i] = sqrt(sqw+i*i);
        }
        for (int i=1; i<mn; ++i) {
            cnt[i] += (mn-i)*2;
        }
        for (int i=1; i<mx; ++i) {
            cnt[i] += min(min(mn,mx-mn), min(mx - i, i));
        }
        double num = (double)x*y;

        double sum = 0;
        for (int i=0; i<mx; ++i) {
            sum += l[i]*(double)cnt[i];
        }
        return sum/num;
    }


    // BEGIN CUT HERE
public:
    void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
private:
    template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
    void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
    void test_case_0() { int Arg0 = 1; int Arg1 = 1; int Arg2 = 1; double Arg3 = 1.0; verify_case(0, Arg3, getExpectedLength(Arg0, Arg1, Arg2)); }
    void test_case_1() { int Arg0 = 1; int Arg1 = 5; int Arg2 = 1; double Arg3 = 2.387132965131785; verify_case(1, Arg3, getExpectedLength(Arg0, Arg1, Arg2)); }
    void test_case_2() { int Arg0 = 2; int Arg1 = 3; int Arg2 = 15; double Arg3 = 6.737191281760445; verify_case(2, Arg3, getExpectedLength(Arg0, Arg1, Arg2)); }
    void test_case_3() { int Arg0 = 1000; int Arg1 = 100000; int Arg2 = 100000; double Arg3 = 33381.38304701605; verify_case(3, Arg3, getExpectedLength(Arg0, Arg1, Arg2)); }

    // END CUT HERE

};



// BEGIN CUT HERE

int main() {

    Pillars ___test;

    ___test.run_test(3);

}

// END CUT HERE

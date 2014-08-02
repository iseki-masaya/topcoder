#include <vector>
#include <string>
#include <cmath>
#include <fstream>
#include <iostream>
#include <sstream>
#include <list>
#include <algorithm>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <numeric>
#include <bitset>
#include <deque>
#include <random>

const long long LINF = (1e18);
const int INF = (1<<28);
const int sINF = (1<<23);
const int MOD = 1000000007;
const double EPS = 1e-6;

using namespace std;

class LameKnight {

public:

    int maxCells(int height, int width) {
        if (height >= 3 && width >= 6)
            return width-2;
        if (height == 1 || width == 1)
            return 1;
        if (height == 2)
            return min(4, (1+width)/2);
        return min(4, width);
    }


    // BEGIN CUT HERE
public:
    void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
private:
    template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
    void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
    void test_case_0() { int Arg0 = 100; int Arg1 = 50; int Arg2 = 48; verify_case(0, Arg2, maxCells(Arg0, Arg1)); }
    void test_case_1() { int Arg0 = 1; int Arg1 = 1; int Arg2 = 1; verify_case(1, Arg2, maxCells(Arg0, Arg1)); }
    void test_case_2() { int Arg0 = 17; int Arg1 = 5; int Arg2 = 4; verify_case(2, Arg2, maxCells(Arg0, Arg1)); }
    void test_case_3() { int Arg0 = 2; int Arg1 = 4; int Arg2 = 2; verify_case(3, Arg2, maxCells(Arg0, Arg1)); }
    void test_case_4() { int Arg0 = 20; int Arg1 = 4; int Arg2 = 4; verify_case(4, Arg2, maxCells(Arg0, Arg1)); }

    // END CUT HERE


};



// BEGIN CUT HERE

int main() {

    LameKnight ___test;

    ___test.run_test(-1);

}

// END CUT HERE

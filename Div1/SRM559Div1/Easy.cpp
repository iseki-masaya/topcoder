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

#define INF (1<<28)
#define EPS 1e-8
#define MOD 100000000

using namespace std;

class HyperKnight {

public:

    long long
    countCells(int a, int b, int numRows, int numColumns, int k)
    {
        long long X = numColumns;
        long long Y = numRows;
        long long mn = min(a,b);
        long long mx = max(a,b);
        switch (k) {
            case 8:
                return (X-2*mx)*(Y-2*mx);
            case 6:
                return 2*(mx-mn)*(X+Y-4*mx);
            case 4:
                return 2*mn*(X+Y-4*mx)+4*(mx-mn)*(mx-mn);
            case 3:
                return 8*mn*(mx-mn);
            case 2:
                return 4*mn*mn;
            default:
                return 0;
        }
    }


    // BEGIN CUT HERE
public:
    void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
private:
    template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
    void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
    void test_case_0() { int Arg0 = 2; int Arg1 = 1; int Arg2 = 8; int Arg3 = 8; int Arg4 = 4; long long Arg5 = 20LL; verify_case(0, Arg5, countCells(Arg0, Arg1, Arg2, Arg3, Arg4)); }
    void test_case_1() { int Arg0 = 3; int Arg1 = 2; int Arg2 = 8; int Arg3 = 8; int Arg4 = 2; long long Arg5 = 16LL; verify_case(1, Arg5, countCells(Arg0, Arg1, Arg2, Arg3, Arg4)); }
    void test_case_2() { int Arg0 = 1; int Arg1 = 3; int Arg2 = 7; int Arg3 = 11; int Arg4 = 0; long long Arg5 = 0LL; verify_case(2, Arg5, countCells(Arg0, Arg1, Arg2, Arg3, Arg4)); }
    void test_case_3() { int Arg0 = 3; int Arg1 = 2; int Arg2 = 10; int Arg3 = 20; int Arg4 = 8; long long Arg5 = 56LL; verify_case(3, Arg5, countCells(Arg0, Arg1, Arg2, Arg3, Arg4)); }
    void test_case_4() { int Arg0 = 1; int Arg1 = 4; int Arg2 = 100; int Arg3 = 10; int Arg4 = 6; long long Arg5 = 564LL; verify_case(4, Arg5, countCells(Arg0, Arg1, Arg2, Arg3, Arg4)); }
    void test_case_5() { int Arg0 = 2; int Arg1 = 3; int Arg2 = 1000000000; int Arg3 = 1000000000; int Arg4 = 8; long long Arg5 = 999999988000000036LL; verify_case(5, Arg5, countCells(Arg0, Arg1, Arg2, Arg3, Arg4)); }

    // END CUT HERE


};



// BEGIN CUT HERE

int main() {

    HyperKnight ___test;

    ___test.run_test(-1);

}

// END CUT HERE

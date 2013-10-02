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
#include <time.h>
#include <numeric>

using namespace std;

#define INF (1<<26)

class MatrixShiftings {

public:

    int
    minimumShifts(vector <string> matrix, int value)
    {
        int res = INF;
        int X = (int)matrix[0].size();
        int Y = (int)matrix.size();

        for (int y=0; y<Y; ++y) {
            for (int x=0; x<X; ++x) {
                if (matrix[y][x] != value + '0') {
                    continue;
                }
                res = min( res , min(y,Y-y) + min(x,X-x) );
            }
        }

        return res == INF ? -1 : res;
    }


    // BEGIN CUT HERE
public:
    void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
private:
    template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
    void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
    void test_case_0() { string Arr0[] = {"136",
        "427",
        "568",
        "309"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; int Arg2 = 2; verify_case(0, Arg2, minimumShifts(Arg0, Arg1)); }
    void test_case_1() { string Arr0[] = {"0000",
        "0000",
        "0099"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 9; int Arg2 = 2; verify_case(1, Arg2, minimumShifts(Arg0, Arg1)); }
    void test_case_2() { string Arr0[] = {"0123456789"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 7; int Arg2 = 3; verify_case(2, Arg2, minimumShifts(Arg0, Arg1)); }
    void test_case_3() { string Arr0[] = {"555",
        "555"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = -1; verify_case(3, Arg2, minimumShifts(Arg0, Arg1)); }
    void test_case_4() { string Arr0[] = {"12417727123",
        "65125691886",
        "55524912622",
        "12261288888"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 9; int Arg2 = 6; verify_case(4, Arg2, minimumShifts(Arg0, Arg1)); }

    // END CUT HERE


};



// BEGIN CUT HERE

int main() {

    MatrixShiftings ___test;

    ___test.run_test(-1);

}

// END CUT HERE

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
const int INF = (1<<28);
#define EPS 1e-6
const int MOD = 1000000009;

using namespace std;

class DivideAndShift {

public:
    int getLeast(int N, int M) {
        int res = N;
        M--;
        for (int y=1; y<=N; ++y) {
            if (N%y != 0)
                continue;

            int x = N/y;
            int c = 0;
            for (int p=2; p<=x/p; ++p) {
                while (x%p == 0) {
                    x /= p;
                    ++c;
                }
            }
            c += x!=1 ? 1: 0;

            int s = min(M%y,y - M%y);
            res = min(res,s+c);
        }

        return res;
    }


    // BEGIN CUT HERE
public:
    void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
private:
    template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
    void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
    void test_case_0() { int Arg0 = 56; int Arg1 = 14; int Arg2 = 3; verify_case(0, Arg2, getLeast(Arg0, Arg1)); }
    void test_case_1() { int Arg0 = 49; int Arg1 = 5; int Arg2 = 2; verify_case(1, Arg2, getLeast(Arg0, Arg1)); }
    void test_case_2() { int Arg0 = 256; int Arg1 = 7; int Arg2 = 6; verify_case(2, Arg2, getLeast(Arg0, Arg1)); }
    void test_case_3() { int Arg0 = 6; int Arg1 = 1; int Arg2 = 0; verify_case(3, Arg2, getLeast(Arg0, Arg1)); }
    void test_case_4() { int Arg0 = 77777; int Arg1 = 11111; int Arg2 = 2; verify_case(4, Arg2, getLeast(Arg0, Arg1)); }

    // END CUT HERE


};



// BEGIN CUT HERE

int main() {

    DivideAndShift ___test;

    ___test.run_test(-1);

}

// END CUT HERE

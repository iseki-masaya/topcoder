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



const long long LINF = (5e18);
const int INF = (1<<31);
#define EPS 1e-6
const int MOD = 1000000007;

using namespace std;

class ProductOfDigits {

public:

    int smallestNumber(int N) {
        if (N == 1)
            return 1;

        int ans = 0;
        for (int d=9; d>1; --d) {
            while (N%d == 0) {
                N /= d;
                ++ans;
            }
        }
        if (N > 9)
            return -1;
        if (N != 1)
            ++ans;
        return ans;
    }


    // BEGIN CUT HERE
public:
    void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5();if ((Case == -1) || (Case == 6)) test_case_6(); }
private:
    template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
    void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
    void test_case_0() { int Arg0 = 1; int Arg1 = 1; verify_case(0, Arg1, smallestNumber(Arg0)); }
    void test_case_1() { int Arg0 = 10; int Arg1 = 2; verify_case(1, Arg1, smallestNumber(Arg0)); }
    void test_case_2() { int Arg0 = 26; int Arg1 = -1; verify_case(2, Arg1, smallestNumber(Arg0)); }
    void test_case_3() { int Arg0 = 100; int Arg1 = 3; verify_case(3, Arg1, smallestNumber(Arg0)); }
    void test_case_4() { int Arg0 = 2520; int Arg1 = 4; verify_case(4, Arg1, smallestNumber(Arg0)); }
    void test_case_5() { int Arg0 = 864; int Arg1 = 4; verify_case(5, Arg1, smallestNumber(Arg0)); }
    void test_case_6() { int Arg0 = 1171875; int Arg1 = 9; verify_case(6, Arg1, smallestNumber(Arg0)); }

    // END CUT HERE


};



// BEGIN CUT HERE

int main() {

    ProductOfDigits ___test;

    ___test.run_test(6);

}

// END CUT HERE

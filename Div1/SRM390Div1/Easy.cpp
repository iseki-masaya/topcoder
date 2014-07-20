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
const int INF = (1<<28);
#define EPS 1e-6
const int MOD = 1000000007;

using namespace std;

class ConcatenateNumber {

public:

    int getSmallest(int number, int k) {
        long long p10 = 1;
        while (p10 <= number) p10 *= 10;
        long long current = number%k;
        for (int i=1; i<=k; ++i) {
            if (current == 0)
                return i;
            current = (p10*current + number)%k;
        }
        return -1;
    }


    // BEGIN CUT HERE
public:
    void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
private:
    template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
    void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
    void test_case_0() { int Arg0 = 2; int Arg1 = 9; int Arg2 = 9; verify_case(0, Arg2, getSmallest(Arg0, Arg1)); }
    void test_case_1() { int Arg0 = 121; int Arg1 = 11; int Arg2 = 1; verify_case(1, Arg2, getSmallest(Arg0, Arg1)); }
    void test_case_2() { int Arg0 = 1; int Arg1 = 2; int Arg2 = -1; verify_case(2, Arg2, getSmallest(Arg0, Arg1)); }
    void test_case_3() { int Arg0 = 35; int Arg1 = 98765; int Arg2 = 9876; verify_case(3, Arg2, getSmallest(Arg0, Arg1)); }
    void test_case_4() { int Arg0 = 1000000000; int Arg1 = 3; int Arg2 = 3; verify_case(4, Arg2, getSmallest(Arg0, Arg1)); }

    // END CUT HERE


};



// BEGIN CUT HERE

int main() {

    ConcatenateNumber ___test;

    ___test.run_test(-1);

}

// END CUT HERE

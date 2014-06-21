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
const int INF = (1<<29);
#define EPS 1e-6
const int MOD = 1000000007;

using namespace std;

class ArithmeticProgression {

public:

    int calc(int a0, vector<int> &seq, long double d, bool &isMatch) {
        int res = 0;
        long double k = a0;
        for (int v: seq) {
            k += d;
            long long a = floor(k);
            if (a < v)
                res = -1;
            else if (a > v)
                res = 1;
        }
        if (res == 0)
            isMatch = true;
        return res == 0 ? 1 : res;
    }

    double minCommonDifference(int a0, vector <int> seq) {
        double lb = 0.0, ub = 1e12;
        bool isMatch = false;
        for (int i=0; i<400; ++i) {
            double md = (lb+ub)/2.0;
            int res = calc(a0, seq, md, isMatch);
            if (res == -1)
                lb = md;
            else if (res == 1)
                ub = md;
        }
        return isMatch ? lb : -1;
    }


    // BEGIN CUT HERE
public:
    void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
private:
    template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
    void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
    void test_case_0() { int Arg0 = 0; int Arr1[] = {6, 13, 20, 27}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 6.75; verify_case(0, Arg2, minCommonDifference(Arg0, Arg1)); }
    void test_case_1() { int Arg0 = 1; int Arr1[] = {2, 3, 4, 5, 6}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 1.0; verify_case(1, Arg2, minCommonDifference(Arg0, Arg1)); }
    void test_case_2() { int Arg0 = 3; int Arr1[] = {}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 0.0; verify_case(2, Arg2, minCommonDifference(Arg0, Arg1)); }
    void test_case_3() { int Arg0 = 3; int Arr1[] = {3, 3, 3, 3, 4}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 0.2; verify_case(3, Arg2, minCommonDifference(Arg0, Arg1)); }
    void test_case_4() { int Arg0 = 1; int Arr1[] = {-3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = -1.0; verify_case(4, Arg2, minCommonDifference(Arg0, Arg1)); }
    void test_case_5() { int Arg0 = -10; int Arr1[] = {-8, -7}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = -1.0; verify_case(5, Arg2, minCommonDifference(Arg0, Arg1)); }

    // END CUT HERE


};



// BEGIN CUT HERE

int main() {

    ArithmeticProgression ___test;

    ___test.run_test(5);

}

// END CUT HERE

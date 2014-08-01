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

class TheDiceGame {

public:

    double expectedThrows(int candies) {
        vector<double> res(7,0);
        res[6] = 1.0;
        for (int n=2; n<=candies; ++n) {
            for (int i=0; i<6; ++i)
                res[i] = res[i+1];
            double sum = accumulate(res.begin(), res.begin()+6, 0.0);
            res[6] = 1.0 + sum/6.0;
        }
        return res[6];
    }


    // BEGIN CUT HERE
public:
    void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
private:
    template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
    void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
    void test_case_0() { int Arg0 = 1; double Arg1 = 1.0; verify_case(0, Arg1, expectedThrows(Arg0)); }
    void test_case_1() { int Arg0 = 2; double Arg1 = 1.1666666666666667; verify_case(1, Arg1, expectedThrows(Arg0)); }
    void test_case_2() { int Arg0 = 7; double Arg1 = 2.5216263717421126; verify_case(2, Arg1, expectedThrows(Arg0)); }
    void test_case_3() { int Arg0 = 47; double Arg1 = 13.90476189046144; verify_case(3, Arg1, expectedThrows(Arg0)); }

    // END CUT HERE


};



// BEGIN CUT HERE

int main() {

    TheDiceGame ___test;

    ___test.run_test(-1);

}

// END CUT HERE

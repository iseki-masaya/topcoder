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

using namespace std;

class TheNumberGameDivOne {

public:
    bool
    check(long long n)
    {
        for (long long i=2; i<=n; i<<=2) {
            if (i==n) {
                return true;
            }
        }
        return false;
    }

    string
    find(long long n)
    {
        if (n&1 || check(n)) {
            return "Brus";
        }
        return "John";
    }


    // BEGIN CUT HERE
public:
    void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
private:
    template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
    void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
    void test_case_0() { long long Arg0 = 6LL; string Arg1 = "John"; verify_case(0, Arg1, find(Arg0)); }
    void test_case_1() { long long Arg0 = 2LL; string Arg1 = "Brus"; verify_case(1, Arg1, find(Arg0)); }
    void test_case_2() { long long Arg0 = 747LL; string Arg1 = "Brus"; verify_case(2, Arg1, find(Arg0)); }
    void test_case_3() { long long Arg0 = 128LL; string Arg1 = "Brus"; verify_case(3, Arg1, find(Arg0)); }

    // END CUT HERE


};



// BEGIN CUT HERE

int main() {

    TheNumberGameDivOne ___test;

    ___test.run_test(-1);

}

// END CUT HERE

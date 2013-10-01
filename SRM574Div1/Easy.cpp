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
#include <numeric>

#define L_INF (1)
#define INF (1<<29)
#define EPS 1e-6

using namespace std;

class TheNumberGame {

public:
    string
    determineOutcome(int A, int B)
    {
        string a,b,inv_b = "";
        stringstream ss;
        ss << A;
        ss >> a;
        ss.clear();
        ss << B;
        ss >> b;
        for (int i=(int)b.size()-1; i >= 0; --i) {
            inv_b += b[i];
        }
        if (a.size() >= b.size() && (a.find(b) != string::npos || a.find(inv_b) != string::npos ) ) {
            return "Manao wins";
        }
        else {
            return "Manao loses";
        }
    }


    // BEGIN CUT HERE
public:
    void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
private:
    template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
    void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
    void test_case_0() { int Arg0 = 45; int Arg1 = 4; string Arg2 = "Manao wins"; verify_case(0, Arg2, determineOutcome(Arg0, Arg1)); }
    void test_case_1() { int Arg0 = 45; int Arg1 = 5; string Arg2 = "Manao wins"; verify_case(1, Arg2, determineOutcome(Arg0, Arg1)); }
    void test_case_2() { int Arg0 = 99; int Arg1 = 123; string Arg2 = "Manao loses"; verify_case(2, Arg2, determineOutcome(Arg0, Arg1)); }
    void test_case_3() { int Arg0 = 2356236; int Arg1 = 5666; string Arg2 = "Manao loses"; verify_case(3, Arg2, determineOutcome(Arg0, Arg1)); }

    // END CUT HERE


};



// BEGIN CUT HERE

int main() {

    TheNumberGame ___test;

    ___test.run_test(-1);

}

// END CUT HERE


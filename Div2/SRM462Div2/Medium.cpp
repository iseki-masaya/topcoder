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

class AgeEncoding {

public:
    bool
    check(int age,double base ,string &str)
    {
        double res = 0;
        double exp =1;
        for (int i=(int)str.size()-1; i>=0; --i) {
            if (str[i] == '1') {
                res += exp;
            }
            exp *= base;
        }
        return age < res;
    }

    bool
    anyOne(string &str)
    {
        for (int i=0; i<str.size()-1; ++i) {
            if (str[i] == '1') {
                return false;
            }
        }
        return str[str.size()-1] == '1';
    }

    double
    getRadix(int age, string candlesLine)
    {
        if (age == 1) {
            if (anyOne(candlesLine)) {
                return -2.0;
            }
            if (candlesLine[candlesLine.size()-1] == '1') {
                return -1.0;
            }
        }
        if (age == 1 && anyOne(candlesLine)) {
            return -2.0;
        }
        double lb = 0.0 , ub = 101.0;
        for (int i=0; i<100; ++i) {
            double mid = (lb+ub)/2.0;
            if (check(age,mid, candlesLine)) {
                ub = mid;
            }
            else {
                lb = mid;
            }
        }
        if (lb < EPS || 100+EPS < ub) {
            return -1.0;
        }
        return ub;
    }


    // BEGIN CUT HERE
public:
    void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
private:
    template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
    void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
    void test_case_0() { int Arg0 = 1; string Arg1 = "1000000000000000001"; double Arg2 = -1.0; verify_case(0, Arg2, getRadix(Arg0, Arg1)); }
    void test_case_1() { int Arg0 = 21; string Arg1 = "10101"; double Arg2 = 2.0; verify_case(1, Arg2, getRadix(Arg0, Arg1)); }
    void test_case_2() { int Arg0 = 6; string Arg1 = "10100"; double Arg2 = 1.414213562373095; verify_case(2, Arg2, getRadix(Arg0, Arg1)); }
    void test_case_3() { int Arg0 = 21; string Arg1 = "10111111110111101111111100111111110111111111111100"; double Arg2 = 0.9685012944510603; verify_case(3, Arg2, getRadix(Arg0, Arg1)); }
    void test_case_4() { int Arg0 = 16; string Arg1 = "1"; double Arg2 = -1.0; verify_case(4, Arg2, getRadix(Arg0, Arg1)); }
    void test_case_5() { int Arg0 = 1; string Arg1 = "1"; double Arg2 = -2.0; verify_case(5, Arg2, getRadix(Arg0, Arg1)); }
    void test_case_6() { int Arg0 = 1; string Arg1 = "001000"; double Arg2 = 1.0; verify_case(6, Arg2, getRadix(Arg0, Arg1)); }

    // END CUT HERE


};



// BEGIN CUT HERE

int main() {

    AgeEncoding ___test;

    ___test.run_test(-1);

}

// END CUT HERE

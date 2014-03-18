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

const long long LINF = (1e15);
const int INF = (1<<27);
#define EPS 1e-6
const int MOD = 1000000007;

using namespace std;

class AgeEncoding {

public:
    double calc(double base, string &line) {
        int N = (int)line.size();
        double b = 1.0;
        double s = 0.0;
        for (int i=N-1; i>=0; --i) {
            if (line[i] == '1') {
                s += b;
            }
            b *= base;
        }
        return s;
    }

    double getRadix(int age, string candlesLine) {
        int N = (int)candlesLine.size();
        int cnt = 0;
        for (int i=0; i<N; ++i)
            if (candlesLine[i] == '1')
                ++cnt;
        if (cnt == 0)
            return -1;
        if (cnt == 1 && candlesLine[N-1] == '1')
            return age == 1 ? -2 : -1;
        if (age == 1 && cnt > 1 && candlesLine[N-1] == '1')
            return -1;

        double lb = 0.0 , ub = 100.0;
        for (int i=0; i<200; ++i) {
            double md = (ub + lb) / 2.0;
            double v = calc(md, candlesLine);
            if (age >= v)
                lb = md;
            else
                ub = md;
        }

        return lb;
    }


    // BEGIN CUT HERE
public:
    void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); if ((Case == -1) || (Case == 7)) test_case_7(); }
private:
    template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
    void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
    void test_case_0() { int Arg0 = 10; string Arg1 = "00010"; double Arg2 = 10.0; verify_case(0, Arg2, getRadix(Arg0, Arg1)); }
    void test_case_1() { int Arg0 = 21; string Arg1 = "10101"; double Arg2 = 2.0; verify_case(1, Arg2, getRadix(Arg0, Arg1)); }
    void test_case_2() { int Arg0 = 6; string Arg1 = "10100"; double Arg2 = 1.414213562373095; verify_case(2, Arg2, getRadix(Arg0, Arg1)); }
    void test_case_3() { int Arg0 = 21; string Arg1 = "10111111110111101111111100111111110111111111111100"; double Arg2 = 0.9685012944510603; verify_case(3, Arg2, getRadix(Arg0, Arg1)); }
    void test_case_4() { int Arg0 = 16; string Arg1 = "1"; double Arg2 = -1.0; verify_case(4, Arg2, getRadix(Arg0, Arg1)); }
    void test_case_5() { int Arg0 = 1; string Arg1 = "1"; double Arg2 = -2.0; verify_case(5, Arg2, getRadix(Arg0, Arg1)); }
    void test_case_6() { int Arg0 = 1; string Arg1 = "001000"; double Arg2 = 1.0; verify_case(6, Arg2, getRadix(Arg0, Arg1)); }
    void test_case_7() { int Arg0 = 1; string Arg1 = "11"; double Arg2 = -1.0; verify_case(7, Arg2, getRadix(Arg0, Arg1)); }

    // END CUT HERE


};



// BEGIN CUT HERE

int main() {

    AgeEncoding ___test;

    ___test.run_test(-1);

}

// END CUT HERE

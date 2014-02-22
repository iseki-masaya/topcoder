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

class BestApproximationDiv1 {

public:
    string calc(int n, int d) {
        stringstream ss;
        string res;
        n *= 1000000;
        int dv = n/d;
        double v = dv / 1000000.0;
        ss << v;
        ss >> res;
        while (res.size() < 8) {
            res.push_back('0');
        }
        return res;
    }

    int count(string &lhs, string &rhs) {
        int res = 1;
        int p = 2;
        while (p < 8 && lhs[p] == rhs[p]) {
            ++res;
            ++p;
        }
        return res;
    }

    string conv(int v) {
        stringstream ss;
        string res;
        ss << v;
        ss >> res;
        return res;
    }

    string findFraction(int maxDen, string number) {
        int cnt = 0;
        int denominator = 0;
        int numerator = 0;
        for (int d=1; d<=maxDen; ++d) {
            for (int n=0; n<d; ++n) {
                string v = calc(n, d);
                int c = count(v, number);
                if (cnt < c) {
                    cnt = c;
                    denominator = d;
                    numerator = n;
                    string vv = calc(n, d);
                }
            }
        }

        return conv(numerator) + "/" + conv(denominator) + " has " + conv(cnt) + " exact digits";
    }


    // BEGIN CUT HERE
public:
    void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
private:
    template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
    void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
    void test_case_0() { int Arg0 = 42; string Arg1 = "0.141592"; string Arg2 = "1/7 has 3 exact digits"; verify_case(0, Arg2, findFraction(Arg0, Arg1)); }
    void test_case_1() { int Arg0 = 3; string Arg1 = "0.133700"; string Arg2 = "0/1 has 1 exact digits"; verify_case(1, Arg2, findFraction(Arg0, Arg1)); }
    void test_case_2() { int Arg0 = 1000; string Arg1 = "0.123456"; string Arg2 = "10/81 has 7 exact digits"; verify_case(2, Arg2, findFraction(Arg0, Arg1)); }
    void test_case_3() { int Arg0 = 1000; string Arg1 = "0.420000"; string Arg2 = "21/50 has 7 exact digits"; verify_case(3, Arg2, findFraction(Arg0, Arg1)); }
    void test_case_4() { int Arg0 = 283; string Arg1 = "0.032520"; string Arg2 = "4/123 has 7 exact digits"; verify_case(4, Arg2, findFraction(Arg0, Arg1)); }
    void test_case_5() { int Arg0 = 240; string Arg1 = "0.512490"; string Arg2 = "103/201 has 5 exact digits"; verify_case(5, Arg2, findFraction(Arg0, Arg1)); }
    // END CUT HERE


};



// BEGIN CUT HERE

int main() {

    BestApproximationDiv1 ___test;

    ___test.run_test(-1);

}

// END CUT HERE

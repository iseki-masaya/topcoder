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

class TwoStringMasks {

public:

    string shortestCommon(string &s1, string &s2) {
        string prefix = "";
        while (s1[0] != '*' && s2[0] != '*') {
            if (s1[0] != s2[0])
                return "impossible";
            prefix += s1[0];
            s1 = s1.substr(1);
            s2 = s2.substr(1);
        }
        string suffix = "";
        while (s1[s1.size()-1] != '*' && s2[s2.size()-1] != '*') {
            if (s1[s1.size()-1] != s2[s2.size()-1])
                return "impossible";
            suffix += s1[s1.size()-1];
            s1 = s1.substr(0, s1.size()-1);
            s2 = s2.substr(0, s2.size()-1);
        }
        reverse(suffix.begin(), suffix.end());
        if (s1 == "*")
            swap(s1, s2);
        if (s2 == "*") {
            int p = 0;
            for (; p<s1.size(); ++p)
                if (s1[p] == '*')
                    break;
            return prefix + s1.substr(0,p) + s1.substr(p+1) + suffix;
        }
        if (s1[0] != '*')
            swap(s1, s2);
        for (int i=(int)s1.size(); i>0; --i) {
            int a = 1;
            int b = (int)s2.size() - i;
            if (b < 0)
                continue;
            for (; a<i; ++a, ++b) {
                if (s1[a] != s2[b]) {
                    break;
                }
            }
            if (a == i)
                return prefix + s2.substr(0,s2.size() - i) + s1.substr(1) + suffix;
        }
        return "impossible";
    }


    // BEGIN CUT HERE
public:
    void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); if ((Case == -1) || (Case == 7)) test_case_7(); }
private:
    template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
    void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
    void test_case_0() { string Arg0 = "TOPC*DER"; string Arg1 = "T*PCODER"; string Arg2 = "TOPCODER"; verify_case(0, Arg2, shortestCommon(Arg0, Arg1)); }
    void test_case_1() { string Arg0 = "HELLO*"; string Arg1 = "HI*"; string Arg2 = "impossible"; verify_case(1, Arg2, shortestCommon(Arg0, Arg1)); }
    void test_case_2() { string Arg0 = "GOOD*LUCK"; string Arg1 = "*"; string Arg2 = "GOODLUCK"; verify_case(2, Arg2, shortestCommon(Arg0, Arg1)); }
    void test_case_3() { string Arg0 = "*SAMPLETEST"; string Arg1 = "THIRDSAMPLE*"; string Arg2 = "THIRDSAMPLETEST"; verify_case(3, Arg2, shortestCommon(Arg0, Arg1)); }
    void test_case_4() { string Arg0 = "*TOP"; string Arg1 = "*CODER"; string Arg2 = "impossible"; verify_case(4, Arg2, shortestCommon(Arg0, Arg1)); }
    void test_case_5() { string Arg0 = "*"; string Arg1 = "A*"; string Arg2 = "A"; verify_case(5, Arg2, shortestCommon(Arg0, Arg1)); }
    void test_case_6() { string Arg0 = "*A"; string Arg1 = "B*"; string Arg2 = "BA"; verify_case(6, Arg2, shortestCommon(Arg0, Arg1)); }
    void test_case_7() { string Arg0 = "LASTCASE*"; string Arg1 = "*LASTCASE"; string Arg2 = "LASTCASE"; verify_case(7, Arg2, shortestCommon(Arg0, Arg1)); }

    // END CUT HERE


};



// BEGIN CUT HERE

int main() {

    TwoStringMasks ___test;

    ___test.run_test(-1);

}

// END CUT HERE

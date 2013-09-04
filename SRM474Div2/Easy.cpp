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
#include <numeric>

using namespace std;

class PalindromesCount {

public:
    bool
    isPalindrome(const string &str)
    {
        for (int i=0,j=(int)str.size()-1; i<str.size(); ++i,--j) {
            if (str[i] != str[j]) {
                return false;
            }
        }
        return true;
    }


    int
    count(string A, string B)
    {
        int res = 0;
        for (int i=0; i<=A.size(); ++i) {
            string t = A;
            t.insert(i, B);
            if (isPalindrome(t)) {
                ++res;
            }
        }
        return res;
    }


    // BEGIN CUT HERE
public:
    void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
private:
    template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
    void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
    void test_case_0() { string Arg0 = "aba"; string Arg1 = "b"; int Arg2 = 2; verify_case(0, Arg2, count(Arg0, Arg1)); }
    void test_case_1() { string Arg0 = "aa"; string Arg1 = "a"; int Arg2 = 3; verify_case(1, Arg2, count(Arg0, Arg1)); }
    void test_case_2() { string Arg0 = "aca"; string Arg1 = "bb"; int Arg2 = 0; verify_case(2, Arg2, count(Arg0, Arg1)); }
    void test_case_3() { string Arg0 = "abba"; string Arg1 = "abba"; int Arg2 = 3; verify_case(3, Arg2, count(Arg0, Arg1)); }
    void test_case_4() { string Arg0 = "topcoder"; string Arg1 = "coder"; int Arg2 = 0; verify_case(4, Arg2, count(Arg0, Arg1)); }

    // END CUT HERE


};



// BEGIN CUT HERE

int main() {

    PalindromesCount ___test;

    ___test.run_test(-1);

}

// END CUT HERE

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
//#include <random>
#include <string.h>
#include <stdlib.h>
#include <vector>

const long long LINF = (1e18);
const int INF = (1<<28);
const int sINF = (1<<23);
const int MOD = 1000000007;
const double EPS = 1e-6;

using namespace std;

class PalindromePermutations {

public:

    double palindromeProbability(string word) {
        int N = (int)word.size();

        double f[55];
        f[0] = 1.0;
        for (int i=1; i<=N; ++i)
            f[i] = i * f[i-1];

        double p = f[N/2], q = f[N];
        int odd = 0;
        for (char c = 'a'; c <= 'z'; ++c) {
            int t = (int)count(word.begin(), word.end(), c);
            if (t&1)
                ++odd;

            p /= f[(t/2)];
            q /= f[t];
        }
        if (odd > 1 || ( odd != (N&1) ) )
            return 0.0;
        return p / q;
    }


    // BEGIN CUT HERE
public:
    void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
private:
    template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
    void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
    void test_case_0() { string Arg0 = "haha"; double Arg1 = 0.3333333333333333; verify_case(0, Arg1, palindromeProbability(Arg0)); }
    void test_case_1() { string Arg0 = "xxxxy"; double Arg1 = 0.2; verify_case(1, Arg1, palindromeProbability(Arg0)); }
    void test_case_2() { string Arg0 = "xxxx"; double Arg1 = 1.0; verify_case(2, Arg1, palindromeProbability(Arg0)); }
    void test_case_3() { string Arg0 = "abcde"; double Arg1 = 0.0; verify_case(3, Arg1, palindromeProbability(Arg0)); }
    void test_case_4() { string Arg0 = "hhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhff"; double Arg1 = 0.025641025641025637; verify_case(4, Arg1, palindromeProbability(Arg0)); }

    // END CUT HERE


};



// BEGIN CUT HERE

int main() {

    PalindromePermutations ___test;

    ___test.run_test(-1);

}

// END CUT HERE

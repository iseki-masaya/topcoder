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

const long long LINF = (1e11);
const int INF = (1<<28);
#define EPS 1e-6
const int MOD = 1000000007;

using namespace std;

class CompositeSmash {

public:
    bool rec(int N,int target) {
        if (N == target) {
            return true;
        }

        bool is_match = true;
        bool is_prime = true;
        for (int i=2; i*i<=N; ++i) {
            if (N%i == 0) {
                is_prime = false;
                bool is_have = false;
                is_have |= rec(N/i, target);
                is_have |= rec(i, target);
                is_match &= is_have;
            }
        }

        return is_prime && N != target ? false : is_match;
    }

    string thePossible(int N, int target) {
        return rec(N, target) ? "Yes" : "No";
    }


    // BEGIN CUT HERE
public:
    void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); if ((Case == -1) || (Case == 7)) test_case_7(); }
private:
    template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
    void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
    void test_case_0() { int Arg0 = 517; int Arg1 = 47; string Arg2 = "Yes"; verify_case(0, Arg2, thePossible(Arg0, Arg1)); }
    void test_case_1() { int Arg0 = 8; int Arg1 = 4; string Arg2 = "Yes"; verify_case(1, Arg2, thePossible(Arg0, Arg1)); }
    void test_case_2() { int Arg0 = 12; int Arg1 = 6; string Arg2 = "No"; verify_case(2, Arg2, thePossible(Arg0, Arg1)); }
    void test_case_3() { int Arg0 = 5; int Arg1 = 8; string Arg2 = "No"; verify_case(3, Arg2, thePossible(Arg0, Arg1)); }
    void test_case_4() { int Arg0 = 100000; int Arg1 = 100000; string Arg2 = "Yes"; verify_case(4, Arg2, thePossible(Arg0, Arg1)); }
    void test_case_5() { int Arg0 = 5858; int Arg1 = 2; string Arg2 = "Yes"; verify_case(5, Arg2, thePossible(Arg0, Arg1)); }
    void test_case_6() { int Arg0 = 81461; int Arg1 = 2809; string Arg2 = "No"; verify_case(6, Arg2, thePossible(Arg0, Arg1)); }
    void test_case_7() { int Arg0 = 65536; int Arg1 = 256; string Arg2 = "No"; verify_case(7, Arg2, thePossible(Arg0, Arg1)); }

    // END CUT HERE


};



// BEGIN CUT HERE

int main() {

    CompositeSmash ___test;

    ___test.run_test(-1);

}

// END CUT HERE

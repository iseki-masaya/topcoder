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

class PotatoGame {

public:

    string theWinner(int n) {
        int p = (n-1)%5;
        if (p == 1 || p == 4) {
            return "Hanako";
        }
        return "Taro";
    }


    // BEGIN CUT HERE
public:
    void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
private:
    template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
    void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
    void test_case_0() { int Arg0 = 1; string Arg1 = "Taro"; verify_case(0, Arg1, theWinner(Arg0)); }
    void test_case_1() { int Arg0 = 2; string Arg1 = "Hanako"; verify_case(1, Arg1, theWinner(Arg0)); }
    void test_case_2() { int Arg0 = 3; string Arg1 = "Taro"; verify_case(2, Arg1, theWinner(Arg0)); }

    // END CUT HERE


};



// BEGIN CUT HERE

int main() {

    PotatoGame ___test;

    ___test.run_test(-1);

}

// END CUT HERE

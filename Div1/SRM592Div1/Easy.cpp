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

const int ma = 10000;

using namespace std;

class LittleElephantAndBalls {

public:

    int getNumber(string S) {
        set<char> left,right;
        int res = 0;
        for (char c : S) {
            res += left.size() + right.size();
            ( left.count(c) ? right : left ).insert(c);
        }
        return res;
    }


    // BEGIN CUT HERE
public:
    void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
private:
    template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
    void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
    void test_case_0() { string Arg0 = "RGB"; int Arg1 = 3; verify_case(0, Arg1, getNumber(Arg0)); }
    void test_case_1() { string Arg0 = "RGGRBBB"; int Arg1 = 21; verify_case(1, Arg1, getNumber(Arg0)); }
    void test_case_2() { string Arg0 = "RRRGBRR"; int Arg1 = 16; verify_case(2, Arg1, getNumber(Arg0)); }
    void test_case_3() { string Arg0 = "RRRR"; int Arg1 = 5; verify_case(3, Arg1, getNumber(Arg0)); }
    void test_case_4() { string Arg0 = "GGRRRGR"; int Arg1 = 18; verify_case(4, Arg1, getNumber(Arg0)); }
    void test_case_5() { string Arg0 = "G"; int Arg1 = 0; verify_case(5, Arg1, getNumber(Arg0)); }

    // END CUT HERE


};



// BEGIN CUT HERE

int main() {

    LittleElephantAndBalls ___test;

    ___test.run_test(-1);

}

// END CUT HERE

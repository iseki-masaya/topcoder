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
const int INF = (1<<30);
#define EPS 1e-6
const int MOD = 1000000007;

using namespace std;

class LampsGrid {

public:

    int count(string &s) {
        int res = 0;
        for (char ch : s)
            if (ch == '0')
                ++res;
        return res;
    }

    int mostLit(vector <string> initial, int K) {
        map<string, int> m;
        for (string s : initial)
            m[s]++;

        int ans = 0;
        for (pair<string, int> p : m) {
            int c = K - count(p.first);
            if (c >= 0 && (c&1)==0 ) {
                ans = max(ans, p.second);
            }
        }

        return ans;
    }


    // BEGIN CUT HERE
public:
    void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
private:
    template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
    void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
    void test_case_0() { string Arr0[] = {"01",
        "10",
        "10"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = 2; verify_case(0, Arg2, mostLit(Arg0, Arg1)); }
    void test_case_1() { string Arr0[] = {"101010"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; int Arg2 = 0; verify_case(1, Arg2, mostLit(Arg0, Arg1)); }
    void test_case_2() { string Arr0[] = {"00", "11"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 999; int Arg2 = 0; verify_case(2, Arg2, mostLit(Arg0, Arg1)); }
    void test_case_3() { string Arr0[] = {"0", "1", "0", "1", "0"}
        ; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1000; int Arg2 = 2; verify_case(3, Arg2, mostLit(Arg0, Arg1)); }
    void test_case_4() { string Arr0[] = {
        "001",
        "101",
        "001",
        "000",
        "111",
        "001",
        "101",
        "111",
        "110",
        "000",
        "111",
        "010",
        "110",
        "001"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 6; int Arg2 = 4; verify_case(4, Arg2, mostLit(Arg0, Arg1)); }
    void test_case_5() { string Arr0[] = {"01", "10", "01", "01", "10"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = 3; verify_case(5, Arg2, mostLit(Arg0, Arg1)); }

    // END CUT HERE


};



// BEGIN CUT HERE

int main() {

    LampsGrid ___test;

    ___test.run_test(-1);

}

// END CUT HERE

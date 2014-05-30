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

class TheLuckyString {

public:

    int solve(vector<int> &rest, string &mg) {
        bool isComplete = true;
        int res = 0;
        for (int i=0; i<26; ++i) {
            if (rest[i] > 0) {
                isComplete = false;
                if (mg.back() == ('a'+i) )
                    continue;
                mg.push_back('a'+i);
                rest[i]--;
                res += solve(rest, mg);
                rest[i]++;
                mg.pop_back();
            }
        }

        if (isComplete)
            return 1;
        return res;
    }

    int count(string s) {
        vector<int> rest(26);
        for (char ch: s)
            rest[ch-'a']++;
        string mg = "";
        return solve(rest, mg);
    }


    // BEGIN CUT HERE
public:
    void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
private:
    template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
    void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
    void test_case_0() { string Arg0 = "ab"; int Arg1 = 2; verify_case(0, Arg1, count(Arg0)); }
    void test_case_1() { string Arg0 = "aaab"; int Arg1 = 0; verify_case(1, Arg1, count(Arg0)); }
    void test_case_2() { string Arg0 = "aabbbaa"; int Arg1 = 1; verify_case(2, Arg1, count(Arg0)); }
    void test_case_3() { string Arg0 = "abcdefghij"; int Arg1 = 3628800; verify_case(3, Arg1, count(Arg0)); }

    // END CUT HERE


};



// BEGIN CUT HERE

int main() {

    TheLuckyString ___test;

    ___test.run_test(-1);

}

// END CUT HERE

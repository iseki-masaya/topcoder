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

class LargestSubsequence {

public:

    string getLargest(string s) {
        string rev = s;
        sort(rev.begin(), rev.end(), greater<char>());
        string ans = "";

        int N = (int)s.size();
        int p = 0;
        s += '\n';
        for (int i=0; i<N; ++i) {
            int t = p;
            while (t < N && s[t] != rev[i]) ++t;
            if (s[t] == rev[i]) {
                ans += s[t];
                p = t + 1;
            }
        }

        return ans;
    }


    // BEGIN CUT HERE
public:
    void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
private:
    template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
    void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
    void test_case_0() { string Arg0 = "test"; string Arg1 = "tt"; verify_case(0, Arg1, getLargest(Arg0)); }
    void test_case_1() { string Arg0 = "a"; string Arg1 = "a"; verify_case(1, Arg1, getLargest(Arg0)); }
    void test_case_2() { string Arg0 = "example"; string Arg1 = "xple"; verify_case(2, Arg1, getLargest(Arg0)); }
    void test_case_3() { string Arg0 = "aquickbrownfoxjumpsoverthelazydog"; string Arg1 = "zyog"; verify_case(3, Arg1, getLargest(Arg0)); }

    // END CUT HERE


};



// BEGIN CUT HERE

int main() {

    LargestSubsequence ___test;

    ___test.run_test(-1);

}

// END CUT HERE

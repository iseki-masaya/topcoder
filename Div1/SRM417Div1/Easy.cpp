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
const int INF = (1<<29);
#define EPS 1e-6
const int MOD = 1000000007;

using namespace std;

class TemplateMatching {

public:
    int calc(string &s, string &p) {
        for (int i=(int)min(s.size(), p.size()); i>0; --i) {
            if (s.substr(0, i) == p.substr(p.size()-i)) {
                return i;
            }
        }
        return 0;
    }

    string bestMatch(string text, string prefix, string suffix) {
        int N = (int)text.size();
        string ans = "";
        int bs1 = -1, bs2 = -1;
        for (int i=0; i<N; ++i) {
            for (int j=1; j<=N-i; ++j) {
                string candidate = text.substr(i, j);
                int s1 = calc(candidate, prefix);
                int s2 = calc(suffix, candidate);
                if (s1 + s2 > bs1 + bs2 || (s1 + s2 == bs1 + bs2 && s1 > bs1) || (s1 + s2 == bs1 + bs2 && s1 == bs1 && candidate < ans) ) {
                    bs1 = s1;
                    bs2 = s2;
                    ans = candidate;
                }
            }
        }
        return ans;
    }


    // BEGIN CUT HERE
public:
    void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
private:
    template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
    void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
    void test_case_0() { string Arg0 = "something"; string Arg1 = "awesome"; string Arg2 = "ingenious"; string Arg3 = "something"; verify_case(0, Arg3, bestMatch(Arg0, Arg1, Arg2)); }
    void test_case_1() { string Arg0 = "havka"; string Arg1 = "eto"; string Arg2 = "papstvo"; string Arg3 = "a"; verify_case(1, Arg3, bestMatch(Arg0, Arg1, Arg2)); }
    void test_case_2() { string Arg0 = "abracadabra"; string Arg1 = "habrahabr"; string Arg2 = "bracket"; string Arg3 = "abrac"; verify_case(2, Arg3, bestMatch(Arg0, Arg1, Arg2)); }
    void test_case_3() { string Arg0 = "mississippi"; string Arg1 = "promise"; string Arg2 = "piccolo"; string Arg3 = "ippi"; verify_case(3, Arg3, bestMatch(Arg0, Arg1, Arg2)); }
    void test_case_4() { string Arg0 = "a a a a a a"; string Arg1 = "a a"; string Arg2 = "a"; string Arg3 = "a a"; verify_case(4, Arg3, bestMatch(Arg0, Arg1, Arg2)); }
    void test_case_5() { string Arg0 = "ab"; string Arg1 = "b"; string Arg2 = "a"; string Arg3 = "b"; verify_case(5, Arg3, bestMatch(Arg0, Arg1, Arg2)); }

    // END CUT HERE


};



// BEGIN CUT HERE

int main() {

    TemplateMatching ___test;

    ___test.run_test(-1);

}

// END CUT HERE

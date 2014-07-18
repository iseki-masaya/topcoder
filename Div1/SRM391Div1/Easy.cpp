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

class IsomorphicWords {

public:
    vector<int> conv(string &s) {
        int num = 0;
        map<char, int> m;
        vector<int> res;
        for (char ch: s) {
            if (!m.count(ch))
                m[ch] = num++;
            res.push_back(m[ch]);
        }
        return res;
    }

    bool check(string &lhs, string &rhs) {
        return conv(lhs) == conv(rhs);
    }

    int countPairs(vector <string> words) {
        // search : O(N^2)
        // check  : O(2M)
        int N = (int)words.size();
        int ans = 0;
        for (int i=0; i<N; ++i)
            for (int j=i+1; j<N; ++j)
                if (check(words[i], words[j]))
                    ++ans;
        return ans;
    }


    // BEGIN CUT HERE
public:
    void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
private:
    template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
    void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
    void test_case_0() { string Arr0[] = {"abca", "zbxz", "opqr"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(0, Arg1, countPairs(Arg0)); }
    void test_case_1() { string Arr0[] = {"aa", "ab", "bb", "cc", "cd"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; verify_case(1, Arg1, countPairs(Arg0)); }
    void test_case_2() { string Arr0[] = { "cacccdaabc", "cdcccaddbc", "dcdddbccad", "bdbbbaddcb",
        "bdbcadbbdc", "abaadcbbda", "babcdabbac", "cacdbaccad",
        "dcddabccad", "cacccbaadb", "bbcdcbcbdd", "bcbadcbbca" }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 13; verify_case(2, Arg1, countPairs(Arg0)); }

    // END CUT HERE


};



// BEGIN CUT HERE

int main() {

    IsomorphicWords ___test;

    ___test.run_test(-1);

}

// END CUT HERE

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

class GooseTattarrattatDiv1 {

public:
    bool used[30];
    bool conn[30][30];
    map<int, int> m;

    int dfs(int v) {
        used[v] = true;
        int res = m[v];
        for (int i=0; i<='z'-'a'; ++i) {
            if (conn[v][i] && !used[i]) {
                res = max(res, dfs(i));
            }
        }
        return res;
    }

    int getmin(string S) {
        memset(conn, false, sizeof(conn));
        m.clear();

        int N = (int)S.size();
        int left = 0, right = N-1;
        while (right > left) {
            int lhs = S[left]  - 'a';
            int rhs = S[right] - 'a';
            conn[lhs][rhs] = true;
            conn[rhs][lhs] = true;
            m[lhs]++, m[rhs]++;
            ++left, --right;
        }
        if (right == left)
            m[S[left]-'a']++;

        int ans = N;
        memset(used, false, sizeof(used));
        for (int i=0; i<='z'-'a'; ++i) {
            if (!used[i] && m.count(i)) {
                vector<int> v;
                ans -= dfs(i);
            }
        }
        return ans;
    }


    // BEGIN CUT HERE
public:
    void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
private:
    template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
    void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
    void test_case_0() { string Arg0 = "geese"; int Arg1 = 2; verify_case(0, Arg1, getmin(Arg0)); }
    void test_case_1() { string Arg0 = "tattarrattat"; int Arg1 = 0; verify_case(1, Arg1, getmin(Arg0)); }
    void test_case_2() { string Arg0 = "xyyzzzxxx"; int Arg1 = 2; verify_case(2, Arg1, getmin(Arg0)); }
    void test_case_3() { string Arg0 = "xrepayuyubctwtykrauccnquqfuqvccuaakylwlcjuyhyammag"; int Arg1 = 11; verify_case(3, Arg1, getmin(Arg0)); }
    void test_case_4() { string Arg0 = "abaabb"; int Arg1 = 3; verify_case(4, Arg1, getmin(Arg0)); }

    // END CUT HERE


};



// BEGIN CUT HERE

int main() {

    GooseTattarrattatDiv1 ___test;

    ___test.run_test(-1);

}

// END CUT HERE

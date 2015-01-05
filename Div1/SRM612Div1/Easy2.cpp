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
#include <unordered_map>
#include <thread>

const long long LINF = (5e18);
const int INF = (1<<30);
const int sINF = (1<<23);
const int MOD = 1000000007;
const double EPS = 1e-6;

using namespace std;

class EmoticonsDiv1 {

public:

    int printSmiles(int smiles) {
        typedef pair<int, int> P;
        int N = 1005;
        vector<vector<int> > dp(2*N, vector<int>(N,INF));
        dp[1][0] = 0;
        queue<P> que;
        que.push(P(1,0));
        while (!que.empty()) {
            P p = que.front();
            que.pop();
            int s = p.first;
            int c = p.second;
            if (s + c < N && dp[s+c][c] >= INF) {
                dp[s+c][c] = dp[s][c] + 1;
                que.push(P(s+c, c));
            }
            if (s < N && dp[s][s] >= INF) {
                dp[s][s] = dp[s][c] + 1;
                que.push(P(s, s));
            }
            if (s - 1 > 0 && dp[s-1][c] >= INF) {
                dp[s-1][c] = dp[s][c] + 1;
                que.push(P(s-1, c));
            }
        }
        int ans = INF;
        for (int i=0; i<N; ++i)
            ans = min(ans, dp[smiles][i]);
        return ans;
    }

    // BEGIN CUT HERE
public:
    void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
private:
    template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
    void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
    void test_case_0() { int Arg0 = 2; int Arg1 = 2; verify_case(0, Arg1, printSmiles(Arg0)); }
    void test_case_1() { int Arg0 = 4; int Arg1 = 4; verify_case(1, Arg1, printSmiles(Arg0)); }
    void test_case_2() { int Arg0 = 6; int Arg1 = 5; verify_case(2, Arg1, printSmiles(Arg0)); }
    void test_case_3() { int Arg0 = 18; int Arg1 = 8; verify_case(3, Arg1, printSmiles(Arg0)); }
    void test_case_4() { int Arg0 = 11; int Arg1 = 8; verify_case(4, Arg1, printSmiles(Arg0)); }

    // END CUT HERE


};



// BEGIN CUT HERE

int main() {

    EmoticonsDiv1 ___test;

    ___test.run_test(-1);

}

// END CUT HERE

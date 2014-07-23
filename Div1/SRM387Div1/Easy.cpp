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

class MarblesRegroupingEasy {

public:

    int count(int joker, vector<string> &boxes) {
        bool active[55];
        memset(active, true, sizeof(active));
        active[joker] = false;

        int N = (int)boxes.size();
        int M = (int)boxes[0].size();
        for (int i=0; i<N; ++i) if (active[i]) {
            int c = 0;
            for (int j=0; j<M; ++j) {
                if (boxes[i][j] != '0') {
                    ++c;
                }
            }
            if (c > 1)
                active[i] = false;
        }

        for (int j=0; j<M; ++j) {
            bool fill = false;
            for (int i=0; i<N; ++i) if (active[i]) {
                if (boxes[i][j] != '0') {
                    if (fill) active[i] = false;
                    fill = true;
                }
            }
        }

        int res = -1;
        for (int i=0; i<N; ++i) {
            if (!active[i]) {
                ++res;
            }
        }
        return res;
    }

    int minMoves(vector <string> boxes) {
        int ans = INF;
        int N = (int)boxes.size();
        for (int joker=0; joker<N; ++joker) {
            ans = min(ans, count(joker, boxes));
        }
        return ans;
    }


    // BEGIN CUT HERE
public:
    void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
private:
    template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
    void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
    void test_case_0() { string Arr0[] = {"20",
        "11"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(0, Arg1, minMoves(Arg0)); }
    void test_case_1() { string Arr0[] = {"11",
        "11",
        "10"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(1, Arg1, minMoves(Arg0)); }
    void test_case_2() { string Arr0[] = {"10",
        "10",
        "01",
        "01"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(2, Arg1, minMoves(Arg0)); }
    void test_case_3() { string Arr0[] = {"11",
        "11",
        "11",
        "10",
        "10",
        "01"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(3, Arg1, minMoves(Arg0)); }
    void test_case_4() { string Arr0[] = {"020008000070",
        "000004000000",
        "060000600000",
        "006000000362",
        "000720000000",
        "000040000000",
        "004009003000",
        "000800000000",
        "020030003000",
        "000500200000",
        "000000300000"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 6; verify_case(4, Arg1, minMoves(Arg0)); }

    // END CUT HERE


};



// BEGIN CUT HERE

int main() {

    MarblesRegroupingEasy ___test;

    ___test.run_test(-1);

}

// END CUT HERE

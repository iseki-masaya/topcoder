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

const long long LINF = (1e18);
const int INF = (1<<28);
const int sINF = (1<<23);
const int MOD = 1000000007;
const double EPS = 1e-6;

using namespace std;

class UniformBoard {

public:

    int rectangle(vector<vector<int> > &t, int x0, int y0, int x1, int y1) {
        return t[y1][x1] - t[y0][x1] - t[y1][x0] + t[y0][x0];
    }

    int getBoard(vector <string> board, int K) {
        int X = (int)board[0].size();
        int Y = (int)board.size();
        map<char, vector<vector<int> > > t;
        string appear = ".PA";
        for (char ch: appear) {
            vector<vector<int> > c(Y+1, vector<int>(X+1, 0));
            for (int x=1; x<=X; ++x) {
                for (int y=1; y<=Y; ++y) {
                    int v = (board[y-1][x-1] == ch);
                    c[y][x] = v + c[y-1][x] + c[y][x-1] - c[y-1][x-1];
                }
            }
            t[ch] = c;
        }

        int A = rectangle(t['A'], 0, 0, X, Y);
        int E = rectangle(t['.'], 0, 0, X, Y);

        int ans = 0;
        for (int x0=0; x0<=X; ++x0) {
            for (int y0=0; y0<=Y; ++y0) {
                for (int x1=x0+1; x1<=X; ++x1) {
                    for (int y1=y0+1; y1<=Y; ++y1) {
                        int s = (x1 - x0) * (y1 - y0);
                        int p = rectangle(t['P'], x0, y0, x1, y1);
                        int e = rectangle(t['.'], x0, y0, x1, y1);
                        if ( (A >= s) && (p == 0 || E > 0) ) {
                            if (e + 2*p <= K) {
                                ans = max(ans, s);
                            }
                        }
                    }
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
    void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
    void test_case_0() { string Arr0[] = {"AP",
        ".A"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; int Arg2 = 1; verify_case(0, Arg2, getBoard(Arg0, Arg1)); }
    void test_case_1() { string Arr0[] = {"AP",
        ".A"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = 2; verify_case(1, Arg2, getBoard(Arg0, Arg1)); }
    void test_case_2() { string Arr0[] = {"PPP",
        "APA",
        "A.P"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; int Arg2 = 3; verify_case(2, Arg2, getBoard(Arg0, Arg1)); }
    void test_case_3() { string Arr0[] = {"AAA",
        "PPP",
        "AAA"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 10; int Arg2 = 3; verify_case(3, Arg2, getBoard(Arg0, Arg1)); }
    void test_case_4() { string Arr0[] = {"."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1000; int Arg2 = 0; verify_case(4, Arg2, getBoard(Arg0, Arg1)); }
    void test_case_5() { string Arr0[] = {"PPAAPA..AP",
        "PPA.APAP..",
        "..P.AA.PPP",
        "P.P..APAA.",
        "P.P..P.APA",
        "PPA..AP.AA",
        "APP..AAPAA",
        "P.P.AP...P",
        ".P.A.PAPPA",
        "..PAPAP..P"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 10; int Arg2 = 15; verify_case(5, Arg2, getBoard(Arg0, Arg1)); }

    // END CUT HERE


};



// BEGIN CUT HERE

int main() {

    UniformBoard ___test;

    ___test.run_test(-1);

}

// END CUT HERE

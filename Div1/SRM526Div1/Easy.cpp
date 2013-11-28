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
#include <stdio.h>
#include <string.h>
#include <numeric>

#define INF (1<<28)
#define MOD (1000000007)

using namespace std;

class DucksAlignment {

public:
    int calc(vector<string> &grid,int cx,int cy) {
        int Y = (int)grid.size();
        int X = (int)grid[0].size();

        int res = INF;
        for (int loop=0; loop<2; ++loop) {
            int N = loop ? Y : X;
            vector<bool> used(N,false);

            int shift = 0;
            for (int x=0; x<X; ++x) {
                for (int y=0; y<Y; ++y) {
                    if (grid[y][x] == 'o') {
                        shift += loop ? abs(cx - x) : abs(cy - y);
                        int n = loop ? y : x;
                        used[n] = true;
                    }
                }
            }

            int fill = 0;
            int p = loop ? cy : cx;
            int left = used[p] ? 1 : 0;
            for (int l=0; l<p; ++l)
                if (used[l])
                    fill += (p-l) - left , ++left;
            int right = left ? 1 : 0;
            for (int r=p+1; r<N; ++r)
                if (used[r])
                    fill += (r-p) - right , ++right;

            res = min(res, shift + fill);
        }

        return res;
    }

    int minimumTime(vector <string> grid) {
        int ans = INF;
        int Y = (int)grid.size();
        int X = (int)grid[0].size();

        for (int x=0; x<X; ++x)
            for (int y=0; y<Y; ++y)
                ans = min(ans, calc(grid, x, y));

        return ans;
    }


    // BEGIN CUT HERE
public:
    void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
private:
    template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
    void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
    void test_case_0() { string Arr0[] = {".o",
        "o."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(0, Arg1, minimumTime(Arg0)); }
    void test_case_1() { string Arr0[] = {".o...",
        "..o..",
        "....o"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(1, Arg1, minimumTime(Arg0)); }
    void test_case_2() { string Arr0[] = {"o..........",
        "..o........",
        ".......o...",
        "...........",
        "...........",
        "...........",
        "........o..",
        "..........."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 16; verify_case(2, Arg1, minimumTime(Arg0)); }
    void test_case_3() { string Arr0[] = {".........",
        "....o....",
        "........."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(3, Arg1, minimumTime(Arg0)); }
    void test_case_4() { string Arr0[] = {"...o..........................",
        "............................o.",
        ".o............................",
        "............o.................",
        ".................o............",
        "......................o.......",
        "......o.......................",
        "....o.........................",
        "...............o..............",
        ".......................o......",
        "...........................o..",
        ".......o......................"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 99; verify_case(4, Arg1, minimumTime(Arg0)); }

    // END CUT HERE


};



// BEGIN CUT HERE

int main() {

    DucksAlignment ___test;

    ___test.run_test(-1);

}

// END CUT HERE

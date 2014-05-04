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

#include <random>

const long long LINF = (1e15);
const int INF = (1<<27);
#define EPS 1e-6
const int MOD = 1000000007;

using namespace std;

class UnfoldingTriangles {

public:
    vector<string> g;
    int u;

    bool isTriangle(int x,int y,int cx,int cy) {
        int c = 0;
        for (int ny=y+1,k=1; ny<=cy; ++ny,++k) {
            for (int nx=x,t=0; t<k; --nx,++t) {
                if (g[ny][nx] == '.')
                    return false;
                if (g[ny][nx] == '/')
                    ++c;
            }
        }
        return c <= u;
    }

    bool isolate(int x,int y,int cx,int cy) {
        int Y = (int)g.size();
        int X = (int)g[0].size();
        for (int ny=y; ny<=cy && x+1 < X; ++ny) {
            if (g[ny][x+1] == '#') {
                return false;
            }
        }
        for (int nx=x; nx>=cx && cy+1 < Y; --nx) {
            if (g[cy+1][nx] == '#') {
                return false;
            }
        }
        return true;
    }

    int solve(vector <string> grid, int unfoldLimit) {
        this->g = grid;
        this->u = unfoldLimit;

        int ans = -1;
        int Y = (int)grid.size();
        int X = (int)grid[0].size();
        for (int y=0; y<Y; ++y) {
            for (int x=0; x<X; ++x) {
                if (grid[y][x] == '/') {
                    for (int cx=x,cy=y; cx>=0 && cy<Y && grid[cy][cx] == '/' && isTriangle(x, y, cx, cy); --cx,++cy) {
                        if (!isolate(x,y,cx,cy))
                            continue;

                        int n = abs(cy-y) + 1;
                        ans = max(ans, n*(n+1)/2);
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
    void test_case_0() { string Arr0[] = {".../",
        "../#",
        "./#/",
        "/#//"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; int Arg2 = 10; verify_case(0, Arg2, solve(Arg0, Arg1)); }
    void test_case_1() { string Arr0[] = {".../",
        "../#",
        "./#/",
        "/#//"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; int Arg2 = 3; verify_case(1, Arg2, solve(Arg0, Arg1)); }
    void test_case_2() { string Arr0[] = {"////",
        "////",
        "////",
        "////"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; int Arg2 = 6; verify_case(2, Arg2, solve(Arg0, Arg1)); }
    void test_case_3() { string Arr0[] = {".....#...",
        "....###.."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 10; int Arg2 = -1; verify_case(3, Arg2, solve(Arg0, Arg1)); }
    void test_case_4() { string Arr0[] = {"#//#",
        "#//#",
        "####",
        "///#"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; int Arg2 = 1; verify_case(4, Arg2, solve(Arg0, Arg1)); }
    void test_case_5() { string Arr0[] = {".../.../",
        "../#..//",
        "./.#.///",
        "/###...."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; int Arg2 = 6; verify_case(5, Arg2, solve(Arg0, Arg1)); }

    // END CUT HERE


};



// BEGIN CUT HERE

int main() {

    UnfoldingTriangles ___test;

    ___test.run_test(-1);

}

// END CUT HERE

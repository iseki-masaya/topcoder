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

const long long LINF = (1e15);
const int INF = (1<<27);
#define EPS 1e-6
const int MOD = 1000000007;

using namespace std;

bool rect[55][55][55][55];
int t[55][55][55][55];


class DonutsOnTheGridEasy {

public:
    int rec(int a,int b,int c,int d) {
        if (a > c || b > d) {
            return 0;
        }
        if (t[a][b][c][d] != -1) {
            return t[a][b][c][d];
        }

        int mx = 0;
        mx = max(mx, rec(a+1, b, c, d));
        mx = max(mx, rec(a, b+1, c, d));
        mx = max(mx, rec(a, b, c-1, d));
        mx = max(mx, rec(a, b, c, d-1));
        if (rect[a][b][c][d]) {
            mx = max(mx, rec(a+1, b+1, c-1, d-1) + 1);
        }
        return t[a][b][c][d] = mx;
    }

    int calc(vector <string> grid) {
        int Y = (int)grid.size();
        int X = (int)grid[0].size();

        memset(t, -1, sizeof(t));
        memset(rect, false, sizeof(rect));

        for (int i=0; i<X; ++i) {
            for (int j=0; j<Y; ++j) {
                for (int k=i+2; k<X; ++k) {
                    for (int l=j+2; l<Y; ++l) {
                        bool flag = true;
                        for (int m=i; m<=k && flag; ++m) {
                            flag = grid[j][m] == '0' && grid[l][m] == '0';
                        }
                        if (!flag) {
                            continue;
                        }
                        for (int m=j; m<=l && flag; ++m) {
                            flag = grid[m][i] == '0' && grid[m][k] == '0';
                        }
                        if (!flag) {
                            continue;
                        }
                        rect[i][j][k][l] = true;
                    }
                }
            }
        }

        return rec(0,0,X-1,Y-1);
    }


    // BEGIN CUT HERE
public:
    void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
private:
    template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
    void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
    void test_case_0() { string Arr0[] = {"0000000"
        ,"0.....0"
        ,"0.00000"
        ,"0.0..00"
        ,"0.00000"
        ,"0.....0"
        ,"0000000"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(0, Arg1, calc(Arg0)); }
    void test_case_1() { string Arr0[] = {"000"
        ,"0.0"
        ,"000"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(1, Arg1, calc(Arg0)); }
    void test_case_2() { string Arr0[] = {"..."
        ,"..."
        ,"..."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(2, Arg1, calc(Arg0)); }
    void test_case_3() { string Arr0[] = {"00.000"
        ,"00.000"
        ,"0.00.0"
        ,"000.00"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(3, Arg1, calc(Arg0)); }
    void test_case_4() { string Arr0[] =
        {"000000", "000000", "0000.0", "000000"}
        ; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(4, Arg1, calc(Arg0)); }

    // END CUT HERE


};



// BEGIN CUT HERE

int main() {

    DonutsOnTheGridEasy ___test;

    ___test.run_test(-1);

}

// END CUT HERE

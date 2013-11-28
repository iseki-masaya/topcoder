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
const int INF = (1<<30);
#define EPS 1e-6

using namespace std;

class DropCoins {

public:
    int count(vector<string> &b,int l,int r,int d,int u) {
        int res = 0;
        for (int x=l; x<r; ++x)
            for (int y=d; y<u; ++y)
                if (b[y][x] == 'o')
                    res++;
        return res;
    }

    int getMinimum(vector <string> board, int K) {
        int Y = (int)board.size();
        int X = (int)board[0].size();

        int ans = INF;
        for (int l=0; l<X; ++l)
            for (int r=X; r>l; --r)
                for (int d=0; d<Y; ++d)
                    for (int u=Y; u>d; --u)
                        if (K == count(board, l, r, d, u))
                            ans = min(ans, l+d+(X-r)+(Y-u)+min(l,X-r)+min(d,Y-u));

        return ans == INF ? -1 : ans;
    }


    // BEGIN CUT HERE
public:
    void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
private:
    template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
    void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
    void test_case_0() { string Arr0[] = {".o.."
        ,"oooo"
        ,"..o."}
        ; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; int Arg2 = 2; verify_case(0, Arg2, getMinimum(Arg0, Arg1)); }
    void test_case_1() { string Arr0[] = {".....o"
        ,"......"
        ,"oooooo"
        ,"oooooo"
        ,"......"
        ,"o....."}
        ; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 12; int Arg2 = 3; verify_case(1, Arg2, getMinimum(Arg0, Arg1)); }
    void test_case_2() { string Arr0[] = {"...."
        ,".oo."
        ,".oo."
        ,"...."}
        ; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; int Arg2 = -1; verify_case(2, Arg2, getMinimum(Arg0, Arg1)); }
    void test_case_3() { string Arr0[] = {"......."
        ,"..ooo.."
        ,"ooooooo"
        ,".oo.oo."
        ,"oo...oo"}
        ; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 12; int Arg2 = 4; verify_case(3, Arg2, getMinimum(Arg0, Arg1)); }
    void test_case_4() { string Arr0[] = {"................."
        ,".ooooooo...oooo.."
        ,".ooooooo..oooooo."
        ,".oo.......oo..oo."
        ,".oo.......oo..oo."
        ,".ooooo.....oooo.."
        ,".ooooooo...oooo.."
        ,".....ooo..oo..oo."
        ,"......oo..oo..oo."
        ,".ooooooo..oooooo."
        ,".oooooo....oooo.."
        ,"................."}
        ; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 58; int Arg2 = 6; verify_case(4, Arg2, getMinimum(Arg0, Arg1)); }

    // END CUT HERE


};



// BEGIN CUT HERE

int main() {

    DropCoins ___test;

    ___test.run_test(-1);

}

// END CUT HERE

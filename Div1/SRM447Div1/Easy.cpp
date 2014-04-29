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

int dy[] = {-2,-2,-1,-1,1,1,2,2};
int dx[] = {-1,1,-2,2,-2,2,-1,1};

class KnightsTour {

public:
    vector<string> b;

    int count(int x, int y) {
        int res = 0;
        for (int i=0; i<8; ++i) {
            int cx = x + dx[i];
            int cy = y + dy[i];
            if (0 <= cx && cx < 8 && 0 <= cy && cy < 8 && b[cy][cx] == '.') {
                ++res;
            }
        }
        return res;
    }

    int dfs(int x, int y, int s) {
        int mn = 10 , p = -1;
        for (int i=0; i<8; ++i) {
            int cx = x + dx[i];
            int cy = y + dy[i];
            if (0 <= cx && cx < 8 && 0 <= cy && cy < 8 && b[cy][cx] == '.') {
                int t = count(cx, cy);
                if ( mn > t ) {
                    mn = t;
                    p = i;
                }
            }
        }
        if (mn != 10) {
            int cx = x + dx[p];
            int cy = y + dy[p];
            b[cy][cx] = '*';
            return dfs(cx, cy, s + 1);
        }
        return s;
    }

    int visitedPositions(vector <string> board) {
        this->b = board;
        const int X = 8;
        const int Y = 8;
        for (int x=0; x<X; ++x) {
            for (int y=0; y<Y; ++y) {
                if (board[y][x] == 'K') {
                    b[y][x] = '*';
                    return dfs(x,y,1);
                }
            }
        }
        return -1;
    }


    // BEGIN CUT HERE
public:
    void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
private:
    template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
    void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
    void test_case_0() { string Arr0[] = {"........"
        ,".*.*...."
        ,".*......"
        ,"..K...*."
        ,"*...*..."
        ,"...*...."
        ,"...*.*.."
        ,"........"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 39; verify_case(0, Arg1, visitedPositions(Arg0)); }
    void test_case_1() { string Arr0[] = {"K......."
        ,"........"
        ,"........"
        ,"........"
        ,"........"
        ,"........"
        ,"........"
        ,"........"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 64; verify_case(1, Arg1, visitedPositions(Arg0)); }
    void test_case_2() { string Arr0[] = {"********"
        ,"*******."
        ,"********"
        ,"**.***.*"
        ,"********"
        ,"***.*.**"
        ,"********"
        ,"****K***"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(2, Arg1, visitedPositions(Arg0)); }
    void test_case_3() { string Arr0[] = {"*.*....*"
        ,".......*"
        ,"**...*.."
        ,"..***..."
        ,".**.*..."
        ,"..*.*..K"
        ,"..***.*."
        ,"**...*.."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 17; verify_case(3, Arg1, visitedPositions(Arg0)); }
    void test_case_4() { string Arr0[] = {"..*...*."
        ,"**.....*"
        ,"*..*...."
        ,"*..*...."
        ,".....*.."
        ,"....*..K"
        ,"**.*...*"
        ,"..**...."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 27; verify_case(4, Arg1, visitedPositions(Arg0)); }

    // END CUT HERE


};



// BEGIN CUT HERE

int main() {

    KnightsTour ___test;

    ___test.run_test(-1);

}

// END CUT HERE

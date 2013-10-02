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
#include <time.h>

using namespace std;

#define MAX_X 55
#define MAX_Y 55

bool used[MAX_Y][MAX_X];
int X,Y;
int coin_x,coin_y;
vector<string> l;
const int dx[] = {1,-1};

typedef pair<int, int> P;

class ArcadeManao {

public:
    bool
    canReach(int len)
    {
        queue<P> que;
        que.push(P(coin_x,coin_y));
        used[coin_y][coin_x] = true;
        while (!que.empty()) {
            P p = que.front();
            que.pop();
            if (p.second == Y-1) {
                return true;
            }
            for (int cy = p.second-len; cy <= p.second+len; ++cy) {
                if (0 <= cy && cy < Y && l[cy][p.first] == 'X' && !used[cy][p.first]) {
                    used[cy][p.first] = true;
                    que.push(P(p.first,cy));
                }
            }
            for (int i=0; i<2; ++i) {
                int cx = p.first + dx[i];
                if (0 <= cx && cx < X && l[p.second][cx] == 'X' && !used[p.second][cx]) {
                    used[p.second][cx] = true;
                    que.push(P(cx,p.second));
                }
            }
        }
        return false;
    }

    int
    shortestLadder(vector <string> level, int coinRow, int coinColumn)
    {
        if ((level.size()==1 && level[0].size()==1) || coinRow==level.size()) {
            return 0;
        }

        coin_y = coinRow-1;
        coin_x = coinColumn-1;
        X = (int)level[0].size();
        Y = (int)level.size();
        l = level;
        int lb = 0 , ub = 55 , mid;
        while (ub - lb > 1) {
            //      for (int i=0;i<100;++i) {
            memset(used, false, sizeof(used));
            mid = (ub+lb)/2;
            if (canReach(mid)) {
                ub = mid;
            }
            else {
                lb = mid;
            }
        }
        return ub;
    }


    // BEGIN CUT HERE
public:
    void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4();if ((Case == -1) || (Case == 5)) test_case_5(); }
private:
    template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
    void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
    void test_case_0() { string Arr0[] = {"XXXX....",
        "...X.XXX",
        "XXX..X..",
        "......X.",
        "XXXXXXXX"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; int Arg2 = 4; int Arg3 = 2; verify_case(0, Arg3, shortestLadder(Arg0, Arg1, Arg2)); }
    void test_case_1() { string Arr0[] = {"XXXX",
        "...X",
        "XXXX"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = 1; int Arg3 = 1; verify_case(1, Arg3, shortestLadder(Arg0, Arg1, Arg2)); }
    void test_case_2() { string Arr0[] = {"..X..",
        ".X.X.",
        "X...X",
        ".X.X.",
        "..X..",
        "XXXXX"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = 3; int Arg3 = 4; verify_case(2, Arg3, shortestLadder(Arg0, Arg1, Arg2)); }
    void test_case_3() { string Arr0[] = {"X"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = 1; int Arg3 = 0; verify_case(3, Arg3, shortestLadder(Arg0, Arg1, Arg2)); }
    void test_case_4() { string Arr0[] = {"XXXXXXXXXX",
        "...X......",
        "XXX.......",
        "X.....XXXX",
        "..XXXXX..X",
        ".........X",
        ".........X",
        "XXXXXXXXXX"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = 1; int Arg3 = 2; verify_case(4, Arg3, shortestLadder(Arg0, Arg1, Arg2)); }
    void test_case_5() { string Arr0[] = {"XXXXX.XXXXXXX.X..X.XX.XX.XX.XX.XX.X..X.", "..XX..XX.X...XXX.XX...XX.XX..XX..XX.XXX", "X.X....X.XXXXX...X.XXXX...X.X..XX...XXX", ".....X.X..X.X.XXX.XXXXX.X.X...XX.X.....", ".X.X.XX..X.X..XX..XXX..X....X.X.XX...X.", ".......X.XXX.....X..X.X.XXX..X...XXXX.X", ".X.....XXXX.XX.XXX...XXX..XX..XX.XXXX.X", "X....X.XXX..XX..XX.X.X...XX......X...XX", ".X..X.XXXX..X..X.....X....X...XX.X..X.X", "X.....X.X..XXXXX.XX..X....X..X.X.X...X.", "XXX.XX.XXXXX...XXX.XX.XXX..XXXX..XX.XXX", "X..XX.XX.XXXX..XX..XX.XX..X..X.XXXX.X.X", "X.X..XXX..X.X..XX..X..XX..X..X..X.XX..X", "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX"};vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 8; int Arg2 = 22; int Arg3 = 3; verify_case(0, Arg3, shortestLadder(Arg0, Arg1, Arg2)); }
    // END CUT HERE


};



// BEGIN CUT HERE

int main() {

    ArcadeManao ___test;

    ___test.run_test(-1);

}

// END CUT HERE

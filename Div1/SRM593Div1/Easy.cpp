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

int dx[6] = {-1,-1,0,0,1,1};
int dy[6] = {0,1,1,-1,-1,0};

class HexagonalBoard {

public:
    vector<string> b;
    int color[55][55];
    int N;

    int dfs(int x,int y,int c) {
        int res = 1;
        if (color[y][x] == 0) {
            color[y][x] = c;
            for (int i=0; i<6; ++i) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (0 <= nx && nx < N && 0 <= ny && ny < N && b[ny][nx] == 'X') {
                    res = max(res, 2);
                    res = max(res, dfs(nx, ny, -c));
                    if (color[ny][nx] == c)
                        res = 3;
                }
            }
        }
        return res;
    }

    int minColors(vector <string> board) {
        memset(color, 0, sizeof(color));
        int res = 0;
        this->b = board;
        N = (int)b.size();
        for (int y=0; y<N; ++y) {
            for (int x=0; x<N; ++x) {
                if (board[y][x] == 'X' && color[y][x] == 0) {
                    res = max(res, dfs(x, y, 1));
                }
            }
        }
        return res;
    }


    // BEGIN CUT HERE
public:
    void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
private:
    template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
    void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
    void test_case_0() { string Arr0[] = {"---",
        "---",
        "---"}
        ; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(0, Arg1, minColors(Arg0)); }
    void test_case_1() { string Arr0[] = {"-X--",
        "---X",
        "----",
        "-X--"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(1, Arg1, minColors(Arg0)); }
    void test_case_2() { string Arr0[] = {"XXXX",
        "---X",
        "---X",
        "---X"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(2, Arg1, minColors(Arg0)); }
    void test_case_3() { string Arr0[] = {"XX-XX--"
        ,"-XX-XXX"
        ,"X-XX--X"
        ,"X--X-X-"
        ,"XX-X-XX"
        ,"-X-XX-X"
        ,"-XX-XX-"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(3, Arg1, minColors(Arg0)); }

    // END CUT HERE


};



// BEGIN CUT HERE

int main() {

    HexagonalBoard ___test;

    ___test.run_test(-1);

}

// END CUT HERE

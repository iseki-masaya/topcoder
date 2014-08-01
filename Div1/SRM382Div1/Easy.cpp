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

const long long LINF = (1e18);
const int INF = (1<<28);
const int sINF = (1<<23);
#define EPS 1e-6
const int MOD = 1000000007;

using namespace std;

class CollectingRiders {

public:
    vector<string> b;
    const int dx[8] = {2, 1, -1, -2, -2, -1, 1, 2};
    const int dy[8] = {1, 2 , 2, 1, -1, -2, -2, -1};

    int search(int K, int cx, int cy, int gx, int gy) {
        int Y = (int)b.size();
        int X = (int)b[0].size();
        bool used[55][55];
        memset(used, false, sizeof(used));
        typedef pair<int, int> P;
        typedef pair<P, int> T;
        queue<T> que;
        que.push(T(P(cx,cy), 0));

        while (!que.empty()) {
            T t = que.front();
            que.pop();
            P p = t.first;
            int px = p.first;
            int py = p.second;
            int c = t.second;
            if (px == gx && py == gy)
                return c/K + (c%K !=0 ? 1 : 0);
            for (int i=0; i<8; ++i) {
                int x = px + dx[i];
                int y = py + dy[i];
                if (0 <= x && x < X && 0 <= y && y < Y && !used[y][x]) {
                    used[y][x] = true;
                    que.push(T(P(x,y), c+1));
                }
            }
        }
        return sINF;
    }

    int count(int gx, int gy) {
        int Y = (int)b.size();
        int X = (int)b[0].size();
        int res = 0;
        for (int x=0; x<X; ++x) {
            for (int y=0; y<Y; ++y) if (b[y][x] != '.') {
                res += search(b[y][x]-'0', x, y, gx, gy);
            }
        }
        return res;
    }

    int minimalMoves(vector <string> board) {
        this->b = board;
        int ans = sINF;
        int Y = (int)board.size();
        int X = (int)board[0].size();
        for (int x=0; x<X; ++x) {
            for (int y=0; y<Y; ++y) {
                ans = min(ans, count(x,y));
            }
        }
        return ans == sINF ? -1 : ans;
    }


    // BEGIN CUT HERE
public:
    void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
private:
    template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
    void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
    void test_case_0() { string Arr0[] = {"...1",
        "....",
        "2..."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(0, Arg1, minimalMoves(Arg0)); }
    void test_case_1() { string Arr0[] = {"........",
        ".1......",
        "........",
        "....3...",
        "........",
        "........",
        ".7......",
        "........"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(1, Arg1, minimalMoves(Arg0)); }
    void test_case_2() { string Arr0[] = {"..",
        "2.",
        ".."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(2, Arg1, minimalMoves(Arg0)); }
    void test_case_3() { string Arr0[] = {".1....1."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = -1; verify_case(3, Arg1, minimalMoves(Arg0)); }
    void test_case_4() { string Arr0[] = {"9133632343",
        "5286698232",
        "8329333369",
        "5425579782",
        "4465864375",
        "8192124686",
        "3191624314",
        "5198496853",
        "1638163997",
        "6457337215"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 121; verify_case(4, Arg1, minimalMoves(Arg0)); }

    // END CUT HERE


};



// BEGIN CUT HERE

int main() {

    CollectingRiders ___test;

    ___test.run_test(-1);

}

// END CUT HERE

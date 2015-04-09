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
#include <memory>

const long long LINF = (5e18);
const int INF = (1<<30);
#define EPS 1e-6
const int MOD = 1000000007;

using namespace std;

class PathGame {

public:

    int memo[1005][4][4];

    // 1: up
    // 2: down
    // 3: none
    int getGrundy(int len, int l, int r) {
        if (memo[len][l][r] != -1)
            return memo[len][l][r];
        if (len == 1 && l&r)
            return memo[len][l][r] = 1;
        if (len <= 1)
            return memo[len][l][r] = 0;
        set<int> s;
        if (l!=2) s.insert(getGrundy(len-1, 1, r));
        if (l!=1) s.insert(getGrundy(len-1, 2, r));
        if (r!=2) s.insert(getGrundy(len-1, l, 1));
        if (r!=1) s.insert(getGrundy(len-1, l, 2));

        for (int i=1; i<len-1; ++i) {
            s.insert(getGrundy(i, l, 1) ^ getGrundy(len-i-1, 1, r));
            s.insert(getGrundy(i, l, 2) ^ getGrundy(len-i-1, 2, r));
        }
        int res = 0;
        while (s.count(res)) ++res;
        return memo[len][l][r] = res;
    }

    string judge(vector <string> board) {
        board[0].push_back('*');
        board[1].push_back('*');
        memset(memo, -1, sizeof(memo));
        int w = (int)board[0].size();
        int len = 0;
        int leftState = 3;
        int grundy = 0;
        for (int i=0; i<w; ++i) {
            if (board[0][i] != '.' || board[1][i] != '.') {
                int rightState;
                if (board[0][i] == '#')
                    rightState = 1;
                else if (board[1][i] == '#')
                    rightState = 2;
                else
                    rightState = 3;
                grundy ^= getGrundy(len, leftState, rightState);
                leftState = rightState;
                len = 0;
            } else {
                ++len;
            }
        }
        return grundy != 0 ? "Snuke" : "Sothe";
    }


    // BEGIN CUT HERE
public:
    void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
private:
    template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
    void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
    void test_case_0() { string Arr0[] = {"#.."
        ,"..."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Snuke"; verify_case(0, Arg1, judge(Arg0)); }
    void test_case_1() { string Arr0[] = {"#"
        ,"."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Sothe"; verify_case(1, Arg1, judge(Arg0)); }
    void test_case_2() { string Arr0[] = {"....."
        ,"..#.."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Sothe"; verify_case(2, Arg1, judge(Arg0)); }
    void test_case_3() { string Arr0[] = {".#..."
        ,"....."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Snuke"; verify_case(3, Arg1, judge(Arg0)); }
    void test_case_4() { string Arr0[] = {".....#..#........##......."
        ,"..........#..........#...."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Snuke"; verify_case(4, Arg1, judge(Arg0)); }
    void test_case_5() { string Arr0[] = {".."
        ,".."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Sothe"; verify_case(5, Arg1, judge(Arg0)); }

    // END CUT HERE


};



// BEGIN CUT HERE

int main() {

    PathGame ___test;

    ___test.run_test(-1);

}

// END CUT HERE

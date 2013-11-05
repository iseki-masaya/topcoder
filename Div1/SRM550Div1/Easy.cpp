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

const int INF = (1<<30);
#define EPS 1e-8
const int MOD = 10007;

using namespace std;

#define O 10000

int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};

class RotatingBot {

public:

    int
    minArea(vector <int> moves)
    {
        int x = O, y = O;
        // 0:right 1:upper 2:left 3:lower
        int bound[] = {-1,O,-1,-1};
        int mnx = x , mxx = x;
        int mny = y , mxy = y;
        for (int i=0; i<moves.size(); ++i) {
            for (int j=0; j<moves[i]; ++j) {
                x += dx[i%4];
                y += dy[i%4];
                if (x == O && y == O) {
                    return -1;
                }
            }
            mnx = min(mnx, x);
            mxx = max(mxx, x);
            mny = min(mny, y);
            mxy = max(mxy, y);
            if (bound[i%4] == -1) {
                bound[i%4] = i&1 ? y : x;
            }
            if (i != 1 && i + 1 != moves.size() && bound[i%4] != (i&1 ? y : x)) {
                return -1;
            }
            if (i + 1 == moves.size() && i > 3) {
                int v = i&1 ? y : x;
                int b = bound[i%4];
                if (i%4 < 2 && b < v)
                    return -1;
                if (i%4 > 1 && v < b)
                    return -1;
            }
            if (i == 2 && i + 1 != moves.size() && x > O) {
                return -1;
            }
            if (i == 3 && i + 1 != moves.size() && y > O + 1) {
                return -1;
            }
            if (i == 3 && i + 1 != moves.size() && y > O && x != O) {
                return -1;
            }
            if (i == 3 && y > O) {
                bound[1] = mxy - 1;
                bound[0]--;
            }
            else if (i == 3 && y == O) {
                bound[1] = mxy - 1;
                bound[0] = O-1;
            }
            if (i > 0) {
                bound[i%4] += i%4 > 1 ? 1 : -1;
            }
        }
        return (mxx-mnx+1)*(mxy-mny+1);
    }


    // BEGIN CUT HERE
public:
    void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); if ((Case == -1) || (Case == 7)) test_case_7();if ((Case == -1) || (Case == 8)) test_case_8();if ((Case == -1) || (Case == 9)) test_case_9();if ((Case == -1) || (Case == 10)) test_case_10(); }
private:
    template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
    void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
    void test_case_0() { int Arr0[] = {15}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 16; verify_case(0, Arg1, minArea(Arg0)); }
    void test_case_1() { int Arr0[] = {3,10}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 44; verify_case(1, Arg1, minArea(Arg0)); }
    void test_case_2() { int Arr0[] = {1,1,1,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = -1; verify_case(2, Arg1, minArea(Arg0)); }
    void test_case_3() { int Arr0[] = {9,5,11,10,11,4,10}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 132; verify_case(3, Arg1, minArea(Arg0)); }
    void test_case_4() { int Arr0[] = {12,1,27,14,27,12,26,11,25,10,24,9,23,8,22,7,21,6,20,5,19,4,18,3,17,2,16,1,15}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 420; verify_case(4, Arg1, minArea(Arg0)); }
    void test_case_5() { int Arr0[] = {8,6,6,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = -1; verify_case(5, Arg1, minArea(Arg0)); }
    void test_case_6() { int Arr0[] = {8,6,6}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 63; verify_case(6, Arg1, minArea(Arg0)); }
    void test_case_7() { int Arr0[] = {5,4,5,3,3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 30; verify_case(7, Arg1, minArea(Arg0)); }
    void test_case_8() { int Arr0[] = {6, 9, 15, 14, 15, 4, 14, 3, 13, 2, 12, 1, 12}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = -1; verify_case(8, Arg1, minArea(Arg0)); }
    void test_case_9() { int Arr0[] = {4, 5, 4, 4, 3, 2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 30; verify_case(9, Arg1, minArea(Arg0)); }
    void test_case_10() { int Arr0[] = {2, 2, 3, 1, 1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = -1; verify_case(10, Arg1, minArea(Arg0)); }

    // END CUT HERE
};



// BEGIN CUT HERE

int main() {

    RotatingBot ___test;

    ___test.run_test(10);

}

// END CUT HERE

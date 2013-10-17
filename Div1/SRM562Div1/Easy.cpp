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

#define INF (1<<28)
#define EPS 1e-8

using namespace std;

class PastingPaintingDivOne {

public:
    int
    conv(char ch)
    {
        if (ch == 'R')  return 1;
        if (ch == 'G')  return 2;
        if (ch == 'B')  return 3;
        return 0;
    }

    void
    fill(vector<vector<int> > &m,vector<string> &clipboard,int offset)
    {
        int X = (int)clipboard[0].size();
        int Y = (int)clipboard.size();
        for (int y=offset; y<Y+offset; ++y) {
            for (int x=offset; x<X+offset; ++x) {
                if (clipboard[y-offset][x-offset] != '.') {
                    m[y][x] = conv(clipboard[y-offset][x-offset]);
                }
            }
        }
    }

    void
    count(vector<vector<int> > &m,vector<long long> &a)
    {
        int Y = (int)m.size();
        int X = (int)m[0].size();
        for (int y=0; y<Y; ++y) {
            for (int x=0; x<X; ++x) {
                if (m[y][x] > 0) {
                    a[m[y][x]-1]++;
                }
            }
        }
    }

    vector<long long>
    countColors(vector <string> clipboard, int T)
    {
        int F = (int)min(clipboard[0].size(),clipboard.size());
        F = min(F, T);
        vector<vector<int> > m(clipboard.size()+F+1,vector<int>(clipboard[0].size()+F+1,0));
        // R:1 G:2 B:3
        for (int f=0; f<F; ++f) {
            fill(m, clipboard, f);
        }
        vector<long long> ans(3,0);
        count(m, ans);
        if (F == T) {
            return ans;
        }
        fill(m, clipboard, F);
        vector<long long> c_ans(3,0);
        count(m, c_ans);
        vector<long long> d_ans(3,0);
        for (int i=0; i<3; ++i) {
            d_ans[i] = c_ans[i] - (int)ans[i];
            ans[i] += (long long)(T-F)*d_ans[i];
        }
        return ans;
    }


    // BEGIN CUT HERE
public:
    void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
private:
    template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
    void verify_case(int Case, const vector<long long> &Expected, const vector<long long> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
    void test_case_0() { string Arr0[] = {
        "..G",
        "R..",
        "BG."
    }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; long Arr2[] = {3, 4, 3 }; vector<long long> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(0, Arg2, countColors(Arg0, Arg1)); }
    void test_case_1() { string Arr0[] = {
        "R...",
        "....",
        "....",
        "...R"
    }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; long Arr2[] = {4, 0, 0 }; vector<long long> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(1, Arg2, countColors(Arg0, Arg1)); }
    void test_case_2() { string Arr0[] = {"RGB"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 100000; long Arr2[] = {100000, 100000, 100000 }; vector<long long> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(2, Arg2, countColors(Arg0, Arg1)); }
    void test_case_3() { string Arr0[] = {"."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1000000000; long Arr2[] = {0, 0, 0 }; vector<long long> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(3, Arg2, countColors(Arg0, Arg1)); }
    void test_case_4() { string Arr0[] = {
        "RB.",
        ".G."
    }
        ; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 100; long Arr2[] = {100, 1, 100 }; vector<long long> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(4, Arg2, countColors(Arg0, Arg1)); }
    void test_case_5() { string Arr0[] = {
        "..........G..........",
        ".........G.G.........",
        "........G...G........",
        ".......G.....G.......",
        "......G..B.B..G......",
        ".....G...B.B...G.....",
        "....G...........G....",
        "...G...R.....R...G...",
        "..G.....RRRRRR....G..",
        ".G..........RR.....G.",
        "GGGGGGGGGGGGGGGGGGGGG"
    }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1000000000; long Arr2[] = {2000000018, 17000000048, 2000000005 }; vector<long long> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(5, Arg2, countColors(Arg0, Arg1)); }

    // END CUT HERE


};



// BEGIN CUT HERE

int main() {

    PastingPaintingDivOne ___test;

    ___test.run_test(-1);

}

// END CUT HERE

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

class ColoredStrokes {

public:

    int draw(int x,int y,vector<string> &picture) {
        int Y = (int)picture.size();
        int X = (int)picture[0].size();
        char ch = picture[y][x];
        picture[y][x] = '.';
        int res = 0;

        if (ch == 'R' || ch == 'G') {
            int cx = x+1;
            while (cx < X && (picture[y][cx] == 'R' || picture[y][cx] == 'G') ) {
                picture[y][cx] = picture[y][cx] == 'R' ? '.' : 'B';
                ++cx;
            }
            ++res;
        }
        if (ch == 'B' || ch == 'G') {
            int cy = y+1;
            while (cy < Y && (picture[cy][x] == 'B' || picture[cy][x] == 'G') ) {
                picture[cy][x] = picture[cy][x] == 'B' ? '.' : 'R';
                ++cy;
            }
            ++res;
        }
        return res;
    }

    int getLeast(vector <string> picture) {
        int ans = 0;
        int Y = (int)picture.size();
        int X = (int)picture[0].size();

        for (int y=0; y<Y; ++y) {
            for (int x=0; x<X; ++x) {
                ans += draw(x,y,picture);
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
    void test_case_0() { string Arr0[] = {"...",
        "..."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(0, Arg1, getLeast(Arg0)); }
    void test_case_1() { string Arr0[] = {"..B.",
        "..B."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(1, Arg1, getLeast(Arg0)); }
    void test_case_2() { string Arr0[] = {".BB."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(2, Arg1, getLeast(Arg0)); }
    void test_case_3() { string Arr0[] = {"...B..",
        ".BRGRR",
        ".B.B.."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(3, Arg1, getLeast(Arg0)); }
    void test_case_4() { string Arr0[] = {"...B..",
        ".BRBRR",
        ".B.B.."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; verify_case(4, Arg1, getLeast(Arg0)); }
    void test_case_5() { string Arr0[] = {"GR",
        "BG"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; verify_case(5, Arg1, getLeast(Arg0)); }

    // END CUT HERE


};



// BEGIN CUT HERE

int main() {

    ColoredStrokes ___test;

    ___test.run_test(-1);

}

// END CUT HERE

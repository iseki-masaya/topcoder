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
#include <numeric>
#include <stdio.h>
#include <string.h>

#define INF (1<<30)
#define LINF (5e18)

using namespace std;

typedef pair<int, int> P;

class GogoXCake {

public:
    string solve(vector <string> cake, vector <string> cutter) {
        int Y = (int)cutter.size() , X = (int)cutter[0].size();
        for (int i=0; i+X<=cake[0].size(); ++i) {
            for (int j=0; j+Y<=cake.size(); ++j) {
                bool canUse = true;
                for (int x=0;x<X;++x)
                    for (int y=0;y<Y;++y)
                        if (cutter[y][x] == '.' && cake[j+y][i+x] == 'X')
                            canUse = false;

                if (canUse) {
                    for (int x=0;x<X;++x)
                        for (int y=0;y<Y;++y)
                            if (cutter[y][x] == '.')
                                cake[j+y][i+x] = 'X';
                }
            }
        }
        for (int i=0;i<cake.size();++i)
            for (int j=0;j<cake[0].size();++j)
                if (cake[i][j] != 'X')
                    return "NO";
        return "YES";
    }


    // BEGIN CUT HERE
public:
    void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
private:
    template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
    void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
    void test_case_0() { string Arr0[] = {"X.X"
        ,"..."
        ,"..."
        ,"X.X"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {".X"
            ,".."
            ,"X."}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "YES"; verify_case(0, Arg2, solve(Arg0, Arg1)); }
    void test_case_1() { string Arr0[] = {"..XX"
        ,"...X"
        ,"X..."
        ,"XX.."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {".."
            ,".."}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "NO"; verify_case(1, Arg2, solve(Arg0, Arg1)); }
    void test_case_2() { string Arr0[] = {"...X..."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"..."}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "YES"; verify_case(2, Arg2, solve(Arg0, Arg1)); }
    void test_case_3() { string Arr0[] = {".X."
        ,"X.X"
        ,".X."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"."}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "YES"; verify_case(3, Arg2, solve(Arg0, Arg1)); }
    void test_case_4() { string Arr0[] = {"XXXXXXX"
        ,"X.....X"
        ,"X.....X"
        ,"X.....X"
        ,"XXXXXXX"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {".X."
            ,"XXX"
            ,".X."}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "NO"; verify_case(4, Arg2, solve(Arg0, Arg1)); }
    void test_case_5() { string Arr0[] = {".."
        ,"X."
        ,".X"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {".."
            ,".X"
            ,"X."}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "NO"; verify_case(5, Arg2, solve(Arg0, Arg1)); }
    void test_case_6() { string Arr0[] = {"X.X..X...XX.XXX...XX.........XXXX.......XX...XX.X.", "...........X.X...............................X....", "..X.......X..........XX.XXX....X....X....XX..X....", "..X....X........X...........X.............X......X", "..X.......X....X...............................X..", ".............X.....X.......XX....X.X..............", ".X..X.....XXX..X...........XX.X.....X..X......XX.X", "X.X.......X..................X....X..X...X.X.X.XX.", "X........X..X.X........X...X.X....................", ".X........X.......X..X...X............X.....X..X.X", "XX...X........XX............X.X...X.XXX.X.X..X..XX", "X..X.X.X..XX........X...........X....X..X........X", "..X............X..XX......................X.XX....", "X...X.....X..X.X........XX........X.........XX....", "..XXX.......X.X.......XX...X...................X.X", "X....X........X...............XX........X...X....X", "...XXX.X........X.....X....X.X.........X..........", "X...X...XXX.....X..XX..X..............X......XX..X", "...XX......X..................X..X...X.X..X.......", "X........X...............X.....XX..X.X....X.......", "......X.........X...X...X.X..X.........X......XX.X", "XXX.....XXX....X.X.........XX..X..X....X.......X..", "X......X...X.....X.......X......XXX....X...X.....X", "................X.....X........X..X........XX.XXX.", "...XX.........X......X..X...XX......X.....X.X....X", "........X......XX.X..XXX......X...................", "....X.....X...XX.......XX...........X......X......", "X.X.....X..X.....XX.......X..X..XX....X......XX..X", "......X....X......X.X......X.X.........X..X.......", ".X.....X...............X.........X....XX.....X....", "X....X..X....XX........XX...X....X........XX...X.X", "...XX...XX..X..X.XX.......X.....X........X.....X..", "....X...................X........X.X...X..X.X....X", "...........X.....X...............X..XX......X....X", "X....X.....XX..X..X....X....X...X..X.......X......", "...X...X...........X.X........X...............X...", "............X..X..X.................X.....X..X.X..", "..X.X.......X.......XX..X....X..X.......XX........", "X....X............X...XX.XXX....X....X..X........X", "....X.XX.........X...X..........X..X...X....X.....", "X.X....X.X......X.........X...............X.......", "..........XX...X......X...X..X.X..X...X.X..X.XX..X", "....X.....X......X...........X.....XX.......X...X.", ".....XX...X.....X......X......X..X................", "X..............XX..X........X.XX........X........X", ".X........X....XX...............XX.............X.X", "X.XX...X...XX..X....XX........X.XX.......X.X.X...X", "X....X.X......X...X.....XX...............X.X.....X", "..X....X............XXX...........................", "XX..X.X.XXX..XXX.XXXXX...XXX.XXX.X.X.XX.X.X.X.X..X"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"X.", ".X"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "YES"; verify_case(6, Arg2, solve(Arg0, Arg1)); }

    // END CUT HERE


};



// BEGIN CUT HERE

int main() {

    GogoXCake ___test;

    ___test.run_test(-1);

}

// END CUT HERE

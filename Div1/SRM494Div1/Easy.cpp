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

#define INF (1<<30)
#define EPS 1e-8
#define MOD 100000000

using namespace std;

#define MAX_N 55

bool is_black[MAX_N][MAX_N];

class Painting {

public:
    bool
    check(vector<string> &p,int i,int j,int s)
    {
        for (int y=i; y<i+s; ++y) {
            for (int x=j; x<j+s; ++x) {
                if (p[y][x] == 'W') {
                    return false;
                }
            }
        }
        return true;
    }

    bool
    is_fill(vector<string> &p,int s)
    {
        int N = (int)p.size();
        int M = (int)p[0].size();
        bool black[MAX_N][MAX_N];
        memset(black, false, sizeof(black));
        for (int i=0; i<=N-s; ++i) {
            for (int j=0; j<=M-s; ++j) {
                if (check(p, i, j, s)) {
                    for (int x=0; x<s; ++x) {
                        for (int y=0; y<s; ++y) {
                            black[x+i][y+j] = true;
                        }
                    }
                }
            }
        }

        for (int i=0; i<N; ++i) {
            for (int j=0; j<M; ++j) {
                if (is_black[i][j] ^ black[i][j]) {
                    return false;
                }
            }
        }

        return true;
    }

    int
    largestBrush(vector <string> picture)
    {
        int N = (int)picture.size();
        int M = (int)picture[0].size();
        memset(is_black, false, sizeof(is_black));
        for (int i=0; i<N; ++i) {
            for (int j=0; j<M; ++j) {
                if (picture[i][j] == 'B') {
                    is_black[i][j] = true;
                }
            }
        }

        int lb = 0 , ub = 52;
        while (ub - lb > 1) {
            int mid = (ub+lb)/2;
            if (is_fill(picture, mid)) {
                lb = mid;
            }
            else {
                ub = mid;
            }
        }
        return lb;
    }


    // BEGIN CUT HERE
public:
    void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
private:
    template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
    void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
    void test_case_0() { string Arr0[] = {"BBBB",
        "BBBB",
        "BBBB",
        "BBBB"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; verify_case(0, Arg1, largestBrush(Arg0)); }
    void test_case_1() { string Arr0[] = {"BBBB",
        "BWWB",
        "BWWB",
        "BBBB"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(1, Arg1, largestBrush(Arg0)); }
    void test_case_2() { string Arr0[] = {"WBBBBB",
        "BBBBBB",
        "BBBBBB",
        "BBBBBB"}
        ; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(2, Arg1, largestBrush(Arg0)); }
    void test_case_3() { string Arr0[] = {"BBBB",
        "BBBB",
        "WBBB",
        "BBBB",
        "BBBB",
        "BBBB"}
        ; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(3, Arg1, largestBrush(Arg0)); }
    void test_case_4() { string Arr0[] = {"WBBBBBWWWWWWWWW",
        "WBBBBBBWWWWWWWW",
        "WBBBBBBBBBBBWWW",
        "WBBBBBBBBBBBWWW",
        "BBBBBBBBBBBBBBB",
        "BBBBBBBBBBBBBBB",
        "BBBBBBBBBBBBBBB",
        "BBBBBBBBWWBBBBB",
        "BBBBBBBBWBBBBBB",
        "WBBBBBBBWBBBBBW",
        "BBBBBBBWWBBBBBW",
        "BBBBBBBWWBBBBBW",
        "BBBBBBWWWBBBBBW",
        "BBBBBWWWWWWWWWW",
        "BBBBBWWWWWWWWWW"}
        ; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; verify_case(4, Arg1, largestBrush(Arg0)); }

    // END CUT HERE


};



// BEGIN CUT HERE

int main() {

    Painting ___test;

    ___test.run_test(-1);

}

// END CUT HERE

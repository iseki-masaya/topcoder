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

const long long LINF = (5e18);
const int INF = (1<<30);
#define EPS 1e-6
const int MOD = 1000000007;

using namespace std;

class FindingSquareInTable {

public:

    bool isSquare(int n) {
        int i = sqrt(n);
        return i*i == n;
    }

    int make(vector<string> &t, int x, int y, int dx, int dy) {
        int Y = (int)t.size();
        int X = (int)t[0].size();

        int tmp = 0;
        int res = -1;
        while (0 <= x && x<X && 0 <= y && y<Y) {
            tmp *= 10;
            tmp += t[y][x] - '0';
            if (isSquare(tmp))
                res = tmp;

            if (dx == 0 && dy == 0)
                x = -1, y = -1;
            else
                x += dx , y += dy;
        }
        return res;
    }

    int findMaximalSquare(vector <string> table) {
        int Y = (int)table.size();
        int X = (int)table[0].size();

        const int cx[] = {1,1,-1,-1};
        const int cy[] = {1,-1,1,-1};
        int ans = -1;
        for (int y=0; y<Y; ++y) {
            for (int x=0; x<X; ++x) {
                for (int dx=0; dx<X; ++dx) {
                    for (int dy=0; dy<Y; ++dy) {
                        for (int i=0; i<4; ++i) {
                            ans = max(ans, make(table, x, y, cx[i]*dx, cy[i]*dy) );
                        }
                    }
                }
            }
        }
        return ans;
    }


    // BEGIN CUT HERE
public:
    void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
private:
    template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
    void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
    void test_case_0() { string Arr0[] = {"123",
        "456"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 64; verify_case(0, Arg1, findMaximalSquare(Arg0)); }
    void test_case_1() { string Arr0[] = {"00000",
        "00000",
        "00200",
        "00000",
        "00000"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(1, Arg1, findMaximalSquare(Arg0)); }
    void test_case_2() { string Arr0[] = {"3791178",
        "1283252",
        "4103617",
        "8233494",
        "8725572",
        "2937261"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 320356; verify_case(2, Arg1, findMaximalSquare(Arg0)); }
    void test_case_3() { string Arr0[] = {"135791357",
        "357913579",
        "579135791",
        "791357913",
        "913579135"}
        ; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 9; verify_case(3, Arg1, findMaximalSquare(Arg0)); }
    void test_case_4() { string Arr0[] = {"553333733",
        "775337775",
        "777537775",
        "777357333",
        "755553557",
        "355533335",
        "373773573",
        "337373777",
        "775557777"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = -1; verify_case(4, Arg1, findMaximalSquare(Arg0)); }
    void test_case_5() { string Arr0[] = {"257240281",
        "197510846",
        "014345401",
        "035562575",
        "974935632",
        "865865933",
        "684684987",
        "768934659",
        "287493867"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 95481; verify_case(5, Arg1, findMaximalSquare(Arg0)); }
    void test_case_6() { string Arr0[] = {"0"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(6, Arg1, findMaximalSquare(Arg0)); }

    // END CUT HERE


};



// BEGIN CUT HERE

int main() {

    FindingSquareInTable ___test;

    ___test.run_test(6);

}

// END CUT HERE

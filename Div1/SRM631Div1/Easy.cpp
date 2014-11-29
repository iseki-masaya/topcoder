#include <string>
#include <cmath>
#include <fstream>
#include <iostream>
#include <sstream>
#include <list>
#include <algorithm>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <numeric>
#include <bitset>
#include <deque>
//#include <random>
#include <string.h>
#include <stdlib.h>
#include <vector>
#include <unordered_map>
#include <thread>

const long long LINF = (1e18);
const int INF = (1<<28);
const int sINF = (1<<23);
const int MOD = 1000000007;
const double EPS = 1e-6;

using namespace std;

class TaroJiroGrid {

public:

    bool check(vector<string> &grid) {
        int N = (int)grid.size();
        int h = N / 2;
        for (int i=0; i<N; ++i) {
            int c = 1;
            for (int j=1; j<N; ++j) {
                if (grid[j][i] == grid[j-1][i])
                    ++c;
                else
                    c = 1;

                if (c > h)
                    return false;
            }
        }
        return true;
    }

    int getNumber(vector <string> &grid) {
        if (check(grid))
            return 0;

        int N = (int)grid.size();
        string W(N, 'W');
        string B(N, 'B');
        for (int i=0; i<N; ++i) {
            string origin = grid[i];
            grid[i] = W;
            if (check(grid))
                return 1;
            grid[i] = B;
            if (check(grid))
                return 1;
            grid[i] = origin;
        }
        return 2;
    }

    // BEGIN CUT HERE
public:
    void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
private:
    template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
    void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
    void test_case_0() { string Arr0[] = {"WB",
        "BB"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(0, Arg1, getNumber(Arg0)); }
    void test_case_1() { string Arr0[] = {"WB",
        "WW"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(1, Arg1, getNumber(Arg0)); }
    void test_case_2() { string Arr0[] = {"WB",
        "WB"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(2, Arg1, getNumber(Arg0)); }
    void test_case_3() { string Arr0[] = {"WBBW",
        "WBWB",
        "WWBB",
        "BWWW"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(3, Arg1, getNumber(Arg0)); }
    void test_case_4() { string Arr0[] = {"WBBWBB",
        "BBWBBW",
        "WWBWBW",
        "BWWBBB",
        "WBWBBW",
        "WWWBWB"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(4, Arg1, getNumber(Arg0)); }

    // END CUT HERE


};



// BEGIN CUT HERE

int main() {

    TaroJiroGrid ___test;

    ___test.run_test(-1);

}

// END CUT HERE

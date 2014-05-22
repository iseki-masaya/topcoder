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

class CellRemoval {

public:
    bool deleted(vector<int> &parent, int p, int d) {
        while (p != -1) {
            if (p == d) {
                return true;
            }
            p = parent[p];
        }
        return false;
    }

    int cellsLeft(vector <int> parent, int deletedCell) {
        int N = (int)parent.size();
        vector<bool> isCell(N, true);
        for (int i=0; i<N; ++i) {
            int p = parent[i];
            if (p != -1)
                isCell[p] = false;
        }

        for (int i=0; i<N; ++i) {
            if (isCell[i] && deleted(parent, i, deletedCell)) {
                isCell[i] = false;
            }
        }

        int ans = 0;
        for (int i=0; i<N; ++i) {
            if (isCell[i]) {
                ++ans;
            }
        }

        return ans;
    }


    // BEGIN CUT HERE
public:
    void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
private:
    template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
    void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
    void test_case_0() { int Arr0[] = {-1,0,0,1,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; int Arg2 = 2; verify_case(0, Arg2, cellsLeft(Arg0, Arg1)); }
    void test_case_1() { int Arr0[] = {-1,0,0,1,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = 1; verify_case(1, Arg2, cellsLeft(Arg0, Arg1)); }
    void test_case_2() { int Arr0[] = {-1,0,0,1,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; int Arg2 = 0; verify_case(2, Arg2, cellsLeft(Arg0, Arg1)); }
    void test_case_3() { int Arr0[] = {-1,0,0,2,2,4,4,6,6}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; int Arg2 = 2; verify_case(3, Arg2, cellsLeft(Arg0, Arg1)); }
    void test_case_4() { int Arr0[] = {26,2,32,36,40,19,43,24,30,13,21,14,24,21,19,4,30,10,44,12,7,32,17,43,
        35,18,7,36,10,16,5,38,35,4,13,-1,16,26,1,12,2,5,18,40,1,17,38,44,14}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 24; int Arg2 = 14; verify_case(4, Arg2, cellsLeft(Arg0, Arg1)); }

    // END CUT HERE


};



// BEGIN CUT HERE

int main() {

    CellRemoval ___test;

    ___test.run_test(-1);

}

// END CUT HERE

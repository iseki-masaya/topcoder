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
const int INF = (1<<29);
#define EPS 1e-6
const int MOD = 1000000007;

using namespace std;

class AddElectricalWires {

public:
    bool used[55];
    bool conn[55][55];
    int N;
    int curcnt;

    void dfs(int v) {
        if (used[v]) return;
        used[v] = true;
        ++curcnt;
        for (int i=0; i<N; ++i)
            if (conn[v][i])
                dfs(i);
    }

    int maxNewWires(vector <string> wires, vector <int> gridConnections) {
        this->N = (int)wires.size();
        int curr = 0;
        memset(conn, false, sizeof(conn));
        for (int i=0; i<N; ++i) {
            for (int j=0; j<N; ++j) {
                if (wires[i][j] == '1') {
                    conn[i][j] = true;
                    ++curr;
                }
            }
        }
        curr/=2;

        memset(used, false, sizeof(used));
        int ans = 0, left = N, mx = 0;
        for (int i=0; i<gridConnections.size(); ++i) {
            curcnt = 0;
            dfs(gridConnections[i]);
            ans += curcnt*(curcnt-1)/2;
            left -= curcnt;
            mx = max(mx, curcnt);
        }
        ans += left*(left-1)/2+left*mx;
        return ans-curr;
    }


    // BEGIN CUT HERE
public:
    void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
private:
    template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
    void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
    void test_case_0() { string Arr0[] = {"000","000","000"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 3; verify_case(0, Arg2, maxNewWires(Arg0, Arg1)); }
    void test_case_1() { string Arr0[] = {"000","000","000"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0,1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1; verify_case(1, Arg2, maxNewWires(Arg0, Arg1)); }
    void test_case_2() { string Arr0[] = {"01","10"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 0; verify_case(2, Arg2, maxNewWires(Arg0, Arg1)); }
    void test_case_3() { string Arr0[] = {"00000","00000","00000","00000","00000"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0,1,2,3,4}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 0; verify_case(3, Arg2, maxNewWires(Arg0, Arg1)); }
    void test_case_4() { string Arr0[] = {"01000","10100","01010","00100","00000"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2,4}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 3; verify_case(4, Arg2, maxNewWires(Arg0, Arg1)); }

    // END CUT HERE


};



// BEGIN CUT HERE

int main() {

    AddElectricalWires ___test;

    ___test.run_test(-1);

}

// END CUT HERE

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

int dx[] = {1,-1,0,0};
int dy[] = {0,0,-1,1};
double prb[4];

class CrazyBot {

public:
    double e,w,s,n;

    double dfs(int n, int x, int y, vector<vector<int> > &m, double p) {
        if (n == 0)
            return p;
        double res = 0.0;
        for (int i=0; i<4; ++i) {
            int cx = x+dx[i];
            int cy = y+dy[i];
            if (m[cy][cx] == 0) {
                m[cy][cx] = 1;
                res += dfs(n-1, cx, cy, m, p*prb[i]);
                m[cy][cx] = 0;
            }
        }
        return res;
    }

    double getProbability(int n, int east, int west, int south, int north) {
        prb[0] = east  / 100.0;
        prb[1] = west  / 100.0;
        prb[2] = south / 100.0;
        prb[3] = north / 100.0;
        vector<vector<int> > m(30,vector<int>(30,0));
        m[14][14] = 1;
        return dfs(n, 14, 14, m, 1.0);
    }


    // BEGIN CUT HERE
public:
    void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
private:
    template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
    void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
    void test_case_0() { int Arg0 = 1; int Arg1 = 25; int Arg2 = 25; int Arg3 = 25; int Arg4 = 25; double Arg5 = 1.0; verify_case(0, Arg5, getProbability(Arg0, Arg1, Arg2, Arg3, Arg4)); }
    void test_case_1() { int Arg0 = 2; int Arg1 = 25; int Arg2 = 25; int Arg3 = 25; int Arg4 = 25; double Arg5 = 0.75; verify_case(1, Arg5, getProbability(Arg0, Arg1, Arg2, Arg3, Arg4)); }
    void test_case_2() { int Arg0 = 7; int Arg1 = 50; int Arg2 = 0; int Arg3 = 0; int Arg4 = 50; double Arg5 = 1.0; verify_case(2, Arg5, getProbability(Arg0, Arg1, Arg2, Arg3, Arg4)); }
    void test_case_3() { int Arg0 = 14; int Arg1 = 50; int Arg2 = 50; int Arg3 = 0; int Arg4 = 0; double Arg5 = 1.220703125E-4; verify_case(3, Arg5, getProbability(Arg0, Arg1, Arg2, Arg3, Arg4)); }
    void test_case_4() { int Arg0 = 14; int Arg1 = 25; int Arg2 = 25; int Arg3 = 25; int Arg4 = 25; double Arg5 = 0.008845493197441101; verify_case(4, Arg5, getProbability(Arg0, Arg1, Arg2, Arg3, Arg4)); }

    // END CUT HERE


};



// BEGIN CUT HERE

int main() {

    CrazyBot ___test;

    ___test.run_test(-1);

}

// END CUT HERE

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

const long long LINF = (1e11);
const int INF = (1<<28);
#define EPS 1e-6
const int MOD = 1000000007;

using namespace std;

class SRMCodingPhase {

public:

    int calc(vector<int> point,vector<int> skills,int luck,int s) {
        int res = 0;

        int time = 75;
        for (int i=2; i>=0; --i) {
            if ( (s>>i)&1 && (skills[i] - luck) <= time ) {
                int t = skills[i] - luck > 0 ? skills[i] - luck : 1;
                res += point[i] - (1<<(i+1)) * t;
                luck = max(0,luck - skills[i] + 1);
                time -= t;
            }
        }

        return res;
    }

    int countScore(vector <int> points, vector <int> skills, int luck) {
        int lim = (1<<3);

        int ans = 0;
        for (int s=1; s<lim; ++s) {
            ans = max(ans, calc(points,skills,luck,s));
        }

        return ans;
    }


    // BEGIN CUT HERE
public:
    void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
private:
    template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
    void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
    void test_case_0() { int Arr0[] = {250, 500, 1000}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {10, 25, 40}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 0; int Arg3 = 1310; verify_case(0, Arg3, countScore(Arg0, Arg1, Arg2)); }
    void test_case_1() { int Arr0[] = {300, 600, 900}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {30, 65, 90}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 25; int Arg3 = 680; verify_case(1, Arg3, countScore(Arg0, Arg1, Arg2)); }
    void test_case_2() { int Arr0[] = {250, 550, 950}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {10, 25, 40}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 75; int Arg3 = 1736; verify_case(2, Arg3, countScore(Arg0, Arg1, Arg2)); }
    void test_case_3() { int Arr0[] = {256, 512, 1024}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {35, 30, 25}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 0; int Arg3 = 1216; verify_case(3, Arg3, countScore(Arg0, Arg1, Arg2)); }
    void test_case_4() { int Arr0[] = {300, 600, 1100}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {80, 90, 100}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 4; int Arg3 = 0; verify_case(4, Arg3, countScore(Arg0, Arg1, Arg2)); }

    // END CUT HERE


};



// BEGIN CUT HERE

int main() {

    SRMCodingPhase ___test;

    ___test.run_test(-1);

}

// END CUT HERE

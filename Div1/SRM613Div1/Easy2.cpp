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

const long long LINF = (5e18);
const int INF = (1<<30);
const int sINF = (1<<23);
const int MOD = 1000000007;
const double EPS = 1e-6;

using namespace std;

class TaroFriends {

public:

    int getNumber(vector <int> coordinates, int X) {
        if (coordinates.size() == 1)
            return 0;
        sort(coordinates.begin(), coordinates.end());
        int ans = coordinates.back() - coordinates.front();
        for (int l=0; l+1<coordinates.size(); ++l) {
            int ll = coordinates.front() + X;
            int lr = coordinates[l] + X;
            int rl = coordinates[l+1] - X;
            int rr = coordinates.back() - X;
            int left = min(ll, rl);
            int right = max(lr, rr);
            ans = min(ans, right - left);
        }
        return ans;
    }

    // BEGIN CUT HERE
public:
    void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
private:
    template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
    void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
    void test_case_0() { int Arr0[] = {-3, 0, 1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; int Arg2 = 3; verify_case(0, Arg2, getNumber(Arg0, Arg1)); }
    void test_case_1() { int Arr0[] = {4, 7, -7}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; int Arg2 = 4; verify_case(1, Arg2, getNumber(Arg0, Arg1)); }
    void test_case_2() { int Arr0[] = {-100000000, 100000000}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 100000000; int Arg2 = 0; verify_case(2, Arg2, getNumber(Arg0, Arg1)); }
    void test_case_3() { int Arr0[] = {3, 7, 4, 6, -10, 7, 10, 9, -5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 7; int Arg2 = 7; verify_case(3, Arg2, getNumber(Arg0, Arg1)); }
    void test_case_4() { int Arr0[] = {-4, 0, 4, 0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; int Arg2 = 4; verify_case(4, Arg2, getNumber(Arg0, Arg1)); }
    void test_case_5() { int Arr0[] = {7}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; int Arg2 = 0; verify_case(5, Arg2, getNumber(Arg0, Arg1)); }
    void test_case_6() { int Arr0[] = {527, -168, 795, 113, 319, 24, 613, 661, -829, 763, 737, 541, -717, 981, -12, 512, 898, -87, 73, -968, -553, 880, 228, -586, -265, -211, -3, -252, -941, 491, -967, -766, -616, 253, -629, 293, 428, 744, -778, -203, -321, 222}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 824; int Arg2 = 1416; verify_case(6, Arg2, getNumber(Arg0, Arg1)); }


    // END CUT HERE


};



// BEGIN CUT HERE

int main() {

    TaroFriends ___test;

    ___test.run_test(-1);

}

// END CUT HERE

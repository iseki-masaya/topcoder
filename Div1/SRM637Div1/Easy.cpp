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

class GreaterGame {

public:

    vector<int> make(vector <int> &hand, vector <int> &sothe) {
        int N = (int)hand.size();
        vector<int> res;
        for (int i=1; i<=2*N; ++i) {
            if (find(hand.begin(), hand.end(), i) == hand.end() &&
                    find(sothe.begin(), sothe.end(), i) == sothe.end()) {
                res.push_back(i);
            }
        }
        return res;
    }

    double calc(vector <int> hand, vector <int> sothe) {
        int N = (int)hand.size();
        sort(hand.begin(), hand.end());
        sort(sothe.rbegin(), sothe.rend());
        int win = 0, lose = 0;
        vector<bool> used(N, false);

        for (int i=0; i<N; ++i) {
            if (sothe[i] == -1)
                break;
            bool w = false;
            for (int j=0; j<N; ++j) {
                if (used[j])
                    continue;

                if (hand[j] > sothe[i]) {
                    w = true;
                    used[j] = true;
                    break;
                }
            }
            if (!w)
                ++lose;
            else
                ++win;
        }

        vector<int> th;
        for (int i=0; i<N; ++i) {
            if (used[i] || lose-- > 0)
                continue;
            th.push_back(hand[i]);
        }

        double dwin = 0.0;
        vector<int> ts(make(hand, sothe));
        int n = (int)th.size();
        int m = (int)ts.size();
        for (int i=0; i<n; ++i)
            for (int j=0; j<m; ++j)
                if (th[i] > ts[j])
                    dwin += 1.0 / m;

        return win + dwin;
    }


    // BEGIN CUT HERE
public:
    void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
private:
    template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
    void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
    void test_case_0() { int Arr0[] = {4,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {-1,-1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 1.5; verify_case(0, Arg2, calc(Arg0, Arg1)); }
    void test_case_1() { int Arr0[] = {4,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 2.0; verify_case(1, Arg2, calc(Arg0, Arg1)); }
    void test_case_2() { int Arr0[] = {2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {-1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 1.0; verify_case(2, Arg2, calc(Arg0, Arg1)); }
    void test_case_3() { int Arr0[] = {1,3,5,7}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {8,-1,4,-1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 2.5; verify_case(3, Arg2, calc(Arg0, Arg1)); }
    void test_case_4() { int Arr0[] = {6,12,17,14,20,8,16,7,2,15}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {-1,-1,4,-1,11,3,13,-1,-1,18}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 8.0; verify_case(4, Arg2, calc(Arg0, Arg1)); }

    // END CUT HERE


};



// BEGIN CUT HERE

int main() {

    GreaterGame ___test;

    ___test.run_test(-1);

}

// END CUT HERE
